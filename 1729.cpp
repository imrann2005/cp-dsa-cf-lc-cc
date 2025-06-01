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

void solveD(vll &a, ll n)
{
    // Write your solution here
    ll cnt = 0;
    ll sum = 0;
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        /* code */
        //sum += a[l];
        if (a[l] + a[r] >= 0)
        {
            cnt++;
            sum = 0;
            l++;
            r--;
        }
        else
        {
            l++;
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
        ll n;
        cin >> n;
        vll a(n);
        vll b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin>>b[i];
        }
        vll d(n);
        for (int i = 0; i < n; i++)
        {
            d[i] = b[i]-a[i];
        }
        sort(all(d));
        solveD(d, n);
    }

    return 0;
}