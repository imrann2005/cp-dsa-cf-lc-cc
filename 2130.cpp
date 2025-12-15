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
    ll s = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(a[i]==0){
            cnt++;
        }
        s+=a[i];
    }
    //sort(all(a));
    s += cnt;
    cout<<s<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solveA();
    }

    return 0;
}