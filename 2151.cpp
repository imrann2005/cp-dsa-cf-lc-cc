#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

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


struct DSU {
    map<long long, long long> parent; 

    long long find(long long x) {
        if (!parent.count(x)) return x; 
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void eraseCell(long long x) {
        parent[x] = find(x+1); 
    }
};

void solveA() {
    ll n,m;
    cin>>n>>m;
    vll a(m);
    for (int i = 0; i < m; i++)
    {
        cin>>a[i];
    }
    bool f=0;
    ll mx=0;
    mx=a[0];
    for(int i=1;i<m;i++){
        if(a[i]<=a[i-1]){
            f=1;
        }
        mx=max(mx,a[i]);
    }
    if(f==0){
        cout<<n-mx+1<<endl;
    }   
    else{
        cout<<1<<endl;
    }
}

void solveB() {
  
         ll n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        set<ll> black;
        for (int i = 0; i < m; i++) {
            long long x;
            cin >> x;
            black.insert(x);
        }

        ll pos = 1;

        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                char cmd = s[i];
                if (cmd == 'A') {
                    pos++;
                    black.insert(pos);
                } else { 
                    ll nxt = pos + 1;
                    while (black.count(nxt)) nxt++;
                    pos = nxt;
                    black.insert(pos);
                }
            } else {
                char prev = s[i - 1];
                if (prev == 'B') {
                    ll nxt = pos + 1;
                    while (black.count(nxt)) nxt++;
                    pos = nxt;
                }
                char cmd = s[i];
                if (cmd == 'A') {
                    pos++;
                    black.insert(pos);
                } else { 
                    ll nxt = pos + 1;
                    while (black.count(nxt)) nxt++;
                    pos = nxt;
                    black.insert(pos);
                }
            }
        }

        cout << black.size() <<endl;
        for (auto x : black) cout << x << " ";
        cout<<endl;
    
}
void solveC(){
    ll n;
    cin>>n;
    n<<=1;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vll a1,a2;
    ll s=0;
    for (int i = 0; i < n; i++)
    {
        if(i&1){
            s+=a[i];
        }
        else{
            s-=a[i];
        }
    }
     if(n == 2) {
        cout << a[1] - a[0] << endl;
        return;
    }
 
    a1.pb(s);
    s=0;
    s=a[n-1]-a[0];
    for (int i = 1; i < n-1; i++)
    {
        if(i&1){
            s-=a[i];
        }
        else{
            s+=a[i];
        }
    }
    a2.pb(s);

    for(int i=1;i<n-i-1;i+=2){
        a1.pb(a1.back()-2*a[i]+2*a[n-i-1]);
    }
    for (int i = 2; i < n-1-i-1; i+=2)
    {
        /* code */
        a2.pb(a2.back()-2*a[i]+2*a[n-i-1]);
    }

    for (int i = 0; i < a2.size(); i++)
    {
        cout<<a1[i]<<" "<<a2[i]<<" ";
    }
    if((n>>1)&1){
        cout<<a1.back()<<endl;
    }
    else{
        cout<<endl;
    }
    
}

bool comp(pair<ll,ll>&p1,pair<ll,ll>&p2){
    return p1.second<p2.second;
}

void greetings(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(all(a),comp);
    //_print(a);
    ll ans=0;
    ordered_set<ll> o;
    for(auto it:a){
        ll sz=o.size();
        ll x=it.first;
        ll y=it.second;
        if(sz>0){
            ll elts=o.order_of_key(x);
            ll nums=sz-elts;
            ans+=nums;
        }
        o.insert(x);
    }
    cout<<ans<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        greetings();
    }

    return 0;
}