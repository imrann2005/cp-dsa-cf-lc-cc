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

void solve(vi &a, int n)
{
    // Write your solution here
    sort(all(a));
    vi b;
    vi c;
    b.pb(a[0]);
    int i = 1;
    while (i < n)
    {
        if (a[i] == a[i - 1])
        {
            b.pb(a[i]);
            i++;
        }
        else
            break;
    }
    while (i < n)
    {
        c.pb(a[i]);
        i++;
    }
    if (c.size() == 0)
    {
        cout << -1 << endl;
        return;
    }
    cout << b.size() << " ";
    cout << c.size() << endl;
    for (size_t i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    for (size_t i = 0; i < c.size(); i++)
    {
        cout << c[i] << " ";
    }
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solve(a, n);
    }

    return 0;
}