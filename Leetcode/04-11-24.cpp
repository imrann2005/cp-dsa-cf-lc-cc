#include <bits/stdc++.h>
using namespace std;

string compressedString(string word) {
        int n = word.length();
        char curr = word[0];
        int cnt=1;
        int i=1;
        string res;
        while(i<n){
            if(word[i]==curr){
                cnt++;
                if(cnt > 9){
                    res.push_back('9');
                    res.push_back(curr);
                    cnt = 1;
                }
            }
            else{
                res.push_back(cnt + '0');
                res.push_back(curr);
                curr = word[i];
                cnt = 1;
            }
            i++;
        }

        res.push_back(cnt + '0');
        res.push_back(curr);

        return res;
    }

    int main(){
        cout<<compressedString("aaaaaaaaaaaaaabb")<<endl;
        return 0;
    }