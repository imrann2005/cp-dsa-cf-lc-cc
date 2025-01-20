#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define vvc vector<vector<char>>
#define vll vector<ll>
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve(vvc& grid) {
    // Write your solution here
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(grid[i][j] == 'X'){
                if(i==0 || i==9 || j==0 || j==9)cnt += 1;
                else if(i==1 || i==8 || j==1 || j==8)cnt += 2;
                else if(i==2 || i==7 || j==2 || j==7)cnt += 3;
                else if(i==3 || i==6 || j==3 || j==6)cnt += 4;
                else cnt += 5;
            }
        }
        
    }
    cout<<cnt<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        vvc grid(10,vector<char>(10));
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cin>>grid[i][j];
            }
            
        }
        
        solve(grid);
    }

    return 0;
}