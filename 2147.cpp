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

ll binPow(ll a,ll b){
    ll res=1;
    while (b>0)
    {
        if(b&1){
            res=(res*a)%MOD;
        }
        a=(a*a)%MOD;
        b=b>>1;
    }
    return res;
}

void solveA() {
    // Write your solution here
    ll x;
    ll y;
    cin>>x>>y;
    if(x<y){
        cout<<2<<endl;
    }
    else{
        ll dif=abs(x-y);
        if(dif>1 && y>1){
            cout<<3<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}

void solveB(){
    ll n;
    cin>>n;
    vll a(2*n+1);
    int cnt=1;
    for (int i = n+1; i <= 2*n; i++){
        a[i]=cnt;
        cnt++;
    }
    a[n]=n;
    cnt=1;
    for (int i = n-1; i>=1; i--)
    {
        /* code */
        a[i]=cnt;
        cnt++;
    }
    for(int it=1;it<=2*n;it++){
        cout<<a[it]<<" ";
    }
    cout<<endl;
   
    
}

void solveC(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
   
     auto is_anchored_left = [&](int i) {
        if (i == 0) return true;
        if (s[i - 1] == '0') return true;
        return false;
    };
    auto is_anchored_right = [&](int i) {
        if (i == n - 1) return true;
        if (i + 1 < n && s[i + 1] == '0') return true;
        return false;
    };

    std::set<int> empty_pots;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            empty_pots.insert(i);
        }
    }

    while (!empty_pots.empty()) {
        int start_node = *empty_pots.begin();
        
        std::vector<int> chain;

        int chain_start = start_node;
        while (empty_pots.count(chain_start - 2)) {
            chain_start -= 2;
        }
        int current_node = chain_start;
        while (empty_pots.count(current_node)) {
            chain.push_back(current_node);
            empty_pots.erase(current_node); 
            current_node += 2;
        }

        if (chain.empty()) continue;
        bool is_left_end_anchored = is_anchored_left(chain.front());
        bool is_right_end_anchored = is_anchored_right(chain.back());

        if (!is_left_end_anchored && !is_right_end_anchored) {
            if (chain.size() % 2 != 0) {
               
                std::cout << "NO\n";
                return;
            }
        }
    }

    // If we process all chains and don't find any impossible scenarios, a valid arrangement exists.
    cout << "YES\n";
}

void solveD(){
    ll n;
    cin>>n;
    vll arr(n);
    map<ll,ll>mpp;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        mpp[arr[i]]++;
    }
    ll a=0;
    ll b=0;
    priority_queue<pair<ll,ll>>pq;
    for(auto it:mpp){
        pq.push({it.second,it.first});
    }
    ll f=0;
    while (!pq.empty())
    {
        /* code */
        auto it=pq.top();
        pq.pop();
        ll val=it.second;
        ll frq=it.first;
        ll acnt=0,bcnt=0;
        if(f==0){
            bcnt=val/2;
            acnt=val-bcnt;
        }
        else{
            acnt=val/2;
            bcnt=val-acnt;
        }
        // bcnt=val/2;
        // acnt=(val-bcnt);
        a += (frq*bcnt);
        b += (frq*acnt);

        if(val&1){
            f = 1-f;
        }
    }

    cout<<b<<" "<<a<<endl;
    
}

void balArr(){
    ll n;
    cin>>n;
    map<ll,ll>mpp;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin>>x;
        mpp[x]++;
    }
    vll a;
    a.pb(INT_MAX);
    for(auto it:mpp){
        a.pb(it.second);
    }
    sort(all(a),greater<ll>());
    ll mx=0;
    for (int i = 1; i < a.size(); i++)
    {
        ll pdt=1LL*i*a[i];
        mx=max(mx,pdt);
    }
    cout<<mx<<endl;
    
}

void mergingSets(){
    ll n,m;
    cin>>n>>m;
    vector<vll>a(n);
    map<ll,ll>mpp;
    for (int i = 0; i < n; i++)
    {
        int l;
        cin>>l;
        for (int j = 0; j < l; j++)
        {
            ll x;
            cin>>x;
            mpp[x]++;
            a[i].pb(x);
        }
        
    }
    ll cnt=0;
    for (int i = 0; i < n; i++)
    {
        bool f=0;
        for (int j = 0; j < a[i].size(); j++)
        {
            /* code */
            if(mpp[a[i][j]] < 2){
                f=1;
            }
        }
        if(f==0){
            cnt++;
        }
        
        
    }
    if(cnt>=2 && mpp.size()==m){
        yes;
        return;
    }
    no;
    
}

void smilo(){
    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(all(a));
    ll s=0;
    ll c=0;
    int i=0;
    int j=n-1;
    while (i<j)
    {
        /* code */
        s += a[i];
        if(s==a[j]){
            c += (s+1);
            s=0;
            i++;
            j--;
        }
        else if(s > a[j]){
            ll diff=s-a[j];
            c += (a[j]+1);
            a[i] = diff;
            j--;
            s=0;
        }
        else{
            i++;
        }
    }
    if(i==j && a[i]!=1){
        ll diff=a[j]-s;
        if(diff&1){
            c+=s+(diff/2)+1+1;
        }
        else{
            c+=s+(diff/2)+1;
        }
    }
    else if(i==j && a[i]==1){
        c+=1;
    }
    cout<<c<<endl;
}

void exponentiation(){
    ll a,b;
    cin>>a>>b;
    cout<<binPow(a,b)<<endl;
}

void powerAddn(){
    ll n;
    cin>>n;
     vector<int>a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        
        if(is_sorted(a.begin(),a.end())){
            cout<<0<<endl;
            return;
        }
        int maxi = 0;
        for (int i=1; i<n; i++){
            if (a[i - 1] > a[i]){
                maxi = max(maxi, a[i - 1] - a[i]);
                a[i] = a[i - 1];
            }
        } 
        int ans=0;
        if(maxi>0){
            ans = log2(maxi) + 1;
        }
 
        cout<<ans<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        powerAddn();
    }

    return 0;
}