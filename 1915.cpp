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

void solveE(vll &a, ll n)
{
    // Write your solution here
    vll b = a;
    ll s = 0;
    set<ll> st;
    st.insert(s);
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            b[i] = b[i] * -1;
        }
        s += b[i];
        if (st.count(s))
        {
            yes;
            return;
        }
        st.insert(s);
    }
    no;
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

        solveE(a, n);
    }

    return 0;
}