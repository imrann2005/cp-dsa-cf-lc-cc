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

void solveA() {
    ll n;
    cin>>n;
    vll a(n);
    ll mx=0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    cout<<mx<<endl;
}

void solveB(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='0'){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='0'){
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
    
}

void solveC(){
    int a,b;
    cin>>a>>b;
    int i=0;
    vll v;
    while (i<30)
    {
        if(b&(1<<i)){
            if(a&(1<<i)){

            }
            else{
                // cout<<(1<<i)<<" ";
                if((1<<i)>a){
                    cout<<-1<<endl;
                    return;
                }
                v.pb(1<<i);
            }
        }
        else{
            if(a&(1<<i)){
                if((1<<i)>a){
                    cout<<-1<<endl;
                    return;
                }
                v.pb(1<<i);
            }
            else{
                // cout<<(1<<i)<<" ";
            }
        }
        i++;
    }
    cout<<v.size()<<endl;
    for(auto it:v){
      cout<<it<<" ";
    }
    cout<<endl;
}

ll ask(ll l,ll r){
    ll x,y;
    cout<<"1 "<<l<<" "<<r<<endl<<flush;
    cin>>x;
    cout<<"2 "<<l<<" "<<r<<endl<<flush;
    cin>>y;
    return y-x;
}

void solveD(){
    ll n;
    cin>>n;
    ll sum = n*(n+1)/2;
    ll c;
    cout<<"2 "<<1<<" "<<n<<endl<<flush;
    cin>>c;
    ll diff = c - sum;

    ll l = 1, h = n;
    while(l < h){
        ll mid = (l + h) >> 1;
        ll d = ask(1, mid);
        if(d == 0){
            l = mid + 1;
        }else{
            h = mid;
        }
    }

    ll L = l;
    ll R = L + diff - 1;
    cout<<"! "<<L<<" "<<R<<endl<<flush;
}

/*

2 4 6 10
0 2 6 10
0 0 4 10
0 0 2 8
0 0 0 6

2 4 6 10
0 4 6 8

a<b<c<d

a b c d 

*/

void solveE(){
    ll n,k;
    cin>>n>>k;
    vll a(n);
    set<ll>st;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        st.insert(i);
    }
    for (int i = 0; i < n; i++)
    {
        st.erase(a[i]);
    }
    
    if(st.size()==0){
        for (int i = 0; i < k; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    else{
        ll o=*st.begin();
        for(int i=1;i<=n;i++){
        st.insert(i);
        }
        cout<<o<<" ";
        st.erase(o);
        st.erase(a[n-1]);
        for(int i=0;i<k-1;i++){
            if(st.size()){
                cout<<*st.begin()<<" ";
                st.erase(*st.begin());
            }
            else{
                cout<<a[n-1]<<" ";
            }
        }
        cout<<endl;
    }
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solveE();
    }

    return 0;
}