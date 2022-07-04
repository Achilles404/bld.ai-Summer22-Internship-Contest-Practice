#include <bits/stdc++.h>
// Sparse Table loading...
using namespace std;
#define Achilles ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ull unsigned long long
#define ll long long
#define pp push_back
#define M 1000000007
const int N = 100005;
const int INF = 1000000;

map<string, vector<string>> adj;
map<string, bool> vis;

bool cmp(string &a, string &b) {
    if (a.size() > b.size()) return true;
    return false;
}

int ans = 1;

void dfs(string &x, int k) {
    vis[x] = true;
    for (auto &i: adj[x]) {
        if (!vis.count(i) && (int) i.size() < (int) x.size()) {
            dfs(i, k + 1);
        }
    }
    ans = max(ans, k);
}

void Achilles1() {
    int n;
    cin >> n;
    vector<string> v(n);
    map<string, ll> f;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        f[v[i]]++;
    }
    sort(v.begin(), v.end(), cmp);
    string s, t;
    for (int i = 0; i < n; ++i) {
        s = v[i];
        for (int j = 0; j < (int) s.size(); ++j) {
            t = s.substr(0, j) + s.substr(j + 1);
            if (f.count(t))
                adj[v[i]].pp(t);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!vis[v[i]])
            dfs(v[i], 1);
    }
    cout << ans;

}

//XD

int main() {
    Achilles
    int tt = 1;
//    cin >> tt;
    while (tt--) Achilles1();
}
