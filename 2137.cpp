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
    ll n,k;
    cin>>k>>n;
    for(int i=0;i<k;i++){
        n *= 2;
    }
    cout<<n<<endl;
}

void solveB(){
    ll n;
    cin>>n;
    vll a(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll s=1+n;
    for (int i = 0; i < n; i++)
    {
        cout<<s-a[i]<<" ";
    }
    cout<<endl;
}

void solveC(){
     ll a,b; cin>>a>>b;
        int t = 0;
        ll tmp = b;
        while((tmp & 1LL) == 0){
            t++;
            tmp >>= 1;
        }
        if(t == 0){
            if(a % 2 == 1){
                cout << (a * b + 1) << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else if(t == 1){

            if(a % 2 == 1){
                cout << -1 << '\n';
            } else {
                cout << (a * (b/2) + 2) << '\n';
            }
        } else {
            cout << (a * (b/2) + 2) << '\n';
        }
}

void solveD() {
    ll n;
    cin>>n;
    vll a(n);
    //vector<pair<int,int>>v;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        // v.pb({a[i],i});
    }
    map<ll,vector<ll>>mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[a[i]].pb(i);
    }
    ll ans=0;
    for (auto it:mpp)
    {
        /* code */
        ll num=it.first;
        ll frq=it.second.size();
        if((frq%num) != 0){
            cout<<-1<<endl;
            return;
        }
        ans += num*(frq/num);
    }
    vll res(n);
    if(ans==n){
        int x=1;
      for(auto it:mpp){
        ll val=it.first;
        ll sz=it.second.size();
        ll times=sz/val;
        int idx=0;
        for(int i=0;i<times;i++){
            for(int j=0;j<val;j++){
                int index=it.second[idx];
                res[index]=x;
                idx++;
            }
            x++;
        }
      }

      for(auto it:res){
        cout<<it<<" ";
      }
      cout<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}

void d3a(){
    ll n;
    cin>>n;
    ll cnt=0;
    for (int i = 0; i < 100; i++)
    {
        ll x=n-4*i;
        if(x>=0 && x%2==0){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

void d3b(){
    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if((i!=0) && (i!=n-1) && (a[i]==-1)){
            a[i]=0;
        }
    }
    if(a[0]==-1 || a[n-1]==-1){
        cout<<0<<endl;
        if((a[0]==-1 ) && (a[n-1]==-1)){
            a[0]=0;
            a[n-1]=0;
        }
        else if(a[0]!=-1){
            a[n-1]=a[0];
        }
        else a[0]=a[n-1];

        for (int i = 0; i < n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    cout<<abs(a[0]-a[n-1])<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void d3c1(){
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
    
    ll xa=0,xb=0;
    int idx=-1;
    for (int i = 0; i < n; i++)
    {
        if(a[i]!=b[i]){
            idx=i;
            if(i&1){
                xb++;
            }
            else{
                xa++;
            }
        }
    }
    ll diff=abs(xa-xb);
    if((diff%2)==0){
        cout<<"Tie"<<endl;
    }
    else{
        if(idx%2==0){
            cout<<"Ajisai"<<endl;
        }
        else{
            cout<<"Mai"<<endl;
        }
    }
    
}

void d2a(){
    ll n;
    cin>>n;

    ll y,r;
    cin>>y>>r;
    cout<<min(y/2+r,n)<<endl;


}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        d2a();
    }

    return 0;
}