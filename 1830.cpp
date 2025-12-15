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

const int NMAX = 2e5+5;
int dp[NMAX], id[NMAX];
vector<pair<int,int>> edg[NMAX];
void dfs(int u){
    for(auto it : edg[u]){
        if(dp[it.first] == 0){
            dp[it.first] = dp[u] + (it.second <= id[u]);
            id[it.first] = it.second;
            dfs(it.first);
        }
    }
}
void solveA(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) dp[i] = id[i] = 0, edg[i].clear();
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        edg[u].push_back({v,i});
        edg[v].push_back({u,i});
    }
    dp[1] = 1;
    dfs(1);
    int ans = 0;
    for(int i=1; i<=n; i++) ans=max(ans,dp[i]);
    cout<<ans<<'\n';
}

void solve() {
    // Write your solution here
    ll n;
    cin>>n;
    map<ll,ll>mpp;
    for (int i = 0; i < n-1; i++)
    {
        ll x;
        ll y;
        cin>>x>>y;
        mpp[x] = y;
        //mpp = y;
    }
    set<ll>st;
    st.insert(1);
    int cnt = 0;
    while (st.size() < n)
    {
        /* code */
        cnt++;
        for (auto &it : mpp)
        {
            if(st.count(it.first)){
                st.insert(it.second);
                mpp.erase(it.first);
                
            }
        }
        
    }
    cout<<cnt<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solveA();
    }

    return 0;
}