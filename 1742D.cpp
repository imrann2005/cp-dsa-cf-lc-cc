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
    vll b(1001, 0);
    for (int i = 0; i < n; i++)
    {
        b[a[i]] = i+1;
    }
    ll mx = -1;
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            if(b[i] && b[j] && ((int)__gcd(i,j)==1)){
                mx = max(mx,b[i]+b[j]);
            }
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