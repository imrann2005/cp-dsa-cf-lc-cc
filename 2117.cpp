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

void solveA(vll&a,ll n,ll x) {
    // Write your solution here
    int i = 0;
    int f = 0;
    while (i<n)
    {
        /* code */
        if(a[i] == 0){
            i++;
        }
        else{
            if(f==0){
                f = 1;
                i += x;
            }
            else{
                no;
                return;
            }
        }
        
        
    }
    yes;
}

void solveB(ll n){
    int mid = n/2;
    for(int i=1;i<=n;i+=2){
        cout<<i<<" ";
    }
    if(n&1){
        mid = n-1;
    }
    else mid = n;

    for(int i=mid;i>0;i-=2){
        cout<<i<<" ";
    }
    cout<<endl;
}

void solveC(vll&a,int n){
    set<int>st;
    set<int>st2;
    st.insert(a[0]);
    st2.insert(a[0]);
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if(st.count(a[i])){
            st.erase(a[i]);
        }
        st2.insert(a[i]);
        if(st.empty()){
            st = st2;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        // ll n,x;
        // cin>>n>>x;
        // vll a(n);
        // for (int i = 0; i < n; i++)
        // {
        //     cin>>a[i];
        // }
        // ll n;
        // cin>>n;
        // solveA(a,n,x);
        //solveB(n);
        ll n;
        cin>>n;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        solveC(a,n);
    }

    return 0;
}