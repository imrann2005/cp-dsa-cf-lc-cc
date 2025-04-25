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

bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.second < p2.second;
}

void solve(vector<pair<int, int>> &a, int n, vi &x, int q)
{
    // Write your solution here
    sort(all(a));
    int mn = INT_MAX;
    for (int j = 0; j < q; j++)
    {

        if (x[j] < mn)
        {
            mn = x[j];
            for (int i = n - 1; i >= 0; i--)
            {
                if (a[i].first < (1 << x[j]))
                {
                    break;
                }
                if (a[i].first % (1 << x[j]) == 0)
                {
                    a[i].first += (1 << (x[j] - 1));
                }
            }
        }
    }

    sort(all(a), comp);
    for (int i = 0; i < n; i++)
    {
        cout << a[i].first << " ";
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
        int n, q;
        cin >> n >> q;
        vector<pair<int, int>> a(n);
        vi x(q);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < q; i++)
        {
            cin >> x[i];
        }
        solve(a, n, x, q);
    }

    return 0;
}