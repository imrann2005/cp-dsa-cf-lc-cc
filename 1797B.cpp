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

void solve(vector<vi>& a, int n, int k)
{
    int mismatch = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int ri = n - 1 - i;
            int rj = n - 1 - j;
            if (i * n + j <= ri * n + rj && a[i][j] != a[ri][rj])
            {
                mismatch++;
            }
        }
    }

    if (mismatch > k)
    {
        no;
    }
    else
    {

        if ((k - mismatch) % 2 == 0 || n % 2 == 1)
        {
            yes;
        }
        else
        {
            no;
        }
    }
}


int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vi> a(n,vi(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin>>a[i][j];
            }
            
        }
        
        solve(a, n, k);
    }

    return 0;
}