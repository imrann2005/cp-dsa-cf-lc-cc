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

void solve(string &s, int n)
{
    // Write your solution here
    int i = n - 2;
    vi ans(n);
    int uc = 1;
    int dc = n;
    int sum = 0;
    int idx = n-1;
    while (i >= 0)
    {
        if (s[i] == '<')
        {
            sum += uc;
           ans[idx] = uc;
            uc++;
        }
        else
        {
            sum += dc;
            ans[idx] = dc;
            dc--;
        }
        idx--;
        i--;
    }
    int m = (n * (n + 1)) / 2;
    int x = m - sum;
    ans[0] = x;
    //reverse(all(ans));

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(s, n);
    }

    return 0;
}