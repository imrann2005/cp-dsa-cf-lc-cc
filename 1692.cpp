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

void solveE(vll &a, ll n, ll t)
{
    // Write your solution here
    vll pre(n);
    vll suff(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    suff[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        /* code */
        suff[i] = suff[i + 1] + a[i];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<pre[i]<<"\t";
    // }
    // cout<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<suff[i]<<"\t";
    // }
    // cout<<endl;
    int i = 0;
    int j = n - 1;
    int s = pre[n - 1];
    int rem = s - t;
    if (s == t)
    {
        cout << 0 << endl;
        return;
    }
    if (s < t)
    {
        cout << -1 << endl;
        return;
    }
    int sum = 0;
    while (i <= j)
    {
        /* code */
        sum = pre[i] + suff[j];
        if (sum >= rem)
        {
            break;
        }
        i++;
        j--;
    }
    if (sum > rem)
    {
        if (pre[i] < suff[j])
        {
            i--;
        }
        else
            j++;
    }
    while (i - 1 >= 0 && pre[i] == pre[i - 1])
    {
        /* code */
        i--;
    }
    while (j + 1 < n && suff[j] == suff[j + 1])
    {
        /* code */
        j++;
    }
    if (j < n && suff[j] == 0)
        j++;
    if (i >= 0 && pre[i] == 0)
        i--;
    int ans = (i + 1) + (n - j);
    // if(sum > rem){
    //     cout<<ans-1<<endl;
    //     return;
    // }
    cout << ans << endl;
}

void solveG()
{
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i = 0;
    int j = 1;
    ll cnt = 0;
    while (j < n)
    {
        /* code */
        if (a[j] * 2 > a[j - 1])
        {
        }
        else
        {
            i=j;
        }
        if ((j - i + 1) == (k + 1))
        {
            i++;
            cnt++;
        }
        j++;
    }
    cout<<cnt<<endl;
}

void solve(vll &a, ll n, ll t)
{
    map<int, int> mpp;
    int s = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        int rem = s - t;
        if (s == t)
        {
            mx = max(mx, i + 1);
        }
        if (mpp.find(rem) != mpp.end())
        {
            /*found*/
            int len = i - mpp[rem];
            mx = max(mx, len);
        }
        if (mpp.find(s) == mpp.end())
        {
            mpp[s] = i;
        }
    }
    if (s < t)
    {
        cout << -1 << endl;
        return;
    }
    cout << n - mx << endl;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        solveG();
    }

    return 0;
}