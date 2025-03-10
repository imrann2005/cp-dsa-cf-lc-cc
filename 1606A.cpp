#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve(string& s) {
    // Write your solution here
    int n = s.length();
    int i=1;
    int cnt = 0;
    while (i<n)
    {
        /* code */
        if(s[i] != s[i-1]){
            cnt++;
            i++;

            while (i<n && s[i]==s[i-1])
            {
                /* code */
                i++;
            }
            if(i<n){
                cnt--;
                i++;
            }
            else{
                s[i-1] = s[i-1]=='a' ? 'b' : 'a';
            }
        }
        else {
            i++;
        }
    }
    cout<<s<<endl;

}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
       
        string s;
        cin >> s;
        
        solve(s);
    }

    return 0;
}