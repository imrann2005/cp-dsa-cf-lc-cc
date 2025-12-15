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
    vll a(n);
    set<ll>st;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        st.insert(a[i]);
    }
    ll sz=st.size();
    cout<<1+(sz-1)*2<<endl;
}

ll cheb(ll x1, ll y1, ll x2, ll y2){
    return max(abs(x1-x2), abs(y1-y2));
}
ll manh(ll x1, ll y1, ll x2, ll y2){
    return abs(x1-x2) + abs(y1-y2);
}

void solveB(){
    ll n,a,b,c,d;

  cin>>n>>a>>b>>c>>d;
        
        if(a==c){
            if(d>b){
                cout<<d<<endl;
            }else{
                cout<<n-d<<endl;
            }
            return;
        }
        if(b==d){
            if(c>a){
                cout<<c<<endl;
            }else{
                cout<<n-c<<endl;
            }
            return;
        }
        if(c>a && d>b){    
            cout<<max(c,d)<<endl;
            return;
        }
        if(c>a && d<b){
            cout<<max(c,n-d)<<endl;
            return;
        }
        if(c<a && d>b){ 
            cout<<max(n-c,d)<<endl;
            return;
        }
        if(c<a && d<b){
            cout<<max(n-c,n-d)<<endl;
            return;
        }
}

void teatasters(){
    int n;
    cin >> n;
    vll a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    vll sum(n + 1);
    for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + b[i];
    vll cnt(n + 1), add(n + 1);
    for (int i = 0; i < n; ++i) {
      int j = upper_bound(sum.begin(), sum.end(), a[i] + sum[i]) - sum.begin() - 1;
      cnt[i] += 1;
      cnt[j] -= 1;
      add[j] += a[i] - sum[j] + sum[i];
    }
    for (int i = 0; i < n; ++i) {
      cout << cnt[i] * b[i] + add[i] << ' ';
      cnt[i + 1] += cnt[i];   
    }
    cout << '\n';
}

void lunatic(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vll>adj(n+1);
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        //cout<<u<<v<<endl;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    //_print(adj);
    priority_queue<ll,vll,greater<ll>>pq;
    pq.push(1);
    vll vis(n+1,0);
    vis[1]=1;
    while (!pq.empty())
    {
        /* code */
        int node=pq.top();
        pq.pop();
        cout<<node<<" ";
        for (auto it:adj[node])
        {
            if(!vis[it]){
            vis[it]=1;
            pq.push(it);
            }
        }
        
    }
    cout<<endl;
}
    
void solveC(){
    ll n,q;
    cin>>n>>q;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vll pre(n,0);
    ll s=0;
    for (int i = 0; i < n; i++)
    {
        s+=a[i];
        pre[i]=s;
    }
    vll dp(n,1);
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1])dp[i]+=dp[i-1];
    }
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        int len=(r-l)+1;
        ll sum=pre[r]-pre[l]+a[l];
        if(len%3!=0 || sum%3!=0){
            cout<<-1<<endl;
            continue;
        }
        ll ans=len/3;
        if(l>r-dp[r])ans++;
        cout<<ans<<endl;
    }
    

}

void div2A(){
    ll n;
    cin>>n;
    ll cnt=0;
    ll w=n;
    ll l=0;
    
        cnt += n/2;
        l += n/2;
        w=n-l;
        while (w>1 || l>1)
        {
           cnt += w/2;
            cnt += l/2;
            int losers=w/2;
           w -= w/2;
           l -= l/2;
           l+=losers;
        }
    cout<<cnt+1<<endl;
}

char dir(pair<int,int> a, pair<int,int> b) {
    // returns direction to move from a -> b
    int dx = b.first - a.first;
    int dy = b.second - a.second;
    if (dx == 1) return 'D';
    if (dx == -1) return 'U';
    if (dy == 1) return 'R';
    if (dy == -1) return 'L';
    return '?';
}

