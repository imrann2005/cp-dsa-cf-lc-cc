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

void solve(string&s,int n) {
    // Write your solution here
    map<char,int>mpp;
    for (int i = 0; i < n; i++)
    {
        if(mpp.find(s[i]) == mpp.end()){
            mpp[s[i]] = i;
        }
    }
    ll sum = 0;
    for (auto x : mpp)
    {
        /* code */
        sum += (n-x.second);
    }

    cout<<sum<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(s,n);
    }

    return 0;
}