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

bool check(vi &a, int n, int mid, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] + x * i > mid)
        {
            return false;
        }
    }
    return true;
}

void solve(vi &a, int n, int s, int x)
{
    // Write your solution here
    int low = a[0];
    int high = a[0]+n*x;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (check(a, n, mid,x))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << low << endl;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vi a(n, 0);
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s = max(s,a[i]+n*x);
        }

        /* Sorting the array! */

        sort(all(a),greater<int>());

        solve(a, n, s,x);
    }

    return 0;
}