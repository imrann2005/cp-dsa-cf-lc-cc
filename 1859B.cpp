#include <bits/stdc++.h>
using namespace std;

#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve(vvi &l, int n)
{
    // Write your solution here
    int mn1 = INT_MAX;
    int mn2 = INT_MAX;
    int idx = -1;
    int idx1 = -1;
    for (int i = 0; i < n; i++)
    {
        sort(l[i].begin(), l[i].end());
        if (mn1 > l[i][0])
        {
            mn1 = l[i][0];
            idx = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i == idx)
            continue;
        if (mn2 > l[i][1])
        {
            mn2 = l[i][1];
            idx1 = i;
        }
    }

    ll cnt = 0;
    if (l[idx][1] > mn2)
    {
        mn2 = l[idx][1];
    }
    cnt += mn1;
    if (idx1 != -1 && idx != idx1)
        cnt += mn2;
    for (int i = 0; i < n; i++)
    {
        if (i == idx)
            continue;
        if (i == idx1)
            continue;

        else
            cnt += l[i][1];
    }

    cout << cnt << endl;
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
        vvi l;
        for (int i = 0; i < n; i++)
        {
            int mi;
            cin >> mi;
            vi a(mi);
            for (int j = 0; j < mi; j++)
            {
                cin >> a[j];
            }
            l.pb(a);
        }

        solve(l, n);
    }

    return 0;
}
