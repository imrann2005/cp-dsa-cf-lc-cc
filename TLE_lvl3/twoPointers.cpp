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

#define ff first
#define ss second
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


void numEql() {
    // Write your solution here
    ll n,m;
    cin>>n>>m;
    vll a(n);
    int i=0;
    int j=0;
    map<ll,ll>mpp;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        mpp[a[i]]++;
    }
    vll b(m);
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        cin>>b[i];
        ans += mpp[b[i]];
    }
    cout<<ans<<endl;
}

void segSmallSet(){
    ll n,k;
    cin>>n>>k;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    map<ll,ll>mpp;
    int i=0;
    int j=0;
    ll ans=0;
    while (j<n)
    {
        /* code */
        mpp[a[j]]++;
        while (i<=j && mpp.size()>k)
        {
            /* code */
            mpp[a[i]]--;
            if(mpp[a[i]]==0){
                mpp.erase(a[i]);
            }
            i++;
        }
        ans += (j-i+1);
        j++;
    }
    cout<<ans<<endl;
}

void totalLen(){
    ll n,k;
    cin>>n>>k;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll ans=0;
    int i=0,j=0;
    ll s=0;
    while (j<n)
    {
        /* code */
        s+=a[j];
        while(i<=j && s>k){
            s-=a[i];
            i++;
        }
        ll cnt = (j-i)+1;
        //cout<<cnt<<" ";
        ans += ((cnt)*(cnt+1))/2;
        //ans += (j-i)+1;
        j++;
    }
    cout<<ans<<endl;
}


void theyEverywhere(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    map<char,ll>mpp;
    set<char>st;
    for (int i = 0; i < n; i++)
    {
        st.insert(s[i]);
    }
    int k=st.size();
    int i=0;
    int j=0;
    int ans=n;
    while(j<n){
        mpp[s[j]]++;

        while(i<=j && mpp.size()>=k){
            ans=min(ans,j-i+1);
            mpp[s[i]]--;
            if(mpp[s[i]]==0){
                mpp.erase(s[i]);
            }
            
            i++;
        }
        j++;
    }

    cout<<ans<<endl;
}

void segSmallSpread(){
    ll n,k;
    cin>>n>>k;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    multiset<ll>st;
    int i=0;
    int j=0;
    ll ans=0;
    while (j<n)
    {
        st.insert(a[j]);
        ll mn=*(st.begin());
        ll mx=*(prev(st.end()));
        ll diff=mx-mn;

        while (i<j && diff>k)
        {
            st.erase(st.find(a[i]));
            i++;
            ll mn=*(st.begin());
            ll mx=*(prev(st.end()));
            diff=mx-mn;
            
        }
        ans += (j-i)+1;
        //cout<<(j-i+1)<<" ";
        j++;
    }
    cout<<ans<<endl;
}

ll solveMoneyTrees(vll&a,int l,int r,ll k){
    int i=l;
    int j=i;
    ll ans=0;
    ll s=0;
    while (j<=r)
    {
        /* code */
        s+=a[j];
        while (i<=j && s>k)
        {
            /* code */
            s-=a[i];
            i++;
        }
        ans=max(ans,(ll)j-i+1);
        j++;
    }
    return ans;
}

void moneyTrees(){
    ll n,k;
    cin>>n>>k;
    vll a(n);
    vll h(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>h[i];
    }
    vll suff(n);
    suff[n-1]=1;
    for (int i=n-2;i>=0;i--)
    {
        if((h[i]%h[i+1])==0){
            suff[i]=1;
        }
        else suff[i]=0;
    }
    ll ans=0;
    
    // for(int i=0;i<n;i++){
    //     if(suff[i]==1){
    //         int j=i;
    //         while (j<n && suff[j]==suff[i])
    //         {
    //             /* code */
    //             j++;
    //         }
    //         if(j==n){
    //             ans=max(solveMoneyTrees(a,i,j-1,k),ans);
    //         }
    //         else{
    //             ans=max(solveMoneyTrees(a,i,j-1,k),ans);
    //         }
    //         // i=j;
    //         // j++;
            
    //     }
    //     // else j++;
    // }
    int segStart = 0;

    for (int i = 0; i < n; i++) {
      
        if (i == n-1 || (h[i] % h[i+1] )!= 0) {
            ans = max(ans, solveMoneyTrees(a, segStart, i, k));
            segStart = i+1;
        }
    }
    cout<<ans<<endl;
}

