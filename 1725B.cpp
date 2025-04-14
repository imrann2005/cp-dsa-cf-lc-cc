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

void solve(vll&a,ll n,ll d) {
    // Write your solution here
    sort(all(a));
    int j=n-1;
    int i=0;
    ll cnt =0 ;
    while (i < j)
    {
        if(a[j] > d){
            cnt++;
            j--;
        }
        else{
            ll s = a[j];
            while (i < j)
            {
                s = s + a[j];
                if(s > d){
                    cnt++;
                    break;
                }
                i++;
            }
            
            j--;
            i++;
            
        }
       
    }
    if(i<n && j==i && a[i] > d){
        cnt++;
    }

    cout<<cnt<<endl;
    
}

int main() {
    fast_io;
    
        ll n;
        ll d;
        cin >> n >> d;
        vll a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
       
        solve(a,n,d);
    

    return 0;
}

/*8 12
12 12 10 14 12 11 15 11*/
//10 11 11 12 12 12 14 15