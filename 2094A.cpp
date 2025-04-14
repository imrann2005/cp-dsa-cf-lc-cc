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

void solve() {
    // Write your solution here
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        string s1,s2,s3;
        cin >> s1>>s2>>s3;
        string s4;
        s4.pb(s1[0]);
        s4.pb(s2[0]);
        s4.pb(s3[0]);
        cout<<s4<<endl;
        //solve();
    }

    return 0;
}