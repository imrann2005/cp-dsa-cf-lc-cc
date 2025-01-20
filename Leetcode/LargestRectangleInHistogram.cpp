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
    void solve()
    {
        // Write your solution here
    }
    vi findPse(vi &arr)
    {
        stack<int> st;
        int n = arr.size();
        vi pse(n);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    vi findNse(vi &arr)
    {
        int n = arr.size();
        vi nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {

            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        // vi nse = findNse(heights);
        // vi pse = findPse(heights);
        int maxi = INT_MIN;
        rep(i, 0, n)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int elt = heights[st.top()];
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                maxi = max(maxi, elt * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty())
        {
            int elt = heights[st.top()];
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxi = max(maxi,elt*(nse-pse-1));
        }

        return maxi;
    }
};

int main()
{
    fastio;

    //Solution solution;
    vi a = {2, 1, 5, 6, 2, 3, 1};
    cout << ~5;

    return 0;
}