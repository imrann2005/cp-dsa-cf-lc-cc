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

void solveA()
{
    // Write your solution here
    ll n, m;
    cin >> n >> m;
    if (n <= 2 && m <= 2)
    {
        no;
        return;
    }
    yes;
}

bool comp(vector<int> p1, vector<int> p2)
{
    if (p1[1] != p2[1])
    {
        return p1[1] < p2[1];
    }
    return p1[0] < p2[0];
}
int countTrapezoids(vector<vector<int>> &points)
{
    int n = points.size();
    vector<int> lvl;
    sort(points.begin(), points.end(), comp);
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (points[i][1] == points[i - 1][1])
        {
            cnt++;
        }
        else
        {
            int pts = ((cnt) * (cnt - 1)) / 2;
            if (pts > 0)
            {
                lvl.push_back(pts);
            }
            cnt = 1;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout<<points[i][j]<<" " ;
    //     }
        
    // }
    // cout<<endl;
    if(cnt>0){
        int pts = ((cnt) * (cnt - 1)) / 2;
        lvl.push_back(pts);
    }
    for (int i = 0; i < lvl.size(); i++)
    {
        /* code */
        cout<<lvl[i]<<" ";
    }
    cout<<endl;

    long long mod = 1e9 + 7;
    long long ans = 1;
    vector<int> prev(lvl.size());
    vector<int> suff(lvl.size());
    long long s = 0;
    for (int i = 0; i < lvl.size(); i++)
    {
        prev[i] = s;
        s += lvl[i];
    }
    s = 0;
    for (int i = lvl.size() - 1; i >= 0; i--)
    {
        suff[i] = s;
        s += lvl[i];
    }
    // for (int i = 0; i < lvl.size(); i++)
    // {
    //     /* code */
    //     cout<<prev[i]<<" ";

    // }
    // cout<<endl;
    for (int i = 0; i < lvl.size(); i++)
    {
        /* code */
        cout<<suff[i]<<" ";

    }
    cout<<endl;
    // long long ans = 1;
    for (int i = 0; i < lvl.size(); i++)
    {
        ans = (ans * lvl[i] * suff[i]) % MOD;
    }
    return ans;


}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<int>>points = {{1,0},{2,0},{3,0},{2,2},{3,2}};
        cout<<countTrapezoids(points);
    }

    return 0;
}