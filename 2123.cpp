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
    // Write your solution here
    ll n;
    cin>>n;
    if(n%4 == 0){
        cout<<"Bob\n";
    }
    else cout<<"Alice\n";
}

void solveB(){
    ll n,j,k;
    cin>>n>>j>>k;
    vll a(n);
    ll mx = -1;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        mx = max(mx,a[i]);
    }
    if(k == 1){
        if(mx == a[j-1]){
            yes;
        }
        else no;
    }
    else{
        yes;
    }
}

void solveC(){
    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int mn = INT_MAX;
    int mx = INT_MIN;
    set<int>st;
    for (int i = 0; i < n; i++)
    {
        if(mn > a[i]){
            mn = a[i];
            st.insert(i);
        }
    }
    for (int i = n-1; i>=0; i--)
    {
        if(mx < a[i]){
            mx = a[i];
            st.insert(i);
        }
    }
    string s;
    for (int i = 0; i < n; i++)
    {
        if(st.count(i)){
            s.pb('1');
        }
        else s.push_back('0');
    }
    cout<<s<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        
        solveC();
    }

    return 0;
}