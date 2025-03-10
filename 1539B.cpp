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
    ll n = s.length();
    map<char,ll>mpp;
    ll i = n-1;
    ll cnt = 0;
    while (i >= 0)
    {
        if(s[i] == '5'){
            if(mpp.find('0') != mpp.end()){
                /*0 presetr*/
                cout<<mpp['0']-i-1 + (n-mpp['0']-1)<<endl;
                return;
            }
            if(mpp.find(s[i]) == mpp.end()){
                mpp[s[i]] = i;
            }
        }
        else if(s[i] == '0'){
            if(mpp.find('0') != mpp.end()){
                /*0 present*/
                cout<<mpp['0']-i-1 + (n-mpp['0']-1)<<endl;
                return;
            }
            if(mpp.find(s[i]) == mpp.end()){
                mpp[s[i]] = i;
            }
        }
        else if(s[i] == '2'){
            if(mpp.find('5')!=mpp.end()){
                cout<<(mpp['5']-i-1)+(n-mpp['5']-1)<<endl;
                return;
            }
        }
        else if(s[i] == '7'){
            if (mpp.find('5') != mpp.end())
            {
                cout<<mpp['5']-i-1 + (n-mpp['5']-1)<<endl;
                return;
            }
            
        }
        i--;
    }
    
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