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

void solveC() {
    // Write your solution here
    ll n,w;
    cin>>n>>w;
    multiset<ll>a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a.insert(x);
    }
    
    ll h = 1;
    ll rem = w;

    while (!a.empty())
    {
        /* code */
        auto it = a.upper_bound(rem);
        if(it == a.begin()){
            h++;
            rem = w;
        }
        else{
            it--;
            int val = *it;
            rem -= val;
            a.erase(it);
        }
    }
    
    cout<<h<<endl;
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