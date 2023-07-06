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

#define uo unordered_map
#define pp2 pair<string, int>

int n, m, sol;
uo<int, string> nodeId;
uo<string, vt<pp2>> edges;
uo<string, int> vis, dist;

class Compare {
public:
    bool operator()(pp2 x, pp2 y) {
        return x.s < y.s;
    }
};

void dijk(int u, int v) {
    for (auto [x, y] : vis) {
        dist[x] = inf;
    }
    priority_queue<pp2, vt<pp2>, Compare> q;
    string uId = nodeId[u];
    dist[uId] = 0;
    q.push({uId, 0});
    while (q.size()) {
        auto [targ, cost] = q.top();
        q.pop();
        for (auto [targ2, cost2] : edges[targ]) {
            int totalCost = cost + cost2;
            if (totalCost < dist[targ2]) {
                dist[targ2] = totalCost;
                q.push({targ2, totalCost});
            }
        }
    }
    string sIdEnd = nodeId[v];
    cout << (dist[sIdEnd] == inf ? -1 : dist[sIdEnd]) << endl;
}

void solve(int t_c) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        nodeId[i] = x;
        if (!vis[x]) {
            vis[x] = 1;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y, cost;
        cin >> x >> y >> cost; --x, --y;
        if (x == y)
            continue;
        string idA = nodeId[x], idB = nodeId[y];
        if (idA == idB)
            continue;
        edges[idA].pb({idB, cost});
    }
    cin >> sol;
    KickstarT(t_c + 1) << endl;
    for (int i = 0; i < sol; i++) {
        int u, v;
        cin >> u >> v; --u, --v;
        dijk(u, v);
    }
    nodeId.clear();
    vis.clear();
    dist.clear();
    edges.clear();
}

#undef int
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
//    in("input.txt");
//    out("output.txt");
    int t = 1;
    cin >> t;
    REP (i, t) {
        solve(i);
    }
    return 0;
}