void div2B(){
   ll n; 
    ll k;
   cin >> n;
    cin >> k;
    ll p= n*n;
    if(k==p-1){
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    ll d=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(d<k){ 
                cout<<"U";
                d++;
            }else{
                if(j==n-1 && i!= n-1){
                    cout<<"D";
                    continue;
                }
                if(j!=n-1){
                    cout<<"R";
                    continue;
                    
                }
                cout<<"L";
            }
        }
        cout<<endl;
    }
    }

void div2D(){
    ll n; 
    cin >> n;
    int x=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j+i<=n){
                cout<<j<<" "<<j+i<<endl; cout.flush();
                cin>>x;
            }
            if(x==1) break;
        }
        if(x==1) break;
    }
}

void apple(){
    ll n;
    cin>>n;
    set<ll>st;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.insert(x);
    }
    cout<<st.size()<<endl;
}

ll dfs(vector<vi>&adj,vi&vis,int node,ll&cnt){
    vis[node]=1;
    ll s=0;
    for(auto it:adj[node]){
        if(!vis[it]){
            s+=dfs(adj,vis,it,cnt);
        }
    }
    if((s+1) & 1){

    }
    else{
        cnt++;
    }
    return s+1;
}

void bitwisereversion(){
    ll x,y,z;
    cin>>x>>y>>z;
    int i=0;
    ll a=0,b=0,c=0;
    while (i<63)
    {
        /* code */
        if(x&(1LL<<i)){
            a |= (1LL<<i);
            b |= (1LL<<i);
        }
        i++;
    }
    i=0;
    while (i<63)
    {
        /* code */
        if(y&(1LL<<i)){
            b |= (1LL<<i);
            c |= (1LL<<i);
        }
        i++;
    }
    i=0;
    while (i<63)
    {
        /* code */
        if(z&(1LL<<i)){
            a |= (1LL<<i);
            c |= (1LL<<i);
        }
        i++;
    }
    if(((a&b)==x) && ((b&c)==y) && ((a&c)==z)){
        yes;
        return;
    }
    // cout<<x<<" "<<y<<" "<<z<<endl;
    // cout<<(a&b)<<" "<<(b&c)<<" "<<(c&a)<<endl;
    no;
}

void cutemall(){
    ll n;
    cin>>n;
    vector<vi>adj(n+1);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi vis(n+1,0);
    vis[1]=0;
    if(n&1){
        cout<<-1<<endl;
        return;
    }
    ll cnt=0;
    ll x=dfs(adj,vis,1,cnt);
    cout<<cnt-1<<endl;
}

bool comp(pair<ll,ll>&p1,pair<ll,ll>&p2){
    if(p1.second==p2.second){
        return p1.first>p2.first;
    }
    return p1.second<p2.second;

}
// void nestedSeg(){
//     ll n;
//     cin>>n;
//     //ordered_set st;
//     vector<pair<ll,ll>>a;
//     vector<pair<ll,ll>>a1;
//     map<pair<ll,ll>,int>mpp;
//     // map<ll,vll>mpp;
//     for(int i=0;i<n;i++){
//         ll u,v;
//         cin>>u>>v;
//         a.pb({u,v});
//         a1.pb({u,v});
//         //mpp[{u,v}]=
//     }
//     sort(all(a),comp);
//     // _print(a);
//     //ordered_set<ll>st;
//     for(auto it:a){
//         int l=it.first;
//         int r=it.second;
//         int sz=st.size();
//         int num=st.order_of_key(l);
//         int cnt=sz-num;
//         mpp[{l,r}]+=cnt;
//         st.insert(l);
//     }
//     for (auto it:a1)
//     {
//         cout<<mpp[{it.first,it.second}]<<endl;
//     }
    
// }

bool comp2(pair<ll,ll>&p1,pair<ll,ll>&p2){
    if(p1.first==p2.first){
        return p1.second<p2.second;
    }
    return p1.first<p2.first;
// }
}
// void twoTv() {
//     ll n; cin >> n;
//     vector<pair<ll,ll>> a(n);
//     for (int i=0;i<n;i++) cin >> a[i].first >> a[i].second;
//     sort(all(a));

