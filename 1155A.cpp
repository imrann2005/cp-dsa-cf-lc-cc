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

void solve(string&a,int n) {
    // Write your solution here
    for (int i = 1; i < n; i++)
    {
        if((a[i]-'a') < (a[i-1]-'a')){
            yes;
            cout<<i-1+1<<" "<<i+1<<endl;
            return;
        }
    }
    no;  
}

int main() {
    fast_io;

        int n;
        cin >> n;
        string a;
        cin >> a;
        solve(a,n);
    

    return 0;
}