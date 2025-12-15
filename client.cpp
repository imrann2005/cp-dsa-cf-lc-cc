#include <iostream>
#include <winsock2.h>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

#pragma comment(lib, "ws2_32.lib")

void goBackNSender(SOCKET sock, int windowSize, int totalFrames) {
    int base = 0, nextSeqNum = 0;
    char buffer[1024];

    //cout << "\n[Go-Back-N Sender Started]\n";

    while (base < totalFrames) {
        while (nextSeqNum < base + windowSize && nextSeqNum < totalFrames) {
            string frame = "F" + to_string(nextSeqNum);
            send(sock, frame.c_str(), frame.size(), 0);
            cout << "Sender: " << frame << endl;
            nextSeqNum++;
        }

        memset(buffer, 0, sizeof(buffer));
        recv(sock, buffer, sizeof(buffer), 0);
        string ack(buffer);
        cout << "Sender: Got " << ack << endl;

        int ackNo = stoi(ack.substr(3));
        base = ackNo;
    }
}

void selectiveRepeatSender(SOCKET sock, int windowSize, int totalFrames) {
    vector<bool> acked(totalFrames, false);
    int base = 0;
    char buffer[1024];

    cout << "\n[Selective Repeat Sender Started]\n";

    while (base < totalFrames) {
        for (int i = base; i < base + windowSize && i < totalFrames; i++) {
            if (!acked[i]) {
                string frame = "F" + to_string(i);
                send(sock, frame.c_str(), frame.size(), 0);
                cout << "Sender: " << frame << endl;
            }
        }

        memset(buffer, 0, sizeof(buffer));
        recv(sock, buffer, sizeof(buffer), 0);
        string ack(buffer);
        cout << "Sender: Got " << ack << endl;

        int ackNo = stoi(ack.substr(3));
        acked[ackNo] = true;

        while (base < totalFrames && acked[base]) {
            base++;
        }
    }
}

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;

    WSAStartup(MAKEWORD(2, 2), &wsa);
    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    connect(sock, (struct sockaddr *)&server, sizeof(server));
    cout << "Sender: Connected!\n";

    int windowSize = 4, totalFrames = 10;

    
    goBackNSender(sock, windowSize, totalFrames);
    // selectiveRepeatSender(sock, windowSize, totalFrames);

    closesocket(sock);
    WSACleanup();
    return 0;
}
