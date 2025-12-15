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

vector<int> getSieve(int n){
vector<int>primes(n+1,1);
primes[0] = 0;
primes[1] = 0;
for(int i=2;i*i<=n;i++){
if(primes[i]==1){
for(int j = i*i ; j<=n;j+=i){
primes[j] = 0;
}
}
}
return primes;
}

void solveC() {
    // Write your solution here
    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vll vis(n,0);
    int i=n-1;
    int prev = -1;
    while (i>=0)
    {
        /* code */
        if(a[i]>=prev){
            prev = a[i];
            vis[i] = 1;
        }
        i--;
    }
    prev = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(vis[i])continue;
        if(prev==-1){
            prev = a[i];
        }
        else{
            if(a[i] > prev){
                //cout<<a[i]<<" "<<prev<<endl;
                cnt++;
            }
            prev = a[i];
        }
    }
    cout<<cnt<<endl;

}

void solveC2(){
    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int cnt = 0;
    int x = INF;
    int y = INF;
    for (int i = 0; i < n; i++)
    {
        if(x > y){
            swap(x,y);
        }
        if(a[i] <= x){
            x = a[i];
        }
        else if(a[i] <= y){
            y = a[i];
        }
        else{
            x = a[i];
            cnt++;
        }
    }

    cout<<cnt<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solveC2();
    }

    return 0;
}