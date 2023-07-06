#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pp;
#define int ll
#define lld long double
#define REP(x, y) for (int x = 0; x < y; ++x)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define vt vector
#define f first
#define s second
#define pb push_back
#define PI atan(1) * 4
#define KickstarT(test_case) cout << "Case #" << test_case << ": "
#define endl '\n'
#define in(input) freopen(input, "r", stdin)
#define out(output) freopen(output, "w", stdout)
//----------------------------------------------------------------------------------------//
int d8[2][8] = {{-1, -1, 0, 1, 1, 1, 0, -1}, {0, 1, 1, 1, 0, -1, -1, -1}};
int d4[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}}; char dc[] = {'U', 'R', 'D', 'L'}; // N E S W
const int MD = 1e9 + 7; const int N = 3e5 + 1; const int inf = LONG_LONG_MAX;

/*
*/

void solve(int t_c) {
    int n;
    cin >> n;
    vt<int> x, y, vis(n + 1);
    for (int i = 0; i < n; i++) {
        int z;
        cin >> z;
        if (z & 1)
            x.pb(z), vis[i + 1] = 1;
        else
            y.pb(z);
    }
    sort(ALL(x));
    sort(RALL(y));
    KickstarT(t_c + 1);
    for (int i = 1, ni = 0, nj = 0; i <= n; i++) {
        if (vis[i])
            cout << x[ni++];
        else
            cout << y[nj++];
        cout << " \n"[i == n];
    }
}

#undef int
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    REP (i, t) {
        solve(i);
    }
    return 0;
}
