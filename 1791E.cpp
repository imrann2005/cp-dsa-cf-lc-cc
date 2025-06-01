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

void solve(vll &a, int n)
{
    // Write your solution here
    int cnt = 0;
    ll s = 0;
    bool f = 0;
    ll mn = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            f = 1;
        }
        if (a[i] < 0)
            cnt++;
        mn = min(mn, abs(a[i]));
        s += abs(a[i]);
    }
    if (f)
    {
        cout << s << endl;
        return;
    }
    if (cnt & 1)
    {
        cout << s - 2 * mn << endl;
        return;
    }
    cout << s << endl;
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
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solve(a, n);
    }

    return 0;
}