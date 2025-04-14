#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        int n1 = 1;
        int p=0;
        int c0 = 0;
        int c1 = 0;
        for (int i = 0; i < n; i++) {
            /* code */
            if(s[i]=='0')c0++;
            else c1++;
            if(c0 == c1){
                if(p==0){
                    p = 1;
                }
                else{
                    p = 1 + (p+p);
                }
            }
        }
        std::cout << p+n1 << std::endl;
    }
}