void tvSubs(){
    ll n,k,d;
    cin>>n>>k>>d;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int i=0;
    int j=0;
    map<ll,ll>mpp;
    ll ans=k;
    while (j<n)
    {
        /* code */
        mpp[a[j]]++;
        if(i<j && (j-i+1)>d){
            mpp[a[i]]--;
            if(mpp[a[i]]==0){
                mpp.erase(a[i]);
            }
            i++;
        }
        if(j-i+1 == d){
            ans=min(ans,(ll)mpp.size());;
        }
        j++;
    }
    cout<<ans<<endl;
}

void book(){
    ll n,k;
    cin>>n>>k;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll s=0;
    int i=0,j=0;
    ll ans=0;
    while (j<n)
    {
        s+=a[j];
        while (i<=j && s>k)
        {
            /* code */
            s-=a[i];
            i++;
        }
        ans=max(ans,(ll)j-i+1);
        j++;
    }
    cout<<ans<<endl;
}

void doubleDate(){
    ll n,k;
    cin>>n>>k;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int i=0;
    int j=0;
    int ans=0;
    while (j<n)
    {
        /* code */
        ll diff=(a[j]-a[i]);
        while((i<=j) && (diff>k)){
            ans+=(n-j);
            i++;
            diff=a[j]-a[i];
        }
        j++;
    }
    cout<<ans<<endl;
}

void minimizaeInt(){
    string s;
    cin>>s;
    vll a;
    vll b;
    for(auto it:s){
        if((it-'0')&1){
            a.pb((it)-'0');
        }
        else b.pb((it)-'0');
    }
    int i=0;
    int j=0;
    while (i<a.size() && j<b.size())
    {
        /* code */
        if(a[i]<b[j]){
            cout<<a[i];
            i++;
        }
        else{
            cout<<b[j];
            j++;
        }
    }
    while (j<b.size())
    {
        cout<<b[j];
        j++;
    }
    while (i<a.size())
    {
        cout<<a[i];
        i++;
    }
    cout<<endl;
}

void loopedPlaylist(){
    ll n,k;
    cin>>n>>k;
    vll a(n);
    ll sum=0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a.pb(a[i]);
    }
    ll ncpy=n;
    // sum*=2;
    n=a.size();
    ll div=0;
    if(k>sum){
        div=k/sum;
        k=k%sum;
    }

    //ll ans=0;

    int i=0;
    int j=0;
    ll s=0;
    int ans=n+1;
    int st=-1;
    while (j<n)
    {
        s+=a[j];
        while (i<=j && s>=k)
        {
            /* code */
            if((j-i+1) < ans){
                ans=(j-i+1);
                st=i;
            }
            s-=a[i];
            i++;
        }
        j++;
    }
    if (k == 0) {
    cout << 1 << " " << div*(n/2) << endl;
    return;
}
    int start = st % (n/2);
    cout<<start+1<<" "<<div*(n/2)+ans<<endl;
}

void segmentKnapsack(){
    ll n,k;
    cin>>n>>k;
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
    int i=0,j=0;
    ll s=0,sc=0;
    ll mx=0;
    while (j<n)
    {
        /* code */
        s+=a[j];
        sc+=b[j];
        while (i<=j && s>k)
        {
            /* code */
            s-=a[i];
            sc-=b[i];
            i++;
        }
        mx=max(mx,sc);
        j++;
    }
    cout<<mx<<endl;
    
}

void rudeSubstring(){
    ll n,c;
    cin>>n>>c;
    string s;
    cin>>s;
    int i=0;
    int j=0;
    int cnta=0;
    int cntb=0;
    int ans=0;

    ll ways=0;
    while (j<n)
    {
        /* code */
        if(s[j]=='b')cntb++;
        if(s[j]=='a')cnta++;
        
        if(s[j]=='b'){
            ways+=cnta;
        }

        while(i<j && ways>c){
            if(s[i]=='a')cnta--;
            if(s[i]=='b')cntb--;
            if(s[i]=='a'){
                ways -= cntb;
            }
            i++;
        }
        ans = max(ans,(j-i+1));
        j++;
    }
    cout<<ans<<endl;
}

bool works(vi&a,vi&b){
    //int n=a.size();
    for (int i = 0; i < 26; i++)
    {
        /* code */
        if(b[i]>a[i]){
            return false;
        }
    }
    return true;
}

