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

void solveD() {
    // Write your solution here
    ll n,x,y;
    cin>>n>>x>>y;
    vll a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(1&a[i])cnt++;
    }
    
    if(y&1){
        //y odd hai
        if(cnt&1){
            //cnt bhi odd hai
            if(x%2==0){
                cout<<"Alice\n";
                return;
            }
            else{
                cout<<"Bob\n";
                return;
            }
        }
        else{
            if(x&1){
                cout<<"Alice\n";
                return;
            }
            else{
                cout<<"Bob\n";
                return;
            }
        }
    }
    else{
        //y is even
        if(cnt&1){
            if(x%2!=0){
                cout<<"Alice\n";
                return;
            }
            else{
                cout<<"Bob\n";
                return;
            }
        }
        else{
            if(x&1){
                cout<<"Bob\n";
                return;
            }
            else{
                cout<<"Alice\n";
                return;
            }
        }
    }
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solveD();
    }

    return 0;
}