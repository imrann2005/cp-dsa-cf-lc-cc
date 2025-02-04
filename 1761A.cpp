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
        int n,a,b;
        cin>>n>>a>>b;
        if(n==a && n==b){
            yes;
        }
        else if(n-a-b >= 2){
            yes;
        }
        else no;
        //solve();
    }

    return 0;
}