void cardSubstrings(){
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    string t;
    cin>>t;
    vi freq(26,0);
    for(auto it:t){
        freq[it-'a']++;
    }
    vi f2(26,0);
    int i=0,j=0;
    ll ans=0;
    while (j<n)
    {
        f2[s[j]-'a']++;

        while (i<=j && !works(freq,f2))
        {
            /* code */
            f2[s[i]-'a']--;
            i++;
        }
        ans += (j-i+1);
        j++;
    }
    cout<<ans<<endl;
}

void kefaNdCompany(){
    ll n,d;
    cin>>n>>d;
    vector<pair<ll,ll>>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(all(a));
    // for(auto it:a){
    //     cout<<it.first<<" "<<it.second<<" ";
    // }
    // cout<<endl;
    int i=0;
    int j=0;
    ll diff=0;
    ll s=0;
    ll mx=0;
    while (j<n)
    {
        /* code */
        ll diff=a[j].first-a[i].first;
        while (i<j && diff>=d)
        {
            /* code */
            s-=a[i].second;
            i++;
            diff=a[j].first-a[i].first;
        }
        s+=a[j].second;
        mx=max(mx,s);
        j++;
    }
    cout<<mx<<endl;
}

void enduringExodus(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vi a;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='0'){
            a.pb(i+1);
        }
    }
    
    int i=0;
    int j=k;
    int z=0;
    int mn=1e9;
    while (j<a.size())
    {
        /* code */
        while(max(a[z]-a[i],a[j]-a[z])>max(a[z+1]-a[i],a[j]-a[z+1])){
            z++;
        }
        int m=max(a[z]-a[i],a[j]-a[z]);
        mn=min(mn,m);
        i++;
        j++;
    }
    cout<<mn<<endl;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void flamenco(){
    ll n,m;
    cin>>n>>m;
    map<ll,ll>mpp;
    for (int i = 0; i < n; i++)
    {
        ll x;cin>>x;
        mpp[x]++;
    }
    vector<pair<ll,ll>>a;
    a.pb({0,0});
    for(auto it:mpp){
        ll k=it.first;
        ll v=it.second;
        a.push_back({k,v});
    }
    n=a.size();
    vll pdt(n);
    pdt[0]=1;
    for (int i = 1; i < n; i++)
    {
        pdt[i]=(pdt[i-1]*(a[i].second))%MOD;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<pdt[i]<<" ";
    // }
    // cout<<endl;
    ll ans=0;
    for(int i=m;i<n;i++){
        if((a[i].first - a[i-m+1].first) < m){
           ll num = pdt[i];
            ll den = pdt[i-m];
            ll inv = binpow(den, MOD-2);
            ll p = (num * inv) % MOD;
            ans = (ans + p) % MOD;
        }
    }
    cout<<ans<<endl;
}

// bool beaverChk(set<pair<int,int>>&st,int i,int j){
//     for(auto itr:st){
//         int start=itr.ff;
//         int end=itr.ss;
//         if(i<=start && j>=end){
//             return true;
//         }
//     }
//     return false;
// }


void beaver() {
    string s;
    if (!(cin >> s)) return;
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

 
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int S = (int)s.size();
    if (S == 0) { cout << "0 0\n"; return; }


    vector<int> maxStartAtEnd(S, -1);

    for (const string &pat : a) {
        int L = (int)pat.size();
        if (L > S) continue;
        for (int st = 0; st + L <= S; ++st) {
            if (s.compare(st, L, pat) == 0) {
                int e = st + L - 1;
                maxStartAtEnd[e] = max(maxStartAtEnd[e], st);
            }
        }
    }

   
    int i = 0;
    int mx = 0, strt = 0;
    for (int j = 0; j < S; ++j) {
        if (maxStartAtEnd[j] >= i) {
            
            i = maxStartAtEnd[j] + 1; 
        }
        int len = j - i + 1;
        if (len > mx) { mx = len; strt = i; }
    }

    cout << mx << " " << strt << "\n";
}


int main() {
    fast_io;

    // int t;
    // cin >> t;
    // while (t--) {
    //     flamenco();
    // }
    //segSmallSpread();
    //book();
    //loopedPlaylist();
    //doubleDate();
    //segmentKnapsack();
    //rudeSubstring();
    //cardSubstrings();
    //kefaNdCompany();
    //enduringExodus();
    beaver();
    return 0;
}