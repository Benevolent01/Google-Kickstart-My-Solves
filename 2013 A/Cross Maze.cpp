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

#define tests in("input.txt");out("output.txt");

/*
*/

int n;
vt<string> mat(100);
const int MAX_STEPS = 10e3;

int findDir(int i, int j) {
    return (i == 0 ? (j == 0 ? 1 : 2) : (j == 0 ? 0 : 3));
}

bool isWall(int i, int j) {
    return i < 0 || j < 0 || i >= n || j >= n || mat[i][j] == '#';
}

bool isEmpty(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n && mat[i][j] == '.';
}

int findNextDir(int i, int j, int dir) {
    int west = (dir + 3) % 4; // left
    if (isWall(i + d4[0][west], j + d4[1][west])) {
        int east = (dir + 1) % 4;
        int south = (dir + 2) % 4;
        if (isEmpty(i + d4[0][dir], j + d4[1][dir]))
            return dir;
        else if (isEmpty(i + d4[0][east], j + d4[1][east]))
            return east;
        else if (isEmpty(i + d4[0][south], j + d4[1][south]))
            return south;
    } else if (isEmpty(i + d4[0][west], j + d4[1][west]))
        return west;
    return -1;
}

void solve(int t_c) {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> mat[i];
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2; --x1, --y1, --x2, --y2;

    KickstarT(t_c + 1);

    int ni = x1, nj = y1;
    string s; string dc2 = "NESW";
    int dir = findDir(ni, nj);

    while (9999 & 1 | 1 ^ 0 % 1) {
        dir = findNextDir(ni, nj, dir);
        if (s.size() > MAX_STEPS || dir == -1) {
            cout << "Edison ran out of energy.\n";
            return;
        }
        ni += d4[0][dir];
        nj += d4[1][dir];
        s += dc2[dir];
        if (ni == x2 && nj == y2) {
            cout << s.size() << endl << s << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++)
        mat[i].clear();
}

#undef int
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    tests
    int t = 1;
    cin >> t;
    REP (i, t) {
        solve(i);
    }
    return 0;
}
