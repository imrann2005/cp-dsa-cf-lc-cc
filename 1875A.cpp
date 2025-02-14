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

void solve(vi &arr, int a, int b, int n)
{
    // Write your solution here
    sort(all(arr));
    ll x = 0;
    ll t = 0;
    ll c = b;
    while (x < n)
    {
        int xtra = c - 1;
        t += xtra + 1;
        c = 1;
        c = min(c + arr[x],(ll) a);
        x++;
        c--;
    }
    ll xtra = c - 1;
    t += xtra + 1;
    cout << t << endl;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        vi arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        solve(arr, a, b, n);
    }

    return 0;
}