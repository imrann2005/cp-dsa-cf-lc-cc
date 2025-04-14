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
    int i = 0, j = 0;
    vi ans;
    while (j < n && i < n)
    {
        if (a[i] == a[j])
        {
            j++;
        }
        else
        {
            j--;
            if (j - i + 1 == 1)
            {
                cout << -1 << endl;
                return;
            }
            ans.pb(j + 1);
            while (i < j)
            {
                ans.pb(i + 1);
                i++;
            }
            j++;
            i++;
        }
    }
    j--;
    if (j - i + 1 == 1)
    {
        cout << -1 << endl;
        return;
    }
    ans.pb(j + 1);
    while (i < j)
    {
        ans.pb(i + 1);
        i++;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
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
            /* code */
            cin >> a[i];
        }

        solve(a, n);
    }

    return 0;
}