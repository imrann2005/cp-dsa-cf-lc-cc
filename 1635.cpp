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

void solveC(vll &a, ll n)
{
    // Write your solution here
    ll last = a[n - 1];
    ll slast = a[n - 2];
    if (slast <= last)
    {
        if (slast < 0 && last < 0)
        {
            int i = n - 3;
            while (i >= 0)
            {
                /* code */
                if (a[i] > slast)
                {
                    cout << -1 << endl;
                    return;
                }
                slast = a[i];
                i--;
            }
            cout<<0<<endl;
        }
        else
        {
            int m = n - 2;
            cout << m << endl;
            for (int i = n - 3; i >= 0; i--)
            {
                cout << i + 1 << " " << n - 2 + 1 << " " << n - 1 + 1 << endl;
            }
        }
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solveC(a, n);
    }

    return 0;
}