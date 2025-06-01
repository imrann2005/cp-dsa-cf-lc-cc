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

void solve(ll n) {
    ll sum1 = n;
    sum1 = (sum1 * (n + 1)) % MOD;
    sum1 = (sum1 * (2 * n + 1)) % MOD;
    sum1 = (sum1 * 166666668) % MOD; // (1/6) mod 1e9+7

    n--;
    ll sum2 = n;
    sum2 = (sum2 * (n + 1)) % MOD;
    sum2 = (sum2 * (2 * n + 1)) % MOD;
    sum2 = (sum2 * 166666668) % MOD;

    ll sum3 = n;
    sum3 = (sum3 * (n + 1)) % MOD;
    sum3 = (sum3 * 500000004) % MOD; // (1/2) mod 1e9+7

    ll ans = (sum1 + sum2 + sum3) % MOD;
    ans = (ans * 2022) % MOD;
    
    cout << ans << endl;
}


int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin>>n;

        solve(n);
    }

    return 0;
}