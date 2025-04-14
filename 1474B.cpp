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
vi primes = getSieve(1e6);
void solve(int d) {
    // Write your solution here   
    int st = d+1;
    int a = 0;
    for (int i = st; i < primes.size(); i++)
    {
        /* code */
        if(primes[i]){
            a = i;
            break;
        }
    }
    int b = 0;
    for (int i = a+d; i < primes.size(); i++)
    {
        /* code */
        if(primes[i]){
            b = i;
            break;
        }
    }

    cout<<a*b<<endl;
    
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;
        solve(d);
    }

    return 0;
}