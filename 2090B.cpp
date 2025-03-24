#include <bits/stdc++.h>
using namespace std;

#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<char>>
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
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (a[i][j] == '1')
            {
                bool f1 = 1, f2 = 1;
                for (int k = 0; k < i; k++)
                {
                    if (a[k][j] == '0')
                        f1 = 0;
                }
                for (int k = 0; k < j; k++)
                {
                    if (a[i][k] == '0')
                        f2 = 0;
                }

                if (!f1 && !f2)
                {
                    no;
                    return;
                }
            }
        }
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
        int n;
        int m;
        cin >> n >> m;
        vvi a(n, vector<char>(m, 0));
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