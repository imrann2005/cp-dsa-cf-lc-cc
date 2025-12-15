#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib") // Link with ws2_32.lib

using namespace std;

string word2 = "1001";
string divi = "1011";

void receive(string word){
    int n = word.length();

    int j = 3;
    int i=0;

    while (i<n && j<n)
    {
        /* code */
        if(word[i]=='0'){
            i++;
            j++;
        }
        else{
            int idx = 0;
            for (int x = i; x <= j; x++)
            {
                int op1 = word[x] - '0';
                int op2 = divi[idx] - '0'  ;
                
                int ans = op1^op2;
                word[x] = ans + '0';
                idx++;
            }
            
        }
    }
    bool f = 0;
    for (int i = 0; i < n; i++)
    {
        if(word[i]!='0'){
            f = 1;
        }
    }
    if(f){
        cout<<"Received  error\n";
    }
    else cout<<"Received without error\n";
}

int main() {
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server, client;
    int c;
    char buffer[1024] = {0};

    
    WSAStartup(MAKEWORD(2, 2), &wsa);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Prepare sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    // Bind
    bind(server_socket, (struct sockaddr *)&server, sizeof(server));

    // Listen
    listen(server_socket, 3);
    std::cout << "Receiver: Waiting for connection...\n";

    c = sizeof(struct sockaddr_in);
    client_socket = accept(server_socket, (struct sockaddr *)&client, &c);

    // Receive
    recv(client_socket, buffer, sizeof(buffer), 0);
    //std::cout<<sizeof(buffer)<<endl;
    std::string word(buffer);
    std::cout << "Receiver: Got message -> " << word << std::endl;

    receive(word);

    closesocket(server_socket);
    WSACleanup();
    return 0;
}
