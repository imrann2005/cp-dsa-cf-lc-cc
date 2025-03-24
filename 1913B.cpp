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
    int i=0;
    int n = s.length();
    int c0 = 0;
    int c1=0;
    for (auto &ch : s)
    {
        if(ch == '0')c0++;
        else c1++;
    }
    while (i < n)
    {
        if(s[i]=='0'){
            if(c1 <= 0){
                cout<<n-i<<endl;
                return;
            }
            c1--;
        }
        else{
            if(c0 <= 0){
                cout<<n-i<<endl;
                return;
            }
            c0--;
        }
        i++;
    }
    cout<<n-i<<endl;
    
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