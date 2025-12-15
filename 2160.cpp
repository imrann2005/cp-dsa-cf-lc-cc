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
#define ff first
#define ss second
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

// template <class T>
// using ordered_set = tree<
//     T,
//     null_type,
//     less<T>,
//     rb_tree_tag,
//     tree_order_statistics_node_update
// >;

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


void solveA() {
    ll n;
    cin>>n;
    int z=0;
    set<ll>st;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.insert(x);
    }
   for(int i=0;i<=100;i++){
    if(!st.count(i)){
        cout<<i<<endl;
        return;
    }
   }
}

void solveB(){
 int n;
    cin >> n;
    vll b(n), d(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    d[0] = b[0];
    for (int i = 1; i < n; i++) d[i] = b[i] - b[i - 1];

    map<int, int> mpp;
    vi a(n);
    int val = 1;

    for (int i = 0; i < n; i++) {
        int need = (i + 1) - d[i];
        if (mpp.count(need)) {
            int x = mpp[need];
            mpp.erase(need);
            mpp[i + 1] = x;
            a[i] = x;
        } else {
            a[i] = val;
            mpp[i + 1] = val;
            val++;
        }
    }

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

void solveC(){
    int n;
    cin>>n;
    vi a(31);
    int cnt=__builtin_popcount(n);
    if(cnt&1){
        no;
        return;
    }
    int i=0;
    while (i<30)
    {
        /* code */
        if(n&(1<<i)){
            a[i]=1;
        }
        else{
            a[i]=0;
        }
        i++;
    }
    //_print(a);
     i=0;
    while (i<30 && a[i]==0)
    {
        /* code */
        i++;
    }
    int j=30;
    while (j>=0 && a[j]==0)
    {
        /* code */
        j--;
    }
   
    while (i<j)
    {
        /* code */

        if(a[i]==a[j]){
            i++;
            j--;
        }
        else{
            no;
            return;
        }
    }
    yes;
    
}

void solveD(){
    ll n;
    cin>>n;
    // vll a(2*n+1);
    // for (int i = 1; i <= 2*n; i++)
    // {
    //     cin>>a[i];
    // }
    vll b(2*n+1);
    set<ll> f;
    vll fnd;
    vll nf;
    for (int i = 1; i <= 2*n; i++)
    {
        cout<<"? "<<i-f.size()<<" ";
        for (int j=1; j <=i; j++)
        {
            if(!f.count(j)){
                cout<<j<<" ";
            }            
        }
        cout<<endl<<flush;
        int x;
        cin>>x;
        if(x!=0){
            b[i]=x;
            f.insert(i);
            fnd.pb(i);
        }
        else{
            b[i]=0;
            nf.pb(i);
        }
    }
    for(int i=0;i<n;i++){
        cout<<"? "<<n+1<<" ";
        for(auto it:fnd){
            cout<<it<<" ";
        }
        cout<<nf[i]<<endl<<flush;
        int x;
        cin>>x;
        b[nf[i]]=x;
    }

    cout<<"! ";
    for (int i = 1; i <= 2*n; i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl<<flush;
}

void solve4b(){
    // string s,t;
    // cin>>s>>t;
    // sort(all(s));
    // sort(all(t));
    // if(s==t){
    //     yes;
    //     return;
    // }
    // no;
    int n;
    cin>>n;
    vll a(n);
    bool f=0;
    bool f1=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(auto it:a){
        if(it&1){
            f1=1;
        }
        else{
            f=1;
        }
    }
    if(f&&f1){
        sort(all(a));
        for(auto it:a){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    for(auto it:a){
            cout<<it<<" ";
        }
    cout<<endl;
    
}

vector<int> getSieve(int n){
vector<int>primes(n+1,1);
primes[0] = 0;
primes[1] = 0;
for(int i=2;i*i<=n;i++){
if(primes[i]==1){
for(int j = i*i ; j<=n;j+=i){
primes[j] = 0;
}
}
}
return primes;
}

vi primes=getSieve(80);

void solve4d(){
    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int it=2;it<primes.size();it++)
    {
        /* code */
        if(primes[it]==1){
        for (int i = 0; i < n; i++)
        {
            int g;
            g=__gcd((ll)a[i],(ll)it);
            if(g==1){
                cout<<it<<endl;
                return;
            }
        }
        } 
    }
    
    cout<<-1<<endl;
    
}

vll pos;
vll v;
bool chk(ll val,ll n,ll k,ll xx){
    pos.clear();
    bool f=1;
    ll cnt=0;

    set<ll>st;
    for (int i = 1; i < n; i++)
    {
        if(v[i]-v[i-1]>=2*val){
            ll x=v[i-1]+val;
            ll y=v[i]-val;

            ll j=x;
            while (pos.size()<k && j<=y)
            {
                /* code */
                if(!st.count(j)){
                    pos.pb(j);
                    //cnt++;
                }
                st.insert(j);
                j++;
            }
            
        }
    }
    if(v[0]>=val){
        ll lst=v[0]-val;
        ll j=0;
        while (pos.size()<k && j<=lst)
        {
            if(!st.count(j)){
                pos.pb(j);
            }
            st.insert(j);
            j++;
        }
    }
    if(v[n-1]+val<=xx){
        ll j=v[n-1]+val;
        while (pos.size()<k && j<=xx)
        {
            if(!st.count(j)){
                pos.pb(j);

            }
            st.insert(j);
            j++;
        }
        
    }
     cnt=pos.size();
    return cnt>=k;
}

void solve4e(){
    ll n,k,x;
    cin>>n>>k>>x;
    v.clear();
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    sort(all(v));

    ll l=0,h=1e9;
    while (abs(h-l)>1)
    {
        ll mid=(l+h)>>1;
        if(chk(mid,n,k,x)){
            l=mid;
        }
        else{
            h=mid;
        }
    }
    if(chk(h,n,k,x)){
        for (int i = 0; i < k; i++)
        {
            cout<<pos[i]<<" ";
        }
        
    }
    else{
        chk(l,n,k,x);
         for (int i = 0; i < k; i++)
        {
            cout<<pos[i]<<" ";
        }
    }
    cout<<endl;
}

void pa(){
    ll r,x,d,n;
    cin>>r>>x>>d>>n;
    string s;
    cin>>s;
    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='2'){
            if(r<x){
                r=max(0LL,r-d);
                cnt++;
            }
        }
        else if(s[i]=='1'){
            cnt++;
            r=max(0LL,r-d);
        }
    }
    cout<<cnt<<endl;
}

void pb(){
    int n;
        ll X;
        cin >> n >> X;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());           

        int L = 0, R = n - 1;
        ll S = 0;                           
        ll bonus = 0;
        vector<ll> order;
        order.reserve(n);

        while (L <= R) {
            ll need = (X - (S % X)) % X; 
            if (S % X == 0) need = X;


            if (a[R] >= need) {
                bonus += a[R];
                S += a[R];
                order.push_back(a[R]);
                --R;
            } else {
                S += a[L];
                order.push_back(a[L]);
                ++L;
            }
        }

        cout << bonus << "\n";
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << order[i];
        }
        cout << "\n";
}

