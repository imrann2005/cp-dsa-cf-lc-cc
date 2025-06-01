#include <bits/stdc++.h>
using namespace std;

#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
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

void solveE(vector<vector<char>> &a, int n)
{
    // Write your solution here
    set<pair<int,int>>st;
    int cnt = 0;
    for(int i=0;i<n;i++){
        for (int j = 0; j < n; j++)
        {
            if(!st.count({i,j})){
                int v1 = a[i][j]-'0';
                int v2 = a[j][n-1-i]-'0';
                int v3 = a[n-1-i][n-1-j]-'0';
                int v4 = a[n-1-j][i]-'0';
                int s = v1+v2+v3+v4;
                cnt += min(s,4-s);
                st.insert({i,j});
                st.insert({j,n-1-i});
                st.insert({n-1-i,n-1-j});
                st.insert({n-1-j,i});
            }
        }
        
    }
    cout<<cnt<<endl;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        solveE(a, n);
    }

    return 0;
}