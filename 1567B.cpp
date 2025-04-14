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

int xorr(int a){
    if(a%4 == 0) return a;
    if(a%4 == 1) return 1;
    if(a%4 == 2) return a+1;
    return 0;
}

void solve(int a,int b) {
    // Write your solution here
    int x=0;
    x = xorr(a-1);
    if(x == b){
        cout<<a<<endl;
        return;
    }
    else if((x^b)== a){
      cout<<a+2<<endl;
        return;
    }
    else{
        cout<<a+1<<endl;
        return;
    }
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int a,b;
        cin >> a>>b;
        solve(a,b);
    }

    return 0;
}