void dfs(ll node,vector<vll>&adj,vll&subtr,vll&vis){
    vis[node]=1;
    subtr[node]=1;

    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,subtr,vis);
            subtr[node]+=subtr[it];
        }
    }

}

void dfs2(ll node,vector<vll>&adj,vll&dp,vll&subtr,vll&vis,ll k,ll n){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            ll x=subtr[it];
        ll diff=0;
        if(n-x < k){
            diff=-1;
        }
        if(x<k){
            diff+=1;
        }
        dp[it]=dp[node]+diff;
        dfs2(it,adj,dp,subtr,vis,k,n);
        }
        
    }
}
void solveF(){
    ll n,k;
    cin>>n>>k;
    vector<vll>adj(n+1);
    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vll subtr(n+1,0);
    //subtr[0]=0;
    vll vis(n+1,0);
    dfs(1,adj,subtr,vis);
    ll cnt=0;
    for (int i = 1; i <= n; i++)
    {
        if(subtr[i]>=k)cnt++;
    }
    vll dp(n+1,0);
    dp[1]=cnt;
    for(int i=0;i<=n;i++){
        vis[i]=0;
    }
    dfs2(1,adj,dp,subtr,vis,k,n);
    ll sum=0;
    
    for (int i = 1; i <= n; i++)
    {
        sum+=dp[i];
    }
    cout<<sum<<endl;

}
vi dp;
ll solveGHelp(vll&a,vll&c,ll i,ll val,ll n){
    if(i>n)return 0;
    if(dp[i]!=-1)return dp[i];
    ll ans=1e18;
   
    if(a[i]>=val){
        ans=min(ans,solveGHelp(a,c,i+1,a[i],n));
    }
    if(a[i]!=val){
        ans=min(ans,c[i]+solveGHelp(a,c,i+1,val,n));
    }
    

    return dp[i]=ans;

}

