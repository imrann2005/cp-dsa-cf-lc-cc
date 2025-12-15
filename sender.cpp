#include <iostream>
#include <winsock2.h>

using namespace std;


#pragma comment(lib, "ws2_32.lib")

string word2 = "1001";
string divi = "1011";

void sender(){
    string word = word2;
    word += "000";

    int n = word.length();
    
    int j = 3;
    int i=0;
    while (i<n && j<n)
    {
       
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
    
    //cout<<word<<endl;
    string rem = word.substr(4,3);
    word2+=rem;
    //receive(word2,divi);
}

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    sender();
    const char *message = word2.c_str();

    // Initialize Winsock
    WSAStartup(MAKEWORD(2, 2), &wsa);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    // Connect
    connect(sock, (struct sockaddr *)&server, sizeof(server));

    // Send message
    send(sock, message, strlen(message), 0);
    std::cout << "Sender: Message sent!\n";

    closesocket(sock);
    WSACleanup();
    return 0;
}