//     ordered_set<pair<ll,int>> st;
//     for (int i=0;i<n;i++) {
//         ll l=a[i].first, r=a[i].second;
//         // remove all intervals that ended before or at l
//         while (!st.empty()) {
//             auto it = st.begin();
//             if (it->first < l) st.erase(it);
//             else break;
//         }
//         if ((int)st.size() >= 2) { no; return; }
//         st.insert({r,i});
//     }
//     yes;
// }

void dfslabor(vector<vi>&adj,vi&par,int node,vi&vis){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            par[it]=node;
            dfslabor(adj,par,it,vis);
        }
    }
}

void labourHeracles() {
    ll n;
    cin >> n;
    vll a(n + 1);
    ll s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }

    vector<vi> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    priority_queue<ll> mxh;

    for (int i = 1; i <= n; i++) {
        int d = (int)adj[i].size();
        for (int j = 1; j < d; j++) mxh.push(a[i]);
    }

    cout << s << " ";  // k = 1

    for (int i = 2; i <= n - 1; i++) {
        s += mxh.top();
        mxh.pop();
        cout << s << " ";
    }
    cout << endl;
}

bool comp22(pair<pair<int,int>,int>&p1,pair<pair<int,int>,int>&p2){
    if(p1.first.first == p2.first.first){
        return p1.first.second<p2.first.second;
    }
    return p1.first.first<p2.first.first;
}

void divnUnion(){
    ll n;
    cin>>n;
    vector<pair<pair<int,int>,int>>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].first.first>>a[i].first.second;
        a[i].second=i+1;
    }
    sort(all(a),comp22);
    //_print(a);
    int s=-1;
    int e=-1;
    vll b(n+1,1);
    bool f=0;
    for(auto it:a){
        int l=it.first.first;
        int r=it.first.second;
        int idx=it.second;
        if(f){
            b[idx]=2;
        }
        else if(s==-1 && e==-1){
            s=l;
            e=r;
        }
        else{
            if(e<l){
                f=1;
                b[idx]=2;
            }
            else{
                s=min(s,l);
                e=max(e,r);
            }
        }
    }
    if(!f){
        cout<<-1<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
}

void ehabNMex(){
    int n;
    cin>>n;
    vector<vector<pair<int,int>>>adj(n+1);
    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb({v,i});
        adj[v].pb({u,i});
    }
    vi ans(n-1,-1);
    int k=0;
    for (int i = 1; i <= n; i++)
    {
        if(adj[i].size()>=3){
            ans[adj[i][0].second]=0;
            ans[adj[i][1].second]=1;
            ans[adj[i][2].second]=2;
            k=3;
            break;
        }
    }
    for(int i=0;i<n-1;i++){
        if(ans[i]==-1){
            ans[i]=k++;
        }
    }
    for(auto it:ans){
        cout<<it<<endl;
    }    
}


bool comp222(pair<pair<int,int>,int>&p1,pair<pair<int,int>,int>&p2){
    if(p1.first.first==p2.first.first)return p1.first.second>p2.first.second;
    return p1.first.first<p2.first.first;
}

void nesteddSegments(){
    ll n;
    cin>>n;

    vector<pair<pair<int,int>,int>>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].first.first;
        cin>>a[i].first.second;
        a[i].second=i+1;
    }
    sort(all(a),comp222);
    set<pair<ll,ll>>st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.begin()->first < a[i].first.first)
			st.erase(st.begin());
		if (!st.empty() && (--st.end())->first >= a[i].first.second){
			printf("%d %d\n", a[i].second, (--st.end())->second);
			return ;
		}
		st.insert({a[i].first.second, a[i].second});
    }
    
    cout<<"-1 -1"<<endl;
}

