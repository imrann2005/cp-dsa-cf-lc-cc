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

bool double_is_int(double trouble)
{
    double absolute = abs(trouble);
    return absolute == floor(absolute);
}

void solve(ll a, ll b)
{
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }

    ll x = max(a, b);
    ll y = min(a, b);

    if (x % y != 0)
    {
        cout << -1 << endl;
        return;
    }

    ll ratio = x / y;


    if (ratio & (ratio - 1))
    {
        cout << -1 << endl;
        return;
    }

    int operations = 0;
    while (ratio > 1)
    {
        if (ratio % 8 == 0)
        {
            ratio /= 8;
        }
        else if (ratio % 4 == 0)
        {
            ratio /= 4;
        }
        else if (ratio % 2 == 0)
        {
            ratio /= 2;
        }
        operations++;
    }

    cout << operations << endl;
}


int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        solve(a, b);
    }

    return 0;
}