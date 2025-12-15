#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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

ll calSum(vector<int>&v){
    sort(all(v),greater<int>());
    int n = v.size();

    ll s = 0;
    for (int i = 0,j=n-1 ;i < n ; i++,j-=2)
    {
        /* code */
        s += (1LL*j*v[i]);
    }
    return s;
    }

void solve() {
    // Write your solution here
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
            a[i][j]--;
        }
    }
    vector<vector<int>>x(1e5);
    vector<vector<int>>y(1e5);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            x[a[i][j]].push_back(i);
            y[a[i][j]].push_back(j);

        }
        
    }
    ll ans = 0;
    for (int i = 0; i < 1e5; i++)
    {
        ans += calSum(x[i]);
        ans += calSum(y[i]);
    }
    
    cout<<ans<<endl;
}

int main() {
    fast_io;

    // int t;
    // cin >> t;
    // while (t--) {
        solve();
    //}

    return 0;
}