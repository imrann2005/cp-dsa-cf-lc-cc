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

void sageBDay() {
    // Write your solution here
    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
   sort(a.begin(), a.end());

    int mid = n/2;
    vll ans;
    for (int i = 0; i < mid; i++) {
        ans.pb(a[mid+i]);
        ans.pb(a[i]);
    }
    if(n%2) ans.pb(a.back());

    ll cnt = 0;
    for(int i=1;i+1<n;i++){
        if(ans[i] < ans[i-1] && ans[i] < ans[i+1]) cnt++;
    }

    cout<<cnt<<"\n";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<(i+1==n?'\n':' ');
    }
}

bool chkHeapStones(vll a,ll n,ll mid){
    vll cur_h(all(a));
    for (int i = n - 1; i >= 2; --i) {
        if (cur_h[i] < mid) return false;
        int d = min(a[i], cur_h[i] - mid) / 3;
        cur_h[i - 1] += d;
        cur_h[i - 2] += 2 * d;
    }
    return cur_h[0] >= mid and cur_h[1] >= mid;
}

void heapStones(){
    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    ll l=0;
    ll h=1e9;
    ll ans = l;
    while (l<=h)
    {
        /* code */
        ll mid = (l+h)>>1;
        if(chkHeapStones(a,n,mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            h = mid-1;
        }   
    }
    cout<<ans<<endl;
}

bool chksetDec(vll&a,ll n,ll mid,ll sum,ll k){
    //sort()
    if(sum-mid <= k){
        return true;
    }

    for (int i = a.size()-1; i>=max(1LL,(ll)a.size()-mid); i--)
    {
        /* code */
        sum -= a[i];
        ll rem = mid-(a.size()-i);
        ll s = sum-a[0] + (a.size()-i+1)*(a[0] - rem);
        if(s <= k){
            return true;
        }
    }
    
    return false;
}

void setDec(){
    ll n,k;
    cin>>n>>k;
    vll a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        sum +=  a[i];
    }
    sort(all(a));
    ll l=0;
    ll h=1e10;
    ll ans = 1e10;
    while (l<=h)
    {
        /* code */
        ll mid = (l+h)>>1;
        if(chksetDec(a,n,mid,sum,k)){
            ans = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<ans<<endl;
}


    vector<int> medianSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        multiset<ll>lo,hi;
        ll n = nums.size();


        auto balance = [&](){
            if(lo.size() > hi.size()+1){
                hi.insert(*lo.rbegin());
                lo.erase(prev(lo.end()));
            }
            if(hi.size() > lo.size()){
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }

        };

        for(int i=0;i<n;i++){
            if(lo.empty() || nums[i]<=*(lo.rbegin())){
                lo.insert(nums[i]);
            }
            else hi.insert(nums[i]);
            balance();
            if(i>=k){
                ll out = nums[i-k];
                if(out <= *(lo.rbegin())){
                    lo.erase(lo.find(out));
                }
                else hi.erase(hi.find(out));

                balance();
            }

            if(i>=k-1){
                ll sz = k;
                ll mid = sz/2;
                 ans.push_back(*lo.rbegin());
                }
        }

        return ans;
    }
//[7,4,3,9,1,8,5,2,6], k = 3 n = 9  

void rmvSubstring(){
    string s;
    string t;
    cin>>s>>t;

    int n = s.length();
    int m = t.length();

    vll pre(n,0);
    vll suff(n,0);
    
    int i=0;
    int j=0;
    while (j<m && i<n)
    {
        /* code */
         if(s[i] == t[j]){
            pre[i] = (i>0) ? pre[i-1] + 1 : 1;
            i++;
            j++;
         }
         else{
            pre[i] = (i>0) ? pre[i-1] : 0;
            i++;
         }
    }
    while (i<n)
    {
        pre[i] = (i>0)? pre[i-1] : 0;
        i++;
    }
    i = n-1;
    j = m-1;

    while (j>=0 && i>= 0)
    {
        if(s[i] == t[j]){
            suff[i] = (i==n-1) ? 1 : suff[i+1] + 1;
            i--;
            j--;
         }
         else{
            suff[i] = (i==n-1) ? 0 : suff[i+1];
            i--;
         }
    }
    while (i>=0)
    {
        suff[i] = (i==n-1)? 0 : suff[i+1];
        i--;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<pre[i]<<" ";
    // }
    // cout<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<suff[i]<<" ";
    // }
    // cout<<endl;
    
    i = n-1;
    ll mx = 0;
    while (i>=0 && pre[i]==m)
    {
        mx = max(mx,(ll)n-i-1);
        i--;        
    }
    j = n-1;
    
    while (i>=0)
    {

        ll s = pre[i]+suff[j];
        if(s==m){
            mx = max(mx,(ll)j-i-1);
            i--;
        }
        else if(s<m){
            j--;
        }
    }

    while (j>=0 && suff[j]!=m)
    {
        j--;   
    }    
    mx = max(mx,(ll)j);
    cout<<mx<<endl;
}

void nastyaDoor(){
    ll n,k;
    cin>>n>>k;
    vll a(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    vll pre(n+1,0);

    for (int i = 2; i < n; i++)
    {
        if(a[i] > a[i-1] && a[i] > a[i+1]){
            pre[i] = pre[i-1] + 1;
        }
        else pre[i] = pre[i-1];
    }
    int i=1;
    int j=k;
    ll st = 1;
    ll p = 0;
    while (j<=n)
    {
        /* code */
        ll diff = pre[j-1] - pre[i];
        if(diff > p){
            p = diff;
            st = i;
        }
        j++;
        i++;
    }
    cout<<p+1<<" "<<st<<endl;
}


/*

1 2 3 6
4 5 6 7
7 8 9 8

1 2 4 7 5 3 6 6 8 9 7 8

x-1,y-1   x-1,y   x-1,y+1    
x,y-1     x,y     x,y+1

i=0,j=0

1 i -> j
2 j -> i

*/

int main() {
    fast_io;

    // int t;
    // cin >> t;
    // while (t--) {
    //     rmvSubstring();
    // }
    rmvSubstring();
    // ll n,k;
    // cin>>n>>k;
    // vi a(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>a[i];
    // }
    // vector<int> ans = medianSlidingWindow(a,k);
    // //sageBDay();
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout<<(ans[i])<<" ";
    // }
    // cout<<endl;
    return 0;
}