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
    // Write your solution here
    // ll a;
    // ll b;
    // cin>>a>>b;
    // if(a!=b){
    //     if(b%a==0 || a%b==0){
    //         cout<<1<<endl;
    //         return;
    //     }
    //     else{
    //         cout<<2<<endl;
    //     }
    // }
    // else{
    //     cout<<0<<endl;
    // }
    ll n;
    cin>>n;
    string s;
    cin>>s;

    int i=0;
    int j=n-1;
    ll cnt=0;
    while (i<j)
    {
        if((s[i]=='1') && (s[j]=='0')){
            cnt++;
            //swap(s[i],s[j]);
            i++;
            j--;
        }
        else if((s[i]=='0') && (s[j]=='1')){
            i++;
            j--;
        }
        else{
            if((s[i]=='0') && (s[j]=='0')){
                i++;
            }
            else{
                j--;
            }
        }  
        
    }
    cout<<cnt<<endl;
}

void solveB(){
    // ll n;
    // ll m;
    // cin>>n>>m;
    // vector<ll> a(n);
    // for (int i = 0; i < n; ++i) cin >> a[i];
    // sort(a.begin(), a.end(), greater<ll>()); 
    // ll ans = 0;
    // int k = min(n, m);
    // for (int i = 0; i < k; ++i) {
    //     ans += a[i] * (ll)(m - i);
    // }
    // cout << ans << "\n";
    ll x;
    cin>>x;
    int d = to_string(x).size();
    int n = d + 1;

    ll y = (ll)pow(10, n) - 1 - x;

    cout << y << "\n";

}


void solveC(){
    // ll k,x;
    // cin>>k>>x;
    // ll a=(1LL<<k);
    // ll b=(1LL<<k);
    // ll cnt=0;
    // ll sum=a+b;
    // ll tar=a;
    // ll x1=x;
    // ll x2=sum-x;
    // vll ans;
    // while (x1 != tar)
    // {
    //     /* code */
    //     if(x1<x2){
    //         x1*=2;
    //         x2=sum-x1;
    //         ans.pb(1);
    //     }
    //     else{
    //         x2*=2;
    //         x1=sum-x2;
    //         ans.pb(2);
    //     }
    // }
    // cout<<ans.size()<<endl;
    // reverse(all(ans));
    // for(auto it:ans){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll mx=0;
    ll mx2=-INF;
    ll mn1=INF;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(i&1){
            ans-=a[i];
            mx=max(mx,2*a[i]+i-mn1);
            mx2=max(mx2,2*a[i]-i);
        }
        else{
            ans+=a[i];
            //mx=max(mx,2*a[i]+i-mn1);
            mn1=min(mn1,2*a[i]+i);
            mx=max(mx,mx2-2*a[i]+i);
        }
    }
    if(n&1){
        mx=max(mx,n-1);
    }
    else{
        mx=max(mx,n-2);
    }
    ans+=mx;
    cout<<ans<<endl;
}

void solveL(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll p=0,neg=0;
    for(auto it:s){
        if(it=='-')neg++;
        else p++;
    }
    ll mx1=max(p,neg);
    ll mn1=min(p,neg);

    ll q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        ll a,b;
        cin>>a>>b;
        ll g = __gcd(a,b);
        ll lcm=(1LL*a*b)/g;
        ll mx=mx1;
        ll mn=mn1;
        if(mx==mn){
            yes;
            continue;
        }
        ll needa=lcm/a;
        ll needb=lcm/b;
        ll diff1=abs(mx-mn);
        ll diff2=abs(needa-needb);
        if(diff2==0){
            no;
            continue;
        }
        if((diff1 % diff2) == 0){
            int steps=(diff1)/diff2;
            if(steps*(needa+needb)>n){
                no;
            }
            else yes;
        }
        else{
            no;
        }
    }
    
}

int main() {
    fast_io;

    // int t;
    // cin >> t;
    // while (t--) {
    //     solveL();
    // }
    solveL();

    return 0;
}