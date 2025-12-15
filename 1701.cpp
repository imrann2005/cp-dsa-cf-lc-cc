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

bool check(vll&a,ll n,ll time,vll&mpp){
    ll need = 0;
    ll xtra = 0;
    for (int i = 1; i < n+1; i++)
    {
        if(time>=mpp[i]){
            xtra += (time-mpp[i])/2;
        }
        else{
            need += (mpp[i]-time);
        }
    }
    return need <= xtra;
}

void solve() {
    // Write your solution here
    ll n,m;
    cin>>n>>m;
    vll a(m+1);
    for (int i = 1; i < m+1; i++)
    {
        cin>>a[i];
    }
    vll mpp(n+1,0);

    for (int i = 1; i < m+1; i++)
    {
        mpp[a[i]]++;
    }
    
    ll l=0;
    ll h = 2*m;

    while (l<=h)
    {
        /* code */
        ll mid = (l+h)>>1;
        if(check(a,n,mid,mpp)){
            h = mid-1;
        }
        else l = mid+1;
    }
    cout<<l<<endl;

}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}