#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <climits>

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
const int INF = 2000000000; 

void solveA() {
    ll n;
    cin>>n;
    ll s1=n*n+(n*n-1)+(n*n-2)+(n*n-1-n);
    ll s2=(n*n-1-n)+((n*n-1))+(n*n-1-n+1)+(n*n-1-n-1)+((n*n-1-n)-n);

    if(n==1){
     cout<<1<<endl;
     return;
    }
    if(n==2){
     cout<<9<<endl;
     return;
    }

    cout<<max(s1,s2)<<endl;
    
}


void solveB(){
   ll n;
   cin>>n;
   vll b(n);
   ll x=0;
   for (int i = 0; i < n; i++)
   {
    cin>>b[i];
    if(b[i]==0)x++;
   }
   ll s=0;
   for (int i = 0; i < n; i++)
   {
    s+=b[i];
   }
   
   ll m1=s-n+1;
   ll m2=n-x;

   cout<<min(m1,m2)<<endl;
}

int main() {
    fast_io;

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solveB();
    }

    return 0;
}