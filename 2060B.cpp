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

void solve(vvi &a, int n, int m)
{
    // Write your solution here
    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        int rem = a[i][0] % n;
        for (int j = 1; j < m; j++)
        {
            if (rem != (a[i][j]%n))
            {
                cout << -1 << endl;
                return;
            }
        }
        mpp[rem] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << mpp[i] << " ";
    }
    cout << endl;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vvi a(n, vi(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        solve(a, n, m);
    }

    return 0;
}