void kamazing(){
    ll n;
    cin>>n;
    vll f(n+1);
    vll last(n+1);
    vll arr(n+1);
    vll ans(n+1);
    for (int i = 1; i <= n; ++i) {
    f[i] = last[i] = 0;
    ans[i] = -1;
  }
  
  for (int i = 1; i <= n; ++i) {
    cin>>arr[i];
  }
  
  for (int i = 1; i <= n; ++i) {
    int x = arr[i];
    f[x] = max(f[x], i - last[x]);
    last[x] = i;
  }
  
  for (int x = 1; x <= n; ++x) {
    f[x] = max(f[x], n - last[x] + 1);
    
    for (int i = f[x]; i <= n && ans[i] == -1; ++i) {
      ans[i] = x;
    }
  }
  
  for (int i = 1; i <= n; ++i) {
    //printf("%d%c", ans[i], " \n"[i == n]);
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}

ll binPow(ll a,ll b,ll m){
    ll res=1;
    while (b>0)
    {
        if(b&1){
            res=(res*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }
    return res;
}

void dfs(vector<vector<int>>&adj,int node,vi&vis,ll&sz){
    vis[node]=1;
    sz++;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(adj,it,vis,sz);
        }
    }
}

void edgyTrees(){
    ll n,k;
    cin>>n>>k;
    vector<vector<int>>adj(n+1);
    for (int i = 0; i < n-1; i++)
    {
        int u,v,x;
        cin>>u>>v>>x;
        if(x==0){
        adj[u].pb(v);
        adj[v].pb(u);
        }
    }
    ll tot=binPow(n,k,MOD);
    vi vis(n+1,0);
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ll sz=0;
            dfs(adj,i,vis,sz);
            ll pdt=binPow(sz,k,MOD);
            ans=(ans+pdt)%MOD;
        }
    }
    cout << ((tot - ans + MOD) % MOD) << endl;

}

void zeroArr(){
    ll n;
    cin>>n;
    vll a(n);
    ll s=0;
    ll mx=0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
        s+=a[i];
    }
    if(s&1){
        no;
        return;
    }
    ll rem=s-mx;
    if(mx<=rem){
        yes;
        return;
    }
    no;
    //else yes;

}

void power2Facts(){
    ll n;
	cin >> n;

	vll fact(15);
	fact[0] = 1;
	for (int i = 1; i <= 14; i++) fact[i] = fact[i - 1] * i; 

	vll vec;
	for (int i = 3; i <= 14; i++) vec.push_back(fact[i]); 

	ll ans = LLONG_MAX;
	for (int j = 0; j < (1LL << 12); j++) {
		ll sum = 0;
		ll cnt = 0; 
		for (int i = 0; i < 12; i++) {
			if (j & (1LL << i)) {
				sum += vec[i];
				cnt++;
			}
		}
		if (sum > n) continue; 
		cnt += __builtin_popcountll(n - sum);
		ans = min(ans, cnt);
	}

	cout << ans << endl;
}

void pride(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    bool var = false;
    int cnt=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i] == 1){
            cnt++;
            var = true;
        }
    }
    if(var){
        cout<<n-cnt<<endl;
    }else{
        ll g=a[0];
    for(int i=1; i<n; i++){
        g = __gcd(g,a[i]);
    }
    if(g!=1){
        cout<<-1<<endl;
    }else{
        ll ans = LLONG_MAX;
        for(ll i=0; i<n; i++){
            ll gc = a[i];
            for(ll j=i+1; j<n; j++){
                gc = __gcd(gc,a[j]);
                if(gc==1){
                    ans = min(ans,(j-i)+(n-1));
                }
            }
        }
        cout<<ans<<endl;
    }
    }
}

void balancedbit(){
    int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		for (int i = k; i < n; ++i) {
				if (s[i] == '1') {
						if (s[i % k] == '0') { 
								cout << "NO\n";
								return;
						}
						s[i % k] = '1'; 
				} else if (s[i] == '0') {
						if (s[i % k] == '1') { 
								cout << "NO\n";
								return;
						}
						s[i % k] = '0'; 
				}
		}

		int c1 = 0, c0 = 0;
		for (int i = 0; i < k; ++i) {
				if (s[i] == '1') ++c1; 
				if (s[i] == '0') ++c0; 
		}


		if (c1 > k / 2 || c0 > k / 2)
				cout << "NO\n";
		else
				cout << "YES\n";

}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        //lunatic();
        //bitwisereversion();
        //divnUnion();
        //kamazing();
        //power2Facts();
        balancedbit();
    }
    //cutemall();
    //twoTv();
    //labourHeracles();
    //ehabNMex();
    //nesteddSegments();
    //edgyTrees();
    //zeroArr();
    //pride();
    return 0;
}
