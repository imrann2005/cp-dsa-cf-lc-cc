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

vector<int> getSieve(int n)
{
    vector<int> primes(n + 1, 1);
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i] == 1)
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = 0;
            }
        }
    }
    return primes;
}

vi sieve = getSieve(1e6);


void solve2(int x, map<int, int> &mpp)
{

   int i = 2;
    while(i * i <= x){
        while (x % i == 0){
            mpp[i]++;
            x /= i;
        }
        i++;
    }
    if(x > 1) mpp[x]++;
}

void solve(vll &a, ll n)
{
    // Write your solution here

    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        solve2(a[i], mpp);
    }
    int val = -1;
    for (auto &it : mpp)
    {
        /* code */
        if ((it.second % n) != 0)
        {
            no;
            return;
        }
        else
        {
            // if(val == -1){
            //     val = it.second;
            // }
            // else{
            //     if(it.second != val){
            //         no;
            //         return;
            //     }
            // }
        }
    }
    yes;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solve(a, n);
    }

    return 0;
}