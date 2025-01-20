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

void solve(int a0,int a1,int a3,int a4) {
    // Write your solution here
    int x1 = a1 + a0;
    int x2 = a3-a1;
    int x3 = a4-a3;

    if(x1==x2 && x2==x3){
        cout<<3<<endl;
        return;
    }
    if(x1 == x2 || x2 == x3 || x3==x1){
        cout << 2<<endl;
        return;
    }
    cout << 1 <<endl;

}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int a0,a1,a3,a4;
        cin>>a0>>a1>>a3>>a4;
        solve(a0,a1,a3,a4);
    }

    return 0;
}