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

void divDiff() {
    // Write your solution here
    ll n,m,k;
    cin>>n>>k>>m;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    map<ll,vll>mpp;
    for (int i = 0; i < n; i++)
    {
        int rem=a[i]%m;
        mpp[rem].pb(a[i]);
    }
    //_print(mpp);
    for (auto it:mpp)
    {
        /* code */
        ll key=it.first;
        vll v=it.second;
        // cout<<v.size()<<endl;;
        // cout<<k<<endl;;
        if((int)v.size() >= k){
            cout<<"Yes\n";
            for (int i = 0; i < k; i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<endl;
            return;
        }
    }
    cout<<"No\n";
    

}

void rowGcd(){
    ll n,m;
    cin>>n>>m;
    vll a(n);
    vll b(m);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    ll g=0;
    for(int i=1;i<n;i++){
        g = __gcd(g,abs(a[i]-a[0]));
    }
    //cout<<g<<endl;
    for (int i = 0; i < m; i++)
    {
        ll g1=__gcd(g,a[0]+b[i]);
        cout<<g1<<" ";
    }
    cout<<endl;
    
}

void modEqn(){
    ll a,b;
    cin>>a>>b;
    if(a<b){
        cout<<0<<endl;
    }
    else if(a==b){
        cout<<"infinity"<<endl;
    }
    else{
        int num=a-b;
        vll facts;
        for (int i = 1; i*i <= num; i++)
        {
            if(num%i==0){
                facts.pb(i);
                if(num/i != i){
                    facts.pb(num/i);
                }
            }
        }
        int cnt=0;
        for(auto it:facts){
            if(it>b){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}

// vi spfFind(int n){
//     vi spf(n+1,1e9);
//     vi primes(n+1,1);
//     primes[0]=0;
//     primes[1]=0;
//     for (int i = 2; i <= n; i++)
//     {
//         if(primes[i]){
//             spf[i]=i;
//             for (ll j = i*i; j <= n; j+=i)
//             {
//                 primes[j]=0;
//                 spf[j]=min(spf[j],(int)i);
//             }
            
//         }
//     }

//     return spf;
    
// }

void VwereChildren(){
     int n; cin >> n;
    vector<ll> cnt(n + 1, 0), mx(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        if(x <= n) ++cnt[x];
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; j += i) mx[j] += cnt[i];
    }
    cout << *max_element(all(mx)) << "\n";
}

void exponentiation2(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll y=binPow(b,c,MOD-1);
    ll ans=binPow(a,y,MOD);
    cout<<ans<<endl;
}

//vll spf=spfFind(1e7);

// void reduFrct(){
//     ll n,m;
//     cin>>n>>m;
//     vll a(n);
//     vll b(m);
//     for (int i = 0; i < n; i++)
//     {
//         cin>>a[i];
//     }
//     for (int i = 0; i < m; i++)
//     {
//         cin>>b[i];
//     }
    
//     map<ll,ll>mpp1,mpp2;
//     for (int i = 0; i < n; i++)
//     {
//         ll x=a[i];
//         while (x!=1)
//         {
//             /* code */
//             ll p=spf[x];
//             ll cnt=0;
//             while (x%p==0)
//             {
//                 cnt++;

//                 x/=p;
//             }
//             mpp1[p]+=cnt;
//         }
//     }
//     for (int i = 0; i < m; i++)
//     {
//         ll x=b[i];
//         while (x!=1)
//         {
//             /* code */
//             ll p=spf[x];
//             ll cnt=0;
//             while (x%p==0)
//             {
//                 cnt++;
//                 x/=p;
//             }
//             mpp2[p]+=cnt;
//         }
//     }
//     map<ll,ll>mpp3;
//     for(auto it:mpp1){
//         mpp3[it.first]=min(it.second,mpp2[it.first]);
//     }
//     mpp1=mpp2=mpp3;
//     for (int i = 0; i < n; i++)
//     {
//         ll x=a[i];
//         while (x!=1)
//         {
//             /* code */
//             ll p=spf[x];
//             ll cnt=0;
//             while (x%p==0)
//             {
//                 /* code */
//                 cnt++;
//                 x/=p;
//             }
//             cnt=min(mpp1[p],cnt);
//             mpp1[p]-=cnt;
//             while (cnt)
//             {
//                 /* code */
//                 a[i]/=p;
//                 cnt--;
//             }
//         }
//     }
//     for (int i = 0; i < m; i++)
//     {
//         ll x=b[i];
//         while (x!=1)
//         {
//             /* code */
//             ll p=spf[x];
//             ll cnt=0;
//             while (x%p==0)
//             {
//                 /* code */
//                 cnt++;
//                 x/=p;
//             }
//             cnt=min(cnt,mpp2[p]);
//             mpp2[p]-=cnt;
//             while (cnt)
//             {
//                 /* code */
//                 b[i]/=p;
//                 cnt--;
//             }
//         }
//     }
//     cout<<n<<" "<<m<<endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout<<a[i]<<" ";
//     }
//     cout<<endl;
//     for (int i = 0; i < m; i++)
//     {
//         cout<<b[i]<<" ";
//     }
//     cout<<endl;
    
// }

void zeroQty(){
     int n;
    cin>>n;
    vector<ll>a(n),b(n);
    for(int i=0; i<n; i++) 
    cin>>a[i];
    for(int i=0; i<n; i++) 
    cin>>b[i];
 
    
    int cnt=0;
    map<pair<ll,ll>,ll>mpp;
    for(int i=0; i<n; i++){
        if(a[i]==0 && b[i]==0){
            cnt++;
            continue;
        }else if(a[i]==0 && b[i] != 0){
            continue;
        }
        int p = -b[i], q = a[i];
        int g = __gcd(abs(p), abs(q)); 
        p /= g;
        q /= g;
        if (q < 0) {
            p *= -1;
            q *= -1;
        }
        mpp[{p, q}]++;
    }
    ll mx = 0;
    for (auto it : mpp) {
        mx = max(mx, it.second);
    } 
    cnt += mx;
    cout<<cnt<<endl;
 
}

void valueCards(){
    ll n,k;
    cin>>n>>k;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    set<ll>curr;
    curr.insert(1);
    set<ll>st;
    for(int i=1;i<=k;i++){
        if(k%i==0){
            st.insert(i);
            st.insert(k/i);
        }
    }
    ll ans=1;
    for (int i = 0; i < n; i++)
    {
        set<ll>newIns;
        newIns.insert(a[i]);
        for(auto it:st){
            if(it%a[i]==0 && curr.count(it/a[i])){
                newIns.insert(it);
            }
        }
        if(newIns.count(k)){
            ans++;
            curr.clear();
            curr.insert(a[i]);
            curr.insert(1);
        }
        else{
            for (auto &i:newIns)
            {
                curr.insert(i);
            }
        }
    }
    
    cout<<ans<<endl;
}


vi spfFind(int n){
    vi spf(n+1,1e9);
    vi primes(n+1,1);
    primes[0]=0;
    primes[1]=0;
    for (ll i = 2; i <= n; i++)
    {
        if(primes[i]){
            spf[i]=i;
            for (ll j = i*i; j <= n; j+=i)
            {
                primes[j]=0;
                spf[j]=min(spf[j],(int)i);
            }
            
        }
    }
    return spf;
}

void colliderHelp(ll x, char ch, vll& p, vi& spf, vll& a) {
    ll cpy = x;

    if (ch == '+') {
        if (a[cpy] == 1) {
            cout << "Already on" << endl;
            return;
        }

        vll primes;
        ll temp = cpy;
        while (temp > 1) {
            int prime = spf[temp];
            primes.push_back(prime);
            while (temp % prime == 0) {
                temp /= prime;
            }
        }

        ll conflict_collider = 0;
        for (auto it : primes) {
            if (p[it] != 0) {
                conflict_collider = p[it];
                break;
            }
        }

        if (conflict_collider != 0) {
            cout << "Conflict with " << conflict_collider << endl;
            return;
        }

        cout << "Success" << endl;
        a[cpy] = 1;
        for (auto it : primes) {
            p[it] = cpy;
        }

    } else {
        if (a[cpy] == 0) {
            cout << "Already off" << endl;
            return;
        }

        cout << "Success" << endl;
        a[cpy] = 0;

        vll primes;
        ll temp = cpy;
        while (temp > 1) {
            int prime = spf[temp];
            primes.push_back(prime);
            while (temp % prime == 0) {
                temp /= prime;
            }
        }

        for (auto& i : primes) {
            p[i] = 0;
        }
    }
}

void colliders(){
    vi spf=spfFind(1e5);
    ll n,m;
    cin>>n>>m;
    vll p(n+1,0);
    vll a(n+1,0);
    for (int i = 0; i < m; i++)
    {
        ll x;
        char ch;
        cin>>ch;
        cin>>x;
        colliderHelp(x,ch,p,spf,a);
    }
    
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

vi prime=getSieve(1e6);

void vasPetGme(){
    int n;
    cin>>n;
    vi ans;
    for (int i = 1; i <= n; i++)
    {
        if(prime[i]){
            int p=1;
            while (p <= n/i)
            {
                /* code */
                p=p*i;
                ans.pb(p);
            }
            
        }
    }
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

void orac(){
    ll n;
    cin>>n;
    vll a(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    vll pre(n+1);
    vll suf(n+1);
    ll ans=0;
    pre[1]=a[1]; suf[n]=a[n];
	for(int i=2;i<=n;i++)
		pre[i]=__gcd(pre[i-1],a[i]);
	for(int i=n-1;i>=1;i--)
		suf[i]=__gcd(suf[i+1],a[i]);
	for(int i=0;i<=n-1;i++)
	{
		if(i==0)
			ans=suf[2];
		else if(i==n-1)
			ans=ans*pre[n-1]/__gcd(pre[n-1],ans);
		else
			ans=ans*__gcd(pre[i],suf[i+2])/__gcd(__gcd(pre[i],suf[i+2]),ans);
	}
    cout<<ans<<endl;
}

void oracLcm(){
    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(all(a));//540 540 594
    ll a1=a[0];
    ll gcd=0;
    priority_queue<ll>pq;
    for(int i=1;i<n;i++){
        ll a2=a[i];
        ll pdt=a1*a2;
        ll g=__gcd(a1,a2);
        ll lcm=pdt/g;
        pq.push(lcm);
        if(pq.size()>2){
            pq.pop();
        }
    }
    //_print(pq);
    while (!pq.empty())
    {
        /* code */
        ll lcm=pq.top();

        pq.pop();
        gcd=__gcd(gcd,lcm);
    }
    
    cout<<gcd<<endl;
}

void miniErr(){
    ll n,k1,k2;
    cin>>n>>k1>>k2;
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
    priority_queue<ll>mxh;
    for (int i = 0; i < n; i++)
    {
        ll diff=abs(a[i]-b[i]);
        if(diff>0){
           mxh.push(diff); 
        }
    }
    int steps=0;
    for (int i = 0; i < k1+k2 && !mxh.empty(); i++)
    {
        steps++;
        auto it=mxh.top();
        mxh.pop();
        it--;
        if(it>0){
            mxh.push(it);
        }
        if(mxh.empty()){
            break;
        }
    }

    ll ans=0;
    ll rem = k1+k2-steps;
    if(rem&1){
        ans+=1;
    }
    while (!mxh.empty())
    {
        /* code */
        auto it=mxh.top();
        mxh.pop();
        ans += 1LL*it*it;
    }
    cout<<ans<<endl;
    
}

void commonDiv(){
    int N=1e6;
    vll f(N+1,0);

    int n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        f[a[i]]++;
    }
    for(int i=N;i>=1;i--){
        int cnt=0;
        for(int j=i;j<=N;j+=i){
            cnt+=f[j];
        }
        if(cnt>1){
            cout<<i<<endl;
            return;
        }
    }
    
}

int main() {
    fast_io;

    // int t;
    // cin >> t;
    // while (t--) {
    //     valueCards();
    // }
    //divDiff();
    // rowGcd();
    //modEqn();
    //reduFrct();
    //zeroQty();
    //colliders();
    //zeroQty();

    //vasPetGme();
    //orac();
    //commonDiv();
    miniErr();
    return 0;
}

/*
7
5
1 2 3 4 5

1 2 3 4 5
1 2 2 3 2

3
2 2 2

1 2 3
0 3 0

6
3 1 3 4 9 10

1 2 3 4 5 6
1 1 3 1 1 3

9
1 3 2 4 2 3 7 8 5

1 2 3 4 5 6 7 8 9
1 3 3 5 1 6 1 4 4

1 2 3 4 5 6 7 8 9
1 

1
10
8
7 11 6 8 12 4 4 8

10
9 11 9 12 1 7 2 5 8 10

1 2 3 4 5 6 7 8 9 10


*/