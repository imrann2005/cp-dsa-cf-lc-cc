#include <bits/stdc++.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
using namespace std;

#define PORT 9090
#define BUF 4096

uint64_t ntohll_u(uint64_t v){
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    return ((uint64_t)ntohl(v & 0xffffffff) << 32) | ntohl(v >> 32);
#else
    return v;
#endif
}

uint64_t htonll_u(uint64_t v){
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    return ((uint64_t)htonl(v & 0xffffffff) << 32) | htonl(v >> 32);
#else
    return v;
#endif
}

ssize_t recv_line(int fd, string &line){
    line.clear();
    char c;
    while (true){
        ssize_t r = recv(fd, &c, 1, 0);
        if (r <= 0) return r;
        line.push_back(c);
        if (c == '\n') break;
    }
    return (ssize_t)line.size();
}

ssize_t recv_full(int fd, void *buf, size_t len){
    size_t got = 0;
    while (got < len){
        ssize_t r = recv(fd, (char*)buf + got, len - got, 0);
        if (r <= 0) return r;
        got += r;
    }
    return (ssize_t)got;
}

void send_str(int fd, const string &s){
    send(fd, s.c_str(), s.size(), 0);
}

// ---------- Task Handlers ----------
void handle_calc(int cfd, const string &args){
    stringstream ss(args);
    string op; double a, b;
    if (!(ss >> op >> a >> b)){
        send_str(cfd, "ERR Bad format\n");
        return;
    }
    double res = 0;
    if (op == "ADD") res = a + b;
    else if (op == "SUB") res = a - b;
    else if (op == "MUL") res = a * b;
    else if (op == "DIV"){
        if (b == 0){ send_str(cfd, "ERR Divide by zero\n"); return; }
        res = a / b;
    }
    else { send_str(cfd, "ERR Unknown op\n"); return; }
    send_str(cfd, "OK " + to_string(res) + "\n");
}

void handle_text(int cfd, const string &args){
    send_str(cfd, "ECHO: " + args + "\n");
}

void handle_file(int cfd, const string &args){
    string fname; uint64_t size;
    stringstream ss(args);
    if (!(ss >> fname >> size)){
        send_str(cfd, "ERR Bad FILE cmd\n");
        return;
    }
    send_str(cfd, "OK\n");
    FILE *f = fopen(fname.c_str(), "wb");
    if (!f){ perror("fopen"); return; }
    char buf[BUF];
    uint64_t remain = size;
    while (remain > 0){
        ssize_t r = recv(cfd, buf, min<uint64_t>(BUF, remain), 0);
        if (r <= 0) break;
        fwrite(buf, 1, r, f);
        remain -= r;
    }
    fclose(f);
    cout << "[+] File received: " << fname << " (" << size << " bytes)\n";
    send_str(cfd, "DONE\n");
}

void handle_client(int cfd){
    string line;
    while (true){
        ssize_t n = recv_line(cfd, line);
        if (n <= 0) break;

        stringstream ss(line);
        string cmd; ss >> cmd;
        string args; getline(ss, args);
        if (!args.empty() && args[0] == ' ') args.erase(0, 1);
        
        if (cmd == "CALC") handle_calc(cfd, args);
        else if (cmd == "TEXT") handle_text(cfd, args);
        else if (cmd == "FILE") handle_file(cfd, args);
        else if (cmd == "QUIT"){ send_str(cfd, "BYE\n"); break; }
        else send_str(cfd, "ERR Unknown command\n");
    }
    close(cfd);
    exit(0);
}

int main(){
    int s = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1; setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(s, (sockaddr*)&addr, sizeof(addr)) < 0){ perror("bind"); exit(1); }
    if (listen(s, 5) < 0){ perror("listen"); exit(1); }

    cout << "[*] Multi-task Server listening on port " << PORT << endl;

    while (true){
        int c = accept(s, nullptr, nullptr);
        if (c < 0){ perror("accept"); continue; }
        if (!fork()){
            close(s);
            handle_client(c);
        }
        close(c);
    }
    return 0;
}
