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

void solveH(vll &a, ll n, ll k)
{
    vll f(31, 0);
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j <= 30)
        {
            /* code */
            if ((1 << j) & (a[i]))
            {
                f[j]++;
            }
            j++;
        }
    }
    ll ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        /* code */
        ll need = n - f[i];
        if(need == 0){
           ans = ans + pow(2, i); 
        }
        else if (k >= need)
        {
            k -= need;
            ans = ans + pow(2, i);
        }
    }
    cout << ans << endl;
}

void solve(vll &a, int n)
{
    // Write your solution here
    ll s = 0;
    vll p(n);
    vll suf(n);
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        p[i] = s;
    }
    s = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        s += a[i];
        suf[i] = s;
    }
    int i = 0;
    int j = n - 1;
    int mx = 0;
    while (i < j)
    {
        if (p[i] < suf[j])
        {
            i++;
        }
        else if (p[i] == suf[j])
        {
            int cnt = (i - 0 + 1) + (n - 1 - j + 1);
            mx = max(mx, cnt);
            i++;
            j--;
        }
        else
        {
            j--;
        }
    }
    cout << mx << endl;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solveH(a, n, k);
    }

    return 0;
}