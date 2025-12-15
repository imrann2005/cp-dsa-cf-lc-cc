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

bool arrDivhelp(vll&a,ll n,ll mid,ll k){
    ll cnt = 0;
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        if(s == mid){
            cnt++;
            s = 0;
        }
        else if(s > mid){
            cnt++;
            s = 0;
            i--;
        }
    }
    if(s > 0){
        cnt++;
    }
    return cnt <= k;
}

void arrDiv() {
    // Write your solution here
    ll n;cin>>n;
    ll k;cin >> k;
    vll a(n);
    ll s = 0;
    ll mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>a[i];
        s += a[i];
        mx = max(mx,a[i]);
    }
    ll l = mx;
    ll h = s;

    while (l<=h)
    {
        /* code */
        ll mid = (l+h)>>1;
        if(arrDivhelp(a,n,mid,k)){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<l<<endl;
}

bool factoryMxhHelp(vll&a,ll n,ll mid,ll t){
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += mid/a[i];
        if(cnt>=t){
            return true;
            break;
        }
    }

    return cnt >= t;
    
}

void factoryMxh(){
    ll n;cin>>n;
    ll t;cin>>t;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(all(a));
    ll l = 1;
    ll h = 1LL*a[n-1]*t;
    while (l<=h)
    {
        /* code */
        ll mid = (l+h)>>1;
        if(factoryMxhHelp(a,n,mid,t)){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<l<<endl;
}

bool multiTableHelp(ll n,ll mid, ll k){
    ll cnt = 0;
    for (ll i = 1; i <= n; i++)
    {
        cnt += min(n,(mid/i));
       
    }
    return cnt >= (n*n + 1)/2;
}

void multiTable(){
    ll n;
    cin>>n;
    ll h = n*n;
    ll l = 1;

    ll k = (n*n + 1)/2;
    ll ans = 0;
    while (l<=h)
    {
        /* code */
        ll mid = (l+h)>>1;
        if(multiTableHelp(n,mid,k)){
            ans = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    
    cout<<ans<<endl;
    
}

void worms(){
    ll n;
    cin>>n;
    vll a(n);
    
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll m;
    cin>>m;
    vll q(m);
    for (int i = 0; i < m; i++)
    {
        cin>>q[i];
    }
    vll pre(n);
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        pre[i] = s;
    }
    
    for(auto &it : q){
        int idx = lower_bound(all(pre),it) - pre.begin();
        cout<<idx+1<<endl;
    }
    //cout<<endl;
}

bool checkGetTogether(vector<pair<double,double>>&a,int n,double time){
    pair<double,double>curr = {-1e18,1e18};

    for(auto i : a){
        double x = i.first;
        double speed = i.second;

        pair<double,double> range = {x-speed*time,x+speed*time};
        curr = {max(curr.first,range.first),min(curr.second,range.second)};

        if(curr.first > curr.second+1e-9)return false;
    }

    return true;
}
void getTogether(){
    int n;
    cin>>n;
    vector<pair<double,double>>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    double l = 0;
    double h = 1e9;

    for(int i=0;i<60;i++){
        double mid = (l+h)/2;
        if(checkGetTogether(a,n,mid)){
            h = mid;
        }
        else{
            l = mid;
        }
    }
    cout<<setprecision(7)<<fixed<<h<<endl;
    //cout<<h<<endl;
}

bool checkTrackSeg(ll n,ll mid,vll&queries,vector<pair<int,int>>&b){
    vll a(n+1,0);

    for (int i = 1; i <= mid; i++)
    {
        a[queries[i]] = 1;
    }
    vll pre(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = a[i] + pre[i-1];
    }
    
    for(auto &it : b){
        int left = it.first;
        int right = it.second;

        int one = pre[right] - pre[left-1];
        int z = (right-left+1) - one;
        if(one > z){
            return true;
        }
    }

    return false;
}

void trackSeg(){
    ll n,m;
    cin>>n>>m;
    // vll a(n+1);
    // for (int i = 1; i <= n; i++)
    // {
    //     a[i] = 0;
    // }
    vector<pair<int,int>>b(m);
    for (int i = 0; i < m; i++)
    {
        cin>>b[i].first>>b[i].second;
    }
    int q;
    cin>>q;
    vll queries(q+1);
    for (int i = 1; i <= q; i++)
    {
        cin>>queries[i];
    }
    
    ll l = 1;
    ll h = q;
    ll ans = -1;
    while (l <= h)
    {
        /* code */
        ll mid = (l+h)>>1;
        if(checkTrackSeg(n,mid,queries,b)){
            ans = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    
    cout<<ans<<endl;
}

bool ropesChk(vll&a,double mid,ll k){
    ll ans = 0;
    for(auto it : a){
        ans += (it/mid);
        if(ans >= k)return true;
    }
    
    return false;
}

void ropes(){
    ll n,k;
    cin>>n>>k;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    double l = 0;
    double h = 1e18;
    double err = 1e-7;
    double ans = 1e18;
    while (h-l > err)
    {
        /* code */
        double mid = (l+h)/2;
        if(ropesChk(a,mid,k)){
            ans = mid;
            l = mid + err;
        }
        else{
            h = mid-err;
        }
    }
    cout<<setprecision(7)<<fixed<<ans<<endl;
    //cout<<<<endl;
    
}

void tale2Lands(){
    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        a[i] = abs(a[i]);
    }
    
    sort(all(a));
    vll help(n);
    for (int i = 0; i < n; i++)
    {
        help[i] = 2*a[i];
    }
    
    ll ans = 0;

    for (int i = 1; i < n; i++)
    {
        int idx = lower_bound(all(help),a[i]) - help.begin();

        if(idx <= i){
            ans += (i - idx);
        }
    }
    
    cout<<ans<<endl;

}


bool cellNtwrkChk(vll&a,vll&b,ll val){
    ll n = a.size();
    ll m = b.size();

    int i=0;
    int j=0;
    while (j<m && i<n)
    {
        /* code */
        ll diff = abs(b[j]-a[i]);
        if(diff > val){
            j++;
        }
        else{
            i++;
        }
    }

    return i==n;
    
}
void cellNtwrk(){
    ll n,m;
    cin>>n>>m;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vll b(m);
    for (int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    ll l = 0;
    ll h = 1e18;
    ll ans = 1e18;
    while (l<=h)
    {
        /* code */
        ll mid = (l+h)>>1;

        if(cellNtwrkChk(a,b,mid)){
            ans = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<ans<<endl;

}

bool aggCowChk(vll&a,ll n,ll mid,ll c){
    ll idx = a[0];
    ll cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if(a[i]-idx >= mid){
            idx = a[i];
            cnt++;
        }
        if(cnt >= c){
            return true;
        }
    }
    return false;
}

void aggrCows(){
    ll n,c;
    cin>>n>>c;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(all(a));

    ll l = 1;
    ll h = 1e18;
    ll ans = 1;
    while (l<=h)
    {
        /* code */
        ll mid = (l+h)>>1;

        if(aggCowChk(a,n,mid,c)){
            ans = mid;
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    cout<<ans<<endl;
    
}


void pow2s(){
    ll n,k;
    cin>>n>>k;
    int i = 0;
    ll cnt = 0;
    map<ll,ll>mpp;
    vector<ll>p;
    
    while (i<31)
    {
        if(n&(1<<i)){
            cnt++;
            if(i>0){
                p.push_back((1<<i));
            }
            mpp[(1<<i)]++;
        }
        i++;
    }

    if(k>=cnt && k<=n){
        yes;
    }
    else{ 
        no;
        return;
    }
    cnt = mpp.size();
    for (int i = 0; i < p.size() && cnt < k ; i++)
    {
        /* code */
        int x = p[i];
        mpp[x]--;
        mpp[x/2]+=2;

        if(x/2 > 1){
            p.push_back(x/2);
            p.push_back(x/2);
        }
        cnt++;
    }
    
    for(auto it : mpp){
        for (int i = 0; i < it.second; i++)
        {
            /* code */
            cout<<it.first<<" ";
        }
        
    }
    //cout<<endl;
}

ll chkSaagher(vll&a,ll n,ll mid, ll s){
    vll pre(n);
    for (int i = 0; i < n; i++)
    {
        pre[i] = 1LL*a[i]+(i+1)*mid;
    }
    sort(all(pre));
    ll sum = 0;
    //ll cnt = 0;
    for (int i = 0; i < mid; i++)
    {
        sum += (pre[i]);
        // if(sum > s){
        //     break;
        // }
        // else cnt++;
    }
 
    
    
    return sum;
}
 
void sagheer(){
    ll n,s;
    cin>>n>>s;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    ll l = 0;
    ll h = n;
    ll ans = 0;
    while (l<=h)
    {
        
        ll mid = (l+h)>>1;
        if(chkSaagher(a,n,mid,s) <= s){
            ans = mid;
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    if(ans == 0){
        cout<<0<<" "<<0<<endl;
        return;
    }
    //sort(all(a));
    // ll sum = 0;
    // int cnt = 1;
    // for (auto &it : a   )
    // {
    //     sum += (it + cnt*ans);
    //     if(sum==s){
    //         break;
    //     }
    //     if(sum > s){
    //         sum = sum - (it + cnt*ans);
    //         break;
    //     }
    //     cnt++;
    // }
    cout<<ans<<" "<<chkSaagher(a,n,ans,s)<<endl;
}

long double maximumSubarraySum(vector<long double>&a,ll d,ll n){
    vector<long double>prefix(n);
    prefix[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = a[i] + prefix[i-1];
    }

    long double ans = -1e18;
    long double mn = 0;

    for (int i = d-1; i < n; i++)
    {
        long double subArrEndingHere = prefix[i] - mn;
        mn = min(mn,prefix[i-d+1]);
        ans = max(ans,subArrEndingHere);
    }
    return ans;
    
}

bool f(long double x,vector<long double>&a,ll d,ll n){
    vector<long double> transformedArr(n);
    for (int i = 0; i < n; i++)
    {
        transformedArr[i] = a[i] - x;
    }
    return maximumSubarraySum(transformedArr,d,n) >= 0;
}

pair<int,int> subArrWithPositiveSum(vector<long double>&a,ll d,ll n){
    vector<long double>prefix(n);
    prefix[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = a[i] + prefix[i-1];
    }

    long double ans = -1e18;
    long double mn = 0;
    int bestLftIdxSoFar = -1;
    for (int i = d-1; i < n; i++)
    {
        long double subArrEndingHere = prefix[i] - mn;
        ans = max(ans,subArrEndingHere);
        if(ans >=0 ){
            return make_pair(bestLftIdxSoFar+1,i);
        }
        if(mn > prefix[i-d+1]){
            mn = prefix[i-d+1];
            bestLftIdxSoFar = i-d+1;
        }
        
    }
    return {-1,-1};
    

}

pair<int,int> bestSubarray(long double x,vector<long double>&a,ll d,ll n){
    vector<long double> transformedArr(n);
    for (int i = 0; i < n; i++)
    {
        transformedArr[i] = a[i] - x;
    }
    return subArrWithPositiveSum(transformedArr,d,n);
}

void maxAvgSeg(){
    ll n,d;
    cin>>n>>d;

    vector<long double> a(n);
    for(auto &i : a){
        cin>>i;
    }
    
    long double l=0,h=100;

    for(int i=0;i<100;i++){
        long double mid = (l+h)/2;
        if(f(mid,a,d,n)){
            l = mid;
        }
        else{
            h = mid;
        }
    }

    //cout<<setprecision(10)<<fixed<<
    auto ans = bestSubarray(l,a,d,n);
    cout<<ans.first+1<<" "<<ans.second+1<<endl;

}
using lld = long double;

bool chkSelectPairs(lld mid,vector<lld>&a,vector<lld>&b,ll n,ll k){
    vector<lld>c(n);
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i] - b[i]*mid;
    }
    
    sort(all(c),greater<lld>());
    lld s = 0;
    for (int i = 0; i < k; i++)
    {
        /* code */
        s += c[i];
    }
    
    return s>=0;
}
void selectPairs(){
    ll n,k;
    cin>>n>>k;
    vector<lld> a(n);
    vector<lld>b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
    }
    
    lld l= 0;
    lld h= 1e10;

    for (int i = 0; i < 100; i++)
    {
        lld mid = (l+h)/2;
        if(chkSelectPairs(mid,a,b,n,k)){
            l = mid;
        }
        else{
            h = mid;
        }
    }
    cout<<setprecision(7)<<fixed<<l<<endl;
}

int main() {
    fast_io;

    // int t;
    // cin >> t;
    // while (t--) {
    //     aggrCows();
    // }
    selectPairs();

    return 0;
}