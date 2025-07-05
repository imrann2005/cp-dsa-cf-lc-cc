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

void solveC(ll k, ll x)
{
    // Write your solution here
    if ((k * k) <= x)
    {
        cout << 2 * k - 1 << endl;
        return;
    }
    long double s = 0;
    ll l = 1;
    ll h = k;
    while (l<=h)
    {
        /* code */
        ll mid = (l+h)>>1;
        ll sum = ((mid)*(mid+1))>>1;
        if(sum == x){
            cout<<mid<<endl;
            return;
        }
        else if(sum > x){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    if((l<=k)){
        cout<<l<<endl;
        return;
    }
    ll left = (k*(k+1))>>1;
    ll sum1 = ((k-1)*(k))>>1;
    l = 1;
    h = k-1;
    while (l<=h)
    {
        /* code */
        ll mid = (l+h)>>1;
        ll sum2 = ((mid)*(mid+1))/2;
        ll rightSum = sum1-sum2;
        rightSum += left;
        if(rightSum == x){
            cout<<k+((k-1)-mid)<<endl;
            return;
        }
        else if(rightSum >= x){
            l = mid + 1;
        }
        else{
            h = mid-1;
        }
    }
    cout<<k+((k-1)-l+1)<<endl;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll k,x;
        cin>>k>>x;
        solveC(k,x);
    }

    return 0;
}