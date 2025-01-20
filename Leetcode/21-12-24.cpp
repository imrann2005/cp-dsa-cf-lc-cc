#include <bits/stdc++.h>
using namespace std;

#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)

class Solution
{
public:
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
    vector<vi> ans;
    void solve(v1 &nums, int n)
    {
        // Write your solution here
        int i = 0;
        vi v;
        while (i < nums.size())
        {
            if (((1 << i) & n) != 0)
            {
                v.pb(nums[i]);
            }
            i++;
        }
        ans.pb(v);
    }
};

int main()
{
    fastio;

    Solution solution;
    solution.solve();

    return 0;
}
