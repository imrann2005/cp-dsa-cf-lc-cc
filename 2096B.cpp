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

void solve(vll&l,vll&r,ll n,ll k) {
    // Write your solution here
    ll s = 0;
    vll mn(n);
    for (ll i = 0; i < n; i++)
    {
        s += max(l[i],r[i]);
        mn[i] = min(l[i],r[i]);
    }

    sort(all(mn),greater<ll>());

    for (int i = 0; i < k-1; i++)
    {
        s += mn[i];
    }
    s++;
    cout<<s<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll n,k;
        cin >> n >> k;
        vll l(n);
        vll r(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> l[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> r[i];
        }
        
        
        solve(l,r,n,k);
    }

    return 0;
}