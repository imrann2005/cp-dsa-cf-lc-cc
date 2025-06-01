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

void solveB(vector<vi>a,int n,int m) {
    // Write your solution here
    ll cnt = 0;
    for (int j = 0; j < m; j++)
    {
        priority_queue<int,vector<int>,greater<int>>mnh;
        for (int i = 0; i < n; i++)
        {
                mnh.push(a[i][j]);
        }
        int i = 0;
        ll psum = 0;
        while (!mnh.empty())
        {
            /* code */
            ll x = mnh.top();
            mnh.pop();
            if(psum == 0){
                psum += x;
            }
            else{
                cnt += 1LL*(i*x) - psum;
                psum += x;
            }
            i++;
        }
        
    }
    cout<<cnt<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vector<vi>a(n,vector<int>(m,0));
        for (int i = 0; i < n; i++)
        {
           for (int j = 0; j < m; j++)
           {
            cin>>a[i][j];
           }
           
        }
        
        solveB(a,n,m);
    }

    return 0;
}