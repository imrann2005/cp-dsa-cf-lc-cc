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

void solveE(vll &a, vll &b, ll n, ll q)
{
    // Write your solution here
    vll p(n);
    p[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        p[i] = p[i - 1] + a[i];
    }
    vll mx(n);
    mx[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        mx[i] = max(a[i], mx[i - 1]);
    }
    
    for (int i = 0; i < q; i++)
    {
        ll l = 0, h = n - 1;
        while (l <= h)
        {
            /* code */
            ll mid = (l+h)>>1;
            if(mx[mid] <= b[i]){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        //cout<<h<<" ";
        if(h>=0) cout<<p[h]<<" ";
        else cout<<0<<" ";
    }
    cout<<endl;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        vll a(n);
        vll b(q);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < q; i++)
        {
            cin >> b[i];
        }

        solveE(a, b, n, q);
    }

    return 0;
}