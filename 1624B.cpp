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

void solve(int a,int b,int c) {

    // Write your solution here
    if((a+c)%(2*b) == 0){
        yes;
        return;
    }
    if(((2*b - c )> 0 && (2*b - c)%a == 0)){
        yes;
        return;
    }
    if(((2*b - a )> 0 && (2*b - a)%c == 0)){
        yes;
        return;
    }
    no;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int a,b,c;
        cin>>a>>b>>c;
        solve(a,b,c);
    }

    return 0;
}