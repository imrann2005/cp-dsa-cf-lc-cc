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

bool double_is_int(double trouble)
{
    double absolute = abs(trouble);
    return absolute == floor(absolute);
}

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define MOD 1000000007
#define INF 1e18
#define endl "\n"

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t){cerr << t;}
void _print(long long t){cerr << t;}
void _print(string t){cerr << t;}
void _print(char t){cerr << t;}
void _print(double t){cerr << t;}
void _print(long double t){cerr << t;}
void _print(unsigned long long t){cerr << t;}
template<class T, class V> void _print(pair<T,V> p);
template<class T> void _print(vector<T> v);
template<class T> void _print(set<T> v);
template<class T> void _print(multiset<T> v);
template<class T, class V> void _print(map<T,V> v);
template<class T, class V> void _print(pair<T,V> p){cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template<class T> void _print(vector<T> v){cerr << "[ "; for(T i:v){_print(i); cerr << " ";} cerr << "]";}
template<class T> void _print(set<T> v){cerr << "[ "; for(T i:v){_print(i); cerr << " ";} cerr << "]";}
template<class T> void _print(multiset<T> v){cerr << "[ "; for(T i:v){_print(i); cerr << " ";} cerr << "]";}
template<class T, class V> void _print(map<T,V> v){cerr << "[ "; for(auto i:v){_print(i); cerr << " ";} cerr << "]";}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    cout << n << endl;
}

int main(){
    fastio();
    int t=1; cin >> t; while(t--){ solve(); }
    return 0;
}

void solve(ll a, ll b)
{
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }

    ll x = max(a, b);
    ll y = min(a, b);

    if (x % y != 0)
    {
        cout << -1 << endl;
        return;
    }

    ll ratio = x / y;


    if (ratio & (ratio - 1))
    {
        cout << -1 << endl;
        return;
    }

    int operations = 0;
    while (ratio > 1)
    {
        if (ratio % 8 == 0)
        {
            ratio /= 8;
        }
        else if (ratio % 4 == 0)
        {
            ratio /= 4;
        }
        else if (ratio % 2 == 0)
        {
            ratio /= 2;
        }
        operations++;
    }

    cout << operations << endl;
}


void solveC(){
    ll n;
    cin>>n;
    ll ans = 0;
    for(int i=0;i<64;i++){
        ll x = (1LL<<i);
        ans += (n/x);
    }
    cout<<ans<<endl;
}

void basketBall(){
    ll n;
    cin>>n;
    vll a(n);
    vll b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    vll dp1(n);
    vll dp2(n);
    dp1[0]=a[0];
    dp2[0]=b[0];
    for (int i = 1; i < n; i++)
    {
        dp1[i] = max(dp2[i-1]+a[i],dp1[i-1]);
        dp2[i] = max(dp1[i-1]+b[i],dp2[i-1]);
    }
    
    cout<<max(dp1[n-1],dp2[n-1])<<endl;
}

void numProducts(){
    ll n;
    cin>>n;
    vll a(n);
    ll pos=0;
    
    ll tot = (1LL*(n)*(n-1))/2;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>0)pos++;
    }
    tot += n;
    vll suff(n);
    suff[n-1] = (a[n-1] > 0) ? 0 : 1;

    for(int i=n-2;i>=0;i--){
        if(a[i] > 0){
            suff[i] = suff[i+1];
        }
        else{
            suff[i] = suff[i+1]+1;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<suff[i]<<" ";
    // }
    // cout<<endl;
    ll o=0,e=0;

    for (int i = 0; i < n; i++)
    {
        if(a[i] > 0){
            if(suff[i] & 1){
                /*odd*/
                pos += o;
                o++;
            }
            else{
                pos += e;
                e++;
            }
        }
        else{
            if(suff[i] & 1){
                /*odd*/
                pos += e;
                o++;
            }
            else{
                pos += o;
                e++;
            }
        }
    }
    cout<<tot-pos<<" "<<pos<<endl;
}

void journey(){
    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    map<ll,ll>mpp;
    for (int i = 0; i < n; i++)
    {
        ll diff = a[i]-(i+1);
        mpp[diff] += (a[i]);
    }
    ll mx = 0;
    for(auto it : mpp){
        mx = max(it.second,mx);
    }
    cout<<mx<<endl;
}

void candyBox(){
    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    map<ll,ll>mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[a[i]]++;
    }
    set<ll>st;
    ll ans = 0;
    for(auto it : mpp){
        int cnt = it.second;
        while (cnt>0 && st.count(cnt))
        {
            /* code */
            cnt--;
        }
        if(cnt>0){
            st.insert(cnt);
            ans+=cnt;
        }
    }
    cout<<ans<<endl;
}

void dfs(vector<vi>&adj,vi&vis,set<int>&st,int node){
    vis[node] = 1;
    st.insert(node);
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(adj,vis,st,it);
        }
    }
}

void news(){
    int n,m;
    cin>>n>>m;
    vector<vi>adj(n+1);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin>>x;
        // if(x<2){
        //     for(int j=0;j<x;j++){
        //         int val;
        //         cin>>val;
        //     }
        //     continue;
        // }
        vi temp(x);
        for (int j = 0; j < x; j++)
        {
            cin>>temp[j];
        }
        for (int j = 1; j < x; j++)
        {
            int v1 = temp[j-1];
            int v2 = temp[j];
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
    }
    vi vis(n+1,0);
    vi ans(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        if(vis[i]==0){
            set<int>st;
            dfs(adj,vis,st,i);
            int sz = st.size();
            for(auto it : st){
                int idx = it;
                ans[idx] = sz;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

bool dfs2(vector<vi>&adj,vi&vis,vi&b,set<int>&st,int node){
    vis[node]=1;
    bool f=b[node];
    for(auto it:adj[node]){
        if(!vis[it]){
            f &= dfs2(adj,vis,b,st,it);
        }
    }
    if(f){
        st.insert(node);
    }
    return b[node];
}

void queen(){
    ll n;
    cin>>n;
    vector<vi>adj(n+1);
    vi b(n+1,0);
    vi vis(n+1,0);
    int root=-1;
    for (int i = 1; i <= n; i++)
    {
        int p,c;
        cin>>p>>c;
        if(p!=-1){
            adj[i].push_back(p);
            adj[p].push_back(i);
            b[i] = (c==1)?1:0;
        }
        if(p==-1){
            root=i;
        }
    }
    set<int>st;
    bool f=dfs2(adj,vis,b,st,root);
    if(!st.size()){
        cout<<-1<<endl;
        return;
    }
    for (auto it:st)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

void tape(){
    ll n,m,k;
    cin>>n>>m>>k;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vll diff;
    for (int i = 1; i < n; i++)
    {
        ll d = a[i]-a[i-1]-1;
        diff.pb(d);
    }
    ll ans=n;
    sort(all(diff));
    for (int i = 0; i < n-k; i++)
    {
        ans+=diff[i];
    }
    cout<<ans<<endl;
}

void mashmokh(){
    ll n,k;
    cin>>n>>k;
    vi fact[n+1];
    for (int i = 1; i <= n; i++)
    {
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                fact[i].pb(j);

                if(i/j != j){
                    fact[i].pb(i/j);
                }
            }
        }
    }
    int dp[k+1][n+1];
    for (int i = 1; i <= n; i++)
    {
        dp[1][i]=1;
    }
    
    for(int i=2;i<=k;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=0;
            for(auto it:fact[j]){
                dp[i][j] = (dp[i][j]+dp[i-1][it])%MOD;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans = (ans+dp[k][i])%MOD;
    }
    cout<<ans<<endl;

}

int main()
{
    fast_io;

    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     candyBox();
    // }
    //basketBall();
    //queen();
    mashmokh();

    return 0;
}