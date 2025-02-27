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
/*Duplicate elements should not be removed*/
void solve(vi &a, int n)
{
    // Write your solution here
    unordered_map<int, int> mpp;
    for (auto &&i : a)
    {
        mpp[i]++;
    }
    int r = 0;
    int s = -1;
    int e = -1;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        r = max(i, r);
        while (r < n && mpp[a[r]] == 1)
        {
            /* code */
            r++;
        }
        if (r - i > mx)
        {
            mx = r - i;
            s = i;
            e = r-1;
        }
    }

    if (s == -1)
    {
        cout << 0 << endl;
        return;
    }
    cout << s + 1 << " " << e + 1 << endl;
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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solve(a, n);
    }

    return 0;
}