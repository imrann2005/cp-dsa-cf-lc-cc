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

bool is_integer(float k)
{
  return std::floor(k) == k;
}

void solve(int n) {
    // Write your solution here
    vi ans = {2,1,3,4,5,6,7};
    if(n==1){
        cout<<-1<<endl;
        return;
    }
    int mx = n*(n+1)/2;
    float root = sqrt(mx);
    if (is_integer(root))
    {
        cout<<-1<<endl;
    }
    
    

}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}