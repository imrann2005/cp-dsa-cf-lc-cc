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

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pb push_back
#define ff first
#define ss second

#define MOD 1000000007
#define INF 1e18


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

// void solve(){
//     int n; cin >> n;
//     vector<int> a(n);
//     for(int i=0;i<n;i++) cin >> a[i];
//     cout << n << endl;
// }

// int main(){
//     fastio();
//     int t=1; cin >> t; while(t--){ solve(); }
//     return 0;
// }

bool works(vll&a,ll val,ll mx){
    vll t;
    for (int i = 0; i < val; i++)
    {
        /* code */
        t.push_back(a[i]);
    }
    //_print(a);
    sort(all(t));
    int i = t.size()-1;
    ll s = 0;
    while (i>=0)
    {
        /* code */
        s += t[i];
        i-=2;
    }
    if(s <= mx){
        return true;
    }
    return false;
    
}

void solveB() {
    // Write your solution here
    ll n,mx;
    cin>>n>>mx;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll l=2;
    ll h=n;
    while (l<=h)
    {
        /* code */
        ll mid = (l+h)>>1;
        if(works(a,mid,mx)){
            l = mid + 1;
        }
        else{
            h = mid-1;
        }
    }
    cout<<h<<endl;
}

void div4A(){
    ll n,x;
    cin>>x>>n;
    if(n&1){
        cout<<x<<endl;
    }
    else{
        cout<<0<<endl;

    }
}

void div4B(){
    ll n,m,x,y;
    cin>>n>>m>>x>>y;
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
    
    cout<<n+m<<endl;
}

void div4C(){
    ll n,m;
    cin>>n>>m;
    int pos=0;
    int pts=0;
    int time=0;
    for (int i = 0; i < n; i++)
    {
        /* code */
        int t2,pos2;
        cin>>t2>>pos2;
        int diff=t2-time;
        if(diff&1){
            if(pos==pos2){
                pts+=(diff-1);
            }
            else{
                pts+=(diff);
            }
        }   
        else{
            if(pos==pos2){
                pts += diff;
            }
            else{
                pts += (diff-1);
            }
        }
        time=t2;
        pos=pos2;
    }
    int diff = m-time;
        cout<<pts+diff<<endl;
    
}

void div4E(){
    ll n,k;
    cin>>n>>k;
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
    for(auto &it:mpp){
        int key=it.first;
        int val=it.second;
        if(val%k!=0){
            cout<<0<<endl;
            return;
        }
        else{
            it.second = it.second/k;
        }
    }

    int i=0;
    int j=0;
    ll ans=0;
    map<ll,ll>mpp2;
    while (j<n)
    {
        mpp2[a[j]]++;
        while (i<j && mpp2[a[j]]>mpp[a[j]])
        {
            /* code */
            mpp2[a[i]]--;
            if(mpp2[a[i]]==0){
                mpp2.erase(a[i]);
            }
            i++;
        }
        ans+=(j-i+1);
        j++;
    }
    cout<<ans<<endl;
}

void div4D(){
    ll n;
    cin>>n;
    vll a(n);
    ll se=0;
    ll so=0;
    vll b;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(a[i]&1){
            b.pb(a[i]);
        }
        else{
            se+=a[i];
        }
    }
    sort(all(b),greater<ll>());
    if(b.size()==0){
        cout<<0<<endl;
        return;
    }
    // _print(b);
    // cout<<se<<endl;
    int m=b.size();
    int ops = ((m&1) ? m/2+1 : m/2);
    for (int i = 0; i<ops ; i++)
    {
        /* code */
        se+=b[i];
    }

    cout<<se<<endl;
}

vll factorial(){
    vll a(21,0);
    ll pdt=1;
    a[1]=pdt;
    for (ll i = 2; i <= 20; i++)
    {
        pdt=1LL*pdt*i;
        a[i]=pdt;
    }
    return a;
}

vll fcts=factorial();

void factsNdPows2(){
    ll n;
    cin>>n;
    // _print(fcts);
    auto it=lower_bound(all(fcts),n)-fcts.begin();
    if(fcts[it]>n){
        it--;
    }
    ll mn=INT_MAX;
    ll bits = __builtin_popcountll(n);
    mn=min(mn,bits);
    for (int i = 20; i>=1; i--)
    {
        ll diff=n-fcts[i];
        if(diff>=0){
            ll bits=__builtin_popcountll(diff);
            mn=min(mn,bits+1);
        }
    }
    

    cout<<mn<<endl;

}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        factsNdPows2();
    }

    return 0;
}