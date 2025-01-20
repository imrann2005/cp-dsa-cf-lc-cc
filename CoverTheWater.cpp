#include <bits/stdc++.h>
using namespace std;

void solve(string &s, int n)
{
    int f = 0;
    int e = 0;
    int i = 0;

    while (i < n)
    {
        if (s[i] == '.')
        {
            e++;
        }
        else
        {
            if (e >= 3)
            {
                f = 2;
                cout << f << endl;
                return;
            }
            else
                f += e;
            e = 0;
        }
        i++;
    }
    if (e >= 3)
        f = 2;
    else
        f += e;

    cout << f << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n;
        cin.ignore();
        getline(cin, s);

        solve(s, n);
    }
    return 0;
}