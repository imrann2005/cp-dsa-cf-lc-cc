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

bool isIntegralFmod(float value) {
    return std::fabs(std::fmod(value, 1.0F)) < std::numeric_limits<float>::epsilon();
}

map<ll,ll> pre()
{
    map<ll,ll> st;
    ll s = 0;
    for (int i = 1; i <= 1e6; i++)
    {
        /* code */
        s += i;
        st[s] = i;
    }
    return st;
}

void solveE1(ll n,map<ll,ll>&mpp)
{
    // Write your solution here
    n--;
    for (int i = 2; i <= n; i++)
    {
        /* code */
        float t = (n-i)/(float)i;
        ll t1 = (n-i)/i;
        if (isIntegralFmod(t) && (mpp.find(t1) != mpp.end())){
            if(mpp[t1] <= i){
                yes;
                return;
            }
        }
    }
    no;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    map<ll,ll>st = pre();
    while (t--)
    {
        ll n;
        cin>>n;
        solveE1(n,st);
    }

    return 0;
}