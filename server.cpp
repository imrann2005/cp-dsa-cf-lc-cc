#include <iostream>
#include <winsock2.h>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

#pragma comment(lib, "ws2_32.lib")


void goBackNReceiver(SOCKET client_socket, int windowSize, int totalFrames) {
    int expectedFrame = 0;
    char buffer[1024] = {0};

    cout << "\nGo-Back-N Receiver Started\n";

    while (expectedFrame < totalFrames) {
        memset(buffer, 0, sizeof(buffer));
        recv(client_socket, buffer, sizeof(buffer), 0);
        string frame(buffer);

        cout << "Receiver: Got Frame -> " << frame << endl;

        int frameNo = stoi(frame.substr(1)); 
        if (frameNo == expectedFrame) {
            cout << "Receiver: Frame " << frameNo << " accepted \n";
            expectedFrame++;
        } else {
            cout << "Receiver: Wrong frame! Expected " << expectedFrame 
                 << " but got " << frameNo << "\n";
        }

      
        string ack = "ACK" + to_string(expectedFrame);
        send(client_socket, ack.c_str(), ack.size(), 0);
        cout << "Receiver: Sent " << ack << endl;
    }
}

void selectiveRepeatReceiver(SOCKET client_socket, int windowSize, int totalFrames) {
    vector<bool> received(totalFrames, false);
    int base = 0;
    char buffer[1024] = {0};

    cout << "\n[Selective Repeat Receiver Started]\n";

    while (base < totalFrames) {
        memset(buffer, 0, sizeof(buffer));
        recv(client_socket, buffer, sizeof(buffer), 0);
        string frame(buffer);

        cout << "Receiver: Got Frame -> " << frame << endl;
        int frameNo = stoi(frame.substr(1));

        if (frameNo >= base && frameNo < base + windowSize) {
            received[frameNo] = true;
            cout << "Receiver: Frame " << frameNo << " buffered ✅\n";
        }

      
        string ack = "ACK" + to_string(frameNo);
        send(client_socket, ack.c_str(), ack.size(), 0);
        cout << "Receiver: Sent " << ack << endl;

        while (base < totalFrames && received[base]) {
            cout << "Receiver: Frame " << base << " delivered to app ⬆\n";
            base++;
        }
    }
}


int main() {
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server, client;
    int c;

    WSAStartup(MAKEWORD(2, 2), &wsa);
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    bind(server_socket, (struct sockaddr *)&server, sizeof(server));
    listen(server_socket, 3);
    cout << "Receiver: Waiting for connection...\n";

    c = sizeof(struct sockaddr_in);
    client_socket = accept(server_socket, (struct sockaddr *)&client, &c);
    cout << "Receiver: Connected!\n";

    int windowSize = 4, totalFrames = 10;

  
    goBackNReceiver(client_socket, windowSize, totalFrames);
    // selectiveRepeatReceiver(client_socket, windowSize, totalFrames);

    closesocket(server_socket);
    WSACleanup();
    return 0;
}