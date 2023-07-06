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

vt<string> m {"zero","one","two","three","four","five","six","seven","eight","nine"};
vt<string> m2 {"double","triple","quadruple","quintuple","sextuple","septuple","octuple","nonuple","decuple"};

vt<int> T;

void doIt(string s) {
    int n = s.size(), i = 0;
    string now = "";
    while (i < n) {
        while (i < n && s[i] != '-')
            now += s[i++];
        T.pb(stoi(now));
        now = "";
        i++;
    }
}

void solve(int t_c) {
    string s, s2;
    cin >> s >> s2;
    int n = s.size();
    doIt(s2);
    int i = 0, start = 0;
    KickstarT(t_c + 1);
    for (auto x : T) {
        int en = start + x;
        for (i = start; i < en; i++) {
            int times = 0;
            while (i + 1 < en && s[i] == s[i + 1])
                i++, times++;
            // times = realTimes + 1 successive digits
            if (times == 0) {
                cout << m[s[i] - '0'] << " ";
            } else if (times < 10) {
                cout << m2[--times] << " " << m[s[i] - '0'] << " ";
            } else {
                for (int j = 0; j <= times; j++)
                    cout << m[s[i] - '0'] << " ";
            }
        }
        start += x;
    }
    cout << endl;
    T.clear();
}

#undef int
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    in("input.txt");
    out("output.txt");
    int t = 1;
    cin >> t;
    REP (i, t) {
        solve(i);
    }
    return 0;
}
