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

void solve(vi &a, int n, int x)
{
    // Write your solution here
    sort(all(a));
    int j = n - 1;
    int cnt = 0;
    while (j >= 0)
    {
        if (a[j] >= x)
        {
            cnt++;
            j--;
        }
        else
        {

            int i = j;
            bool f = 0;
            while (i >= 0)
            {
                f = 1;
                int s = a[i] * (j - i + 1);
                if (s >= x)
                {
                    j = i;

                    cnt++;
                    break;
                }
                i--;
            }
            j--;
        }
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
        int n, x;
        cin >> n >> x;
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solve(a, n, x);
    }

    return 0;
}