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

void solve(string &s) {
    // Write your solution here
    int len = s.length();
    string s2;
    s2 = s.substr(0,len-2);
    s2 += 'i';
    cout<<s2<<endl;
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