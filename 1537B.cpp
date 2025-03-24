#include <bits/stdc++.h>
using namespace std;

#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ll long long
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vll vector<ll>
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve(ll n, ll m,ll x,ll y)
{
    // Write your solution here
    vvl corners = {
        {0, 0},
        {0, n - 1},
        {n - 1, m - 1},
        {n - 1, 0},
    };

    ll mx = 0;
    ll my = 0;
    ll maxi = -1;
    for (int i = 0; i < 4; i++)
    {
        ll diff = abs(x-corners[i][0]) + abs(y-corners[i][1]);
        if(maxi > diff){
            mx = corners[i][0];
            my = corners[i][1];
        }
    }
    cout<<mx+1<<" "<<my+1<<" ";
    if(mx==0 && my==0){
        cout<<n-1+1<<" "<<m-1+1<<endl;
    }
    else if(mx==0 && my==m-1){
        cout<<n-1+1<<" "<<0+1<<endl;
    }
    else if(mx==n-1 && my==0){
        cout<<0+1<<" "<<m-1+1<<endl;
    }
    else{
        cout<<0+1<<" "<<0+1<<endl;
    }
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, x, y;
        cin >> n >> m >> x >> y;
        solve(n, m, x-1, y-1);
    }

    return 0;
}