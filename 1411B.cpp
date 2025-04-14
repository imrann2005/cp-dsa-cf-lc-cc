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

bool solve(ll n)
{
    ll s = n;
    while (s > 0)
    {
        ll r = s%10;
        s = s/10;
        if(r != 0 && n % r != 0){
            return false;
        }
    }
    return true;
    
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll nxt;
        nxt = n / 2520;
        for (ll i = n; i <= (2520 * (nxt + 1)); i++)
        {
            if (solve(i))
            {
                cout << i << endl;
                break;
            };
        }
    }

    return 0;
}