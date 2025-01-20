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

void solve(int n)
{
    // Write your solution here
    int cnt = 0;
    int i = 0;
    while (i <= 31)
    {
        if ((n & (1 << i)) != 0)
        {
            cnt++;
        }
        i++;
    }

    cout << cnt << endl;
}

void solve2(int s, int g)

{
    int cnt = __builtin_popcount(s^g);
    // while (s != 0 || g != 0)
    // {
    //     if ((s & 1) != (g & 1))
    //     {
    //         cnt++;
    //     }
    //     s = s >> 1;
    //     g = g >> 1;
    // }
    cout<<cnt;
}

void solve3(vector<int>&nums,int n){
    int i=0;
    vi v;
    while (i<nums.size())
    {
       if(((1<<i)&n)!= 0){
        v.pb(nums[i]);
       }
       i++;

    }
    
    for (auto &i : v)
    {
        cout<<i;
    }
    cout<<"\n";

}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        vi a = {1,2,3};
        vi ans;
        for (int i = 0; i < (1<<a.size()); i++)
        {
            solve3(a,i);
            
        }
        
       
        
    }

    return 0;
}