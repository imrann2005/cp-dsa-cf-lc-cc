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


void solveA() {
    ll n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];  

    vll pre(n+1,0);
    for (int i = 1; i <= n; i++) {
        pre[i] = (pre[i-1] + a[i-1]) % 3;
    }

    int total = pre[n];

    for (int l = 1; l < n; l++) {
        for (int r = l+1; r < n; r++) {
            int s1 = pre[l];
            int s2 = (pre[r] - pre[l] + 3) % 3;
            int s3 = (total - pre[r] + 3) % 3;

            if ((s1 == s2 && s2 == s3) ||
                (s1 != s2 && s2 != s3 && s1 != s3)) {
                cout << l << " " << r << "\n";
                return;
            }
        }
    }
    cout << 0 << " " << 0 << "\n";
}

void solveB(){
    ll n;
    cin>>n;
    vll a(n+1);
    set<ll>st;
    int s=0;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
        s+=a[i];
        if(a[i]==0){
            st.insert(i);
        }
    }
    if(st.size()==1){
        int idx=*(st.begin());
        a[idx]=(n*(n+1)/2 - s);
    }
    int i=1;
    int j=n;
    while (a[i]==i)
    {
        /* code */
        i++;
    }
    while (a[j]==j)
    {
        /* code */
        j--;
    }
    
    
    int len=j-i+1;
    if(len<=1){
        cout<<0<<endl;
    }
    else{
        cout<<j-i+1<<endl;
    }
}

void solveC(){
    const int mod=998244353;
    int n;
        cin >> n;
        vi a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<vll> dp(n, vll(2, 0));

        dp[0][0] = 1;
        dp[0][1] = 1; 

        for (int i = 1; i < n; i++) {
       
            if (a[i] >= a[i-1] && b[i] >= b[i-1]) dp[i][0] = (dp[i][0] + dp[i-1][0]) % mod;
            if (a[i] >= b[i-1] && b[i] >= a[i-1]) dp[i][0] = (dp[i][0] + dp[i-1][1]) %mod;

         
            if (b[i] >= a[i-1] && a[i] >= b[i-1]) dp[i][1] = (dp[i][1] + dp[i-1][0]) % mod;
            if (b[i] >= b[i-1] && a[i] >= a[i-1]) dp[i][1] = (dp[i][1] + dp[i-1][1]) % mod;
        }

        ll ans = (dp[n-1][0] + dp[n-1][1]) % mod;
        cout << ans << "\n";
}

void lineEmpire(){
    int n;
        ll x,y;
        cin>>n>>x>>y;
        
        vector<ll> a(n);
        for(int i=0; i<n; i++)
        cin >> a[i];
        
        ll ans = 0; 
        ll pc = 0; 
        
        for(int i=0; i<n; i++){
            ans += (a[i]-pc)*y;
 
            ll remain = n-i-1;
            if(x <= remain * y){
                ans += (a[i]-pc)*x;
                pc = a[i];
            }
        }
        
        cout<<ans<<endl;
    
}
bool check(vll& arr, int n,int idx,int end)
{
    int count = 0;
    for (int i = idx; i <= end; i++) {
        if (arr[i] > arr[(i + 1) % (n-1)]) {
            count++;
        }
    }

    return count <= 1;
}
void solve2A(){
    ll n;
    cin>>n;
    vll a(n);
    int idx=-1;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(a[i]==n)idx=i;
    }
    if(a[0]!=1 && a[n-1]!=1){
        no;
        return;
    }
    bool f1,f2;
    if(a[0]==1){
        int i=idx;
        int j=idx;
        int curr=a[idx];
        while (i>=1 && j<n)
        {
            /* code */
            if(a[i-1]==curr-1){
                i--;
                curr--;
            }
            else if(j+1 <n && a[j+1]==curr-1){
                j++;
                curr--;
            }
            else{
                break;
            }
        }
        if(j-i+1 == n){
            yes;
            return;
        }
        else{
            no;
            return;
        }
    }
    else 
    { 
        int i=idx;
        int j=idx;
        int curr=a[idx];
        while (i>=0 && j<n-1)
        {

            if((i-1 >= 0)&&  a[i-1]==curr-1){
                i--;
                curr--;
            }
            else if(a[j+1]==curr-1){
                j++;
                curr--;
            }
            else{
                break;
            }
        }
        if(j-i+1 == n){
            yes;
            return;
        }
        else{
            no;
            return;
        }
    }
 
}

void discount(){
    ll n,k;
    cin>>n>>k;
    vll a(n);
    vll b(k);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin>>b[i];
    }
    sort(all(b));
    sort(all(a),greater<ll>());
    ll s=0;
    int idx=0;
    for(int i=0;i<k;i++){
        ll val=b[i];
        int tmp=idx;
        for (int j = tmp; j < min(n,tmp+(val-1)); j++)
        {
            s+=a[j];
            idx++;
        }
        idx++;
    }
    while (idx<n)
    {
        /* code */
        s+=a[idx];
        idx++;
    }
    
    cout<<s<<endl;

}

void weWereBothChildren(){

}/* */

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        discount();
    }

    return 0;
}
/*
5 3
18 3 7 2 9
3 1 1

18 9 7 3 2
1 1 3


6 1
1 2 6 3 3 4
5

6 4 3 3 2 1
5

*/