#include <bits/stdc++.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/socket.h>
using namespace std;

#define PORT 9090
#define BUF 4096

void send_full(int fd, const void *buf, size_t len){
    size_t sent = 0;
    while (sent < len){
        ssize_t s = send(fd, (char*)buf + sent, len - sent, 0);
        if (s <= 0) return;
        sent += s;
    }
}

int main(int argc, char **argv){
    if (argc < 3){
        cerr << "Usage:\n";
        cerr << "  " << argv[0] << " server_ip CALC op x y\n";
        cerr << "  " << argv[0] << " server_ip TEXT \"message\"\n";
        cerr << "  " << argv[0] << " server_ip FILE filename\n";
        return 1;
    }

    string server = argv[1];
    string cmd = argv[2];
    int s = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server.c_str(), &addr.sin_addr);
    if (connect(s, (sockaddr*)&addr, sizeof(addr)) < 0){ perror("connect"); return 1; }

    char buf[BUF];

    if (cmd == "CALC" && argc == 6){
        string msg = "CALC " + string(argv[3]) + " " + argv[4] + " " + argv[5] + "\n";
        send_full(s, msg.c_str(), msg.size());
        int n = recv(s, buf, sizeof(buf) - 1, 0);
        buf[n] = 0;
        cout << buf;
    }
    else if (cmd == "TEXT" && argc >= 4){
        string msg = "TEXT " + string(argv[3]) + "\n";
        send_full(s, msg.c_str(), msg.size());
        int n = recv(s, buf, sizeof(buf) - 1, 0);
        buf[n] = 0;
        cout << buf;
    }
    else if (cmd == "FILE" && argc == 4){
        string fname = argv[3];
        struct stat st{};
        if (stat(fname.c_str(), &st) < 0){ perror("stat"); return 1; }
        uint64_t size = st.st_size;

        stringstream msg;
        msg << "FILE " << fname << " " << size << "\n";
        send_full(s, msg.str().c_str(), msg.str().size());

        int n = recv(s, buf, sizeof(buf) - 1, 0); // expect OK
        buf[n] = 0;

        FILE *f = fopen(fname.c_str(), "rb");
        if (!f){ perror("fopen"); return 1; }

        while (!feof(f)){
            size_t r = fread(buf, 1, sizeof(buf), f);
            if (r > 0) send_full(s, buf, r);
        }
        fclose(f);

        n = recv(s, buf, sizeof(buf) - 1, 0);
        buf[n] = 0;
        cout << buf;
    }
    else {
        cerr << "Invalid command or arguments.\n";
    }

    send_full(s, "QUIT\n", 5);
    close(s);
    return 0;
}
