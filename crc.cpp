#include<iostream>

using namespace std;

void receive(string& word,string &div){
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
                int op2 = div[idx] - '0'  ;
                
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
        cout<<"Received without error\n";
    }
    else cout<<"Received error\n";
}

void sender(string& word2,string& div){
    string word = word2;
    word += "000";

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
                int op2 = div[idx] - '0'  ;
                
                int ans = op1^op2;
                word[x] = ans + '0';
                idx++;
            }
            
        }
    }
    
    //cout<<word<<endl;
    string rem = word.substr(4,3);
    word2+=rem;
    receive(word2,div);
}



int main(){
    string word = "1001";
    string div = "1011";
    //word += "000";
    sender(word,div);
    return 0;
}