void solveG(){
    ll n;
    cin>>n;
    vll a(n+1);
    vll c(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin>>c[i];
    }
    //a[0]=-1e9;
    // dp.assign(n+2,-1);
    
    // ll ans = solveGHelp(a,c,1,-1e9,n);
    // cout<<ans<<endl;
    vector <ll> DP(n+1, 0);
    vector <ll> DPnext(n+1, 0);
    
        a[0] = -1e9;
 
        for(ll i = n ; i >= 1 ; i--)
        {
            for(ll j = 0 ; j <= n ; j++)
            {
                ll ans = 1e17;
                if(a[i] != a[j]) ans = min(ans, c[i] + DPnext[j]);
                if(a[i] >= a[j]) ans = min(ans, DPnext[i]);
  

                DP[j] = ans;
            }
            for(ll j = 0 ; j <= n ; j++)
            {
                DPnext[j] = DP[j];
            }
        }
        cout << DP[0] << endl;
}

ll help(vll&x,ll n){
    return x[n/2]-x[(n-1)/2]+1;
}

void easternExhibition(){
    ll n;
    cin>>n;
    vll x(n);
    vll y(n);
    for (int i = 0; i < n; i++)
    {
        int u,v;
        cin>>u>>v;
        x[i]=u;
        y[i]=v;
    }
    sort(all(x));
    sort(all(y));
    ll a=help(x,n);
    ll b=help(y,n);

    cout<<a*b<<endl;
    
}

void agaXorr(){
    // ll n;
    // cin>>n;
    // vll a(n);
    // set<ll>st;
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>a[i];
    //     st.insert(a[i]);
    // }
    // if(st.size()==1){
    //     yes;
    //     return;
    // }
    // ll x=0;
    // for (int i = 0; i < n; i++)
    // {
    //     x^=a[i];
    // }
    // if(x==0){
    //     yes;
    //     return;
    // }

    // no;
    int n, ans = 0; 
    cin >> n;
    int xr = 0;
    vi a(n);
    for(int i=0;i<n;i++) {
    	cin >> a[i];
    	xr ^= a[i];
    }
    if(xr == 0){
    	yes;
    }
    else{
    	int t = 0, c = 0;
    	for(int i=0;i<n;i++) {
    		t^=a[i];
    		if(t==xr){
    			c++;
    			t = 0;
    		}
    	}
    	if(c >= 3 ){
    		yes;
    	}
    	else{
	    	no;
    	}
    }
}

void seqgame(){
    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll x;
    cin>>x;
    sort(all(a));
    if(x>=a[0] && x<=a[n-1]){
        yes;
        return;
    }
    no;
}

void aliceBob(){
    ll n,x;
    cin>>n>>x;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int a1=x-1;
    int a2=x+1;
    int c1=0;
    int c2=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]<=a1){
            c1++;
        }
        if(a[i]>=a2){
            c2++;
        }
    }
    if(c1>c2){
        cout<<a1<<endl;
        return;
    }
    cout<<a2<<endl;
    
}

void sameDiff(){
    ll n;
    cin>>n;

    string s;
    cin>>s;
    ll cnt=0;
    for (int i = n-2; i>=0; i--)
    {
        /* code */
        if(s[i]!=s[n-1]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    

}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        sameDiff();
    }

    return 0;
}