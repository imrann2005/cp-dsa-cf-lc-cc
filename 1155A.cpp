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

void solveC(){
    ll n;
    cin>>n;
    vll s(n);
    vll u(n);
    for (int i = 0; i < n; i++)
    {
        cin>>u[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    vector<vector<ll>>skills(n);
    for (int i = 0; i < n; i++)
    {
        skills[u[i]-1].push_back(s[i]);
    }
    
   for(auto &v : skills){
    sort(all(v));
   }
   vector<vll>pre(n,vll(1,0));
   for (int i = 0; i < n; i++)
   {
        for (int j = 0; j < skills[i].size(); j++)
        {
           
            pre[i].push_back(pre[i].back() + skills[i][j]);
        }
        
   }
   
   vll ans(n+1,0);
   for (int i = 0; i < n; i++)
   {
    ll nums = skills[i].size();
    for (int k = 1; k <= nums; k++)
    {
        ans[k] += (pre[i].back() - pre[i][nums%k]);
    }
    
   }
   
   for (int i = 1; i <= n; i++)
   {
    cout<<ans[i]<<" ";
   }
   cout<<endl;
    
}

int main() {
    fast_io;

        // int n;
        // cin >> n;
        // string a;
        // cin >> a;
        // solve(a,n);
        int t;
        cin>>t;
        while (t--)
        {
            /* code */
            solveC();
        }
        
    //solveC();
    

    return 0;
}