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

void solveA()
{
    // Write your solution here
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vi freq(31, 0);
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j <= 30)
        {
            /* code */
            if (a[i] & (1 << j))
            {
                freq[j]++;
            }
            j++;
        }
    }
    int f = 1;
    int g = -1;
    for (int i = 0; i < freq.size(); i++)
    {
        /* code */
        if (freq[i] > 0)
        {
            f = 0;
            if (g == -1)
            {
                g = freq[i];
            }
            else
                g = __gcd(g, freq[i]);
        }
    }
    vi facts;
    for (int i = 1; i * i <= g; i++)
    {
        /* code */
        if ((g % i) == 0)
        {
            facts.push_back(i);

            if ((g / i) != i)
            {
                facts.push_back(g / i);
            }
        }
    }
    sort(all(facts));
    for (int i = 0; i < facts.size(); i++)
    {
        cout << facts[i] << " ";
    }

    if (f == 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        solveA();
    }

    return 0;
}
