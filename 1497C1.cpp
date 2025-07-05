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

void solveC1(ll n) {
    // Write your solution here
    if(n&1){
        cout<<(n>>1)<<" "<<(n>>1)<<" "<<1<<endl;
    }
    else{
        int x = n/2;
        if(x&1){
            cout<<((n-2)>>1)<<" "<<((n-2)>>1)<<" "<<2<<endl;
           
        }
        else{
            cout<<(n>>2)<<" "<<(n>>2)<<" "<<(n>>1)<<endl;
        }
    }
}

void solveB(vll&a,ll n,ll m){
    vll rem(m);
    for (int i = 0; i < n; i++)
    {
        /* code */
        rem[a[i]%m]++;
    }
    ll cnt = 0;
    int i=1,j=m-1;
    if(rem[0] > 0)cnt++;

    while (i<j)
    {
        if(rem[i]!=0 && rem[i]==rem[j]){
            cnt++;
        }
        else{
            int diff = abs(rem[i]-rem[j]);
            cnt += diff;
        }
        i++;
        j--;
    }
    if(i==j){
        if(rem[i] > 0)cnt++;
    }

    cout<<cnt<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        // ll n,k;
        // cin >> n>>k;

        // solve(n);
        ll n;
        ll m;
        cin>>n>>m;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        solveB(a,n,m);
    }

    return 0;
}