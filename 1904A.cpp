#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pi pair<int, int>
#define pb push_back

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve(int a, int b, int xk, int yk, int xq, int yq) {
    // All possible moves of the knight
    vector<pi> moves = {{a, b}, {a, -b}, {-a, b}, {-a, -b}, 
                         {b, a}, {b, -a}, {-b, a}, {-b, -a}};

    set<pi> knight_moves; // Store knight moves from the king's position

    // Insert all knight moves from the king's position
    for (auto move : moves) {
        int dx = move.first, dy = move.second;
        knight_moves.insert({xk + dx, yk + dy});
    }

    int count = 0; // Count common positions

    // Check which knight moves from the queen's position are in the set
    for (auto move : moves) {
        int dx = move.first, dy = move.second;
        if (knight_moves.count({xq + dx, yq + dy})) {
            count++;
        }
    }

    cout << count << endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int a, b, xk, yk, xq, yq;
        cin >> a >> b >> xk >> yk >> xq >> yq;
        solve(a, b, xk, yk, xq, yq);
    }

    return 0;
}
