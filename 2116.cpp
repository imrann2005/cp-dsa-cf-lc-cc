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

void solveA(ll a,ll b,ll c,ll d) {
    // Write your solution here
    ll mn1 = min(a,c);
    ll mn2 = min(b,d);
    if(mn1 >= mn2){
        cout<<"Gellyfish\n";
        return;
    }
    cout<<"Flower\n";
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        solveA(a,b,c,d);
    }

    return 0;
}