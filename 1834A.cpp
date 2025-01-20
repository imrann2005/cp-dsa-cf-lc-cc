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

    int c1 = 0, cm1 = 0;
    int ops = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            c1++;
        else
            cm1++;
    }

    if ((cm1 <= c1) && (cm1 % 2 == 0))
    {
        cout << 0 << endl;
        return;
    }

    while (cm1 > c1)
    {
        c1++;
        cm1--;
        ops++;
    }
    if (cm1 & 1)
    {
        /* odd */
        cm1--;
        c1++;
        ops++;
    }
    cout << ops << endl;
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
        vi a(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solve(a, n);
    }

    return 0;
}