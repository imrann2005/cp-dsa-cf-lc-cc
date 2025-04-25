#include <bits/stdc++.h>
using namespace std;

#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ll long long
#define vi vector<int>
#define pb push_back
#define all(v) v.begin(), v.end()
#define endl '\n'

vector<int> getSieve(int n) {
    vector<int> primes(n + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i)
                primes[j] = 0;
        }
    }
    return primes;
}

vi primes = getSieve(1e6);

void solve(vi &a, int n) {
    if (primes[n]) {
        sort(all(a));
        cout << a[n - 1] - a[0] << endl;
        return;
    }

    vi f;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            f.pb(i);
            if (i != n / i) f.pb(n / i);
        }
    }

    sort(all(f));
    vector<ll> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + a[i];

    ll result = LLONG_MIN;

    for (int d : f) {
        if (d == n) continue; 

        ll mx = LLONG_MIN, mn = LLONG_MAX;
        ll prev = 0;
        for (int j = d - 1; j < n; j += d) {
            ll curr = prefix[j];
            ll n1 = curr - prev;
            prev = curr;
            mx = max(mx, n1);
            mn = min(mn, n1);
        }
        result = max(result, mx - mn);
    }

    cout << result << endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        if (n == 1) {
            cout << 0 << endl;
        } else {
            solve(a, n);
        }
    }

    return 0;
}
