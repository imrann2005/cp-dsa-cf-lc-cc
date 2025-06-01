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
    int i=0;
    int j=n-1;
    int mx = 0;
    while (i<j)
    {
        if(p[i]<suf[j]){
            i++;
        }
        else if(p[i]==suf[j]){
            int cnt = (i-0+1)+(n-1-j+1);
            mx = max(mx,cnt);
            i++;
            j--;
        }
        else{
            j--;
        }
    }
    cout<<mx<<endl;
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
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solve(a, n);
    }

    return 0;
}