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

void solveB()
{
    // Write your solution here
    ll n;
    cin >> n;
    ll ans;
    if (n & 1)
    {
        ll dot = 1;
        ll times = 0;
        for (int i = 1; i <= n; i += 2)
        {
            /* code */
            dot++;
            times++;
        }
        ans = 2 * dot * times;
    }
    else
    {
        ll dot = 1;
        ll times = 1;
        for (int i = 2; i <= n; i += 2)
        {
            /* code */
            dot++;
            times++;
        }
        ans = dot*times;
    }
    cout<<ans<<endl;
}

int main()
{
    fast_io;

    // int t;
    // cin >> t;
    // while (t--)
    // {
        solveB();
    // }

    return 0;
}