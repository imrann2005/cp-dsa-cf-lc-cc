#include <bits/stdc++.h>
using namespace std;

#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
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

void solve(ll n, ll k, ll x)
{
    // Write your solution here
    ll mx = (n * (n + 1)) / 2;
    ll mn = (k * (k + 1)) / 2;
    // if (mx == x || mn == x)
    // {
    //     yes;
    //     return;
    // }
    if (mx < x || mn > x)
    {
        no;
        return;
    }
    ll xtra = mx - x;
    ll nmk = n - k;
    ll mn_nmk = (nmk * (nmk + 1)) / 2;
    if (mn_nmk > xtra)
    {
        no;
        return;
    }
    yes;
   
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, x;
        cin >> n >> k >> x;
        solve(n, k, x);
    }

    return 0;
}