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

void solve(int a,int b,int c,int d) {
    // Write your solution here
    if(d < b){
        cout<<-1<<endl;
        return;
    }
    int d1 = d-b;
    a += d1;
    if(a >= c){
        d1 += a-c;
    }
    else {
        cout<<-1<<endl;
        return;
    }
    cout<<d1<<endl;

}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        solve(a,b,c,d);
    }

    return 0;
}