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
    vll a(n);
    set<ll>st;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        st.insert(a[i]);
    }
    if(st.size() < n){
        yes;
        return;
    }
    no;

}

void solveB(){
    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(all(a),greater<ll>());
    ll s = 0;
    for (int i = 0; i < n; i+=2)
    {
        s += a[i];
    }
    cout<<s<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solveB();
    }

    return 0;
}

/*
8 6
1 4 2 1 2 4 1 2
F T F F F T F F
0 1 1 1 1 2 2 2
*/