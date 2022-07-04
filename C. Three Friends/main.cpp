#include <bits/stdc++.h>

using namespace std;
#define Achilles ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pp push_back
const int N = 100005;
const int INF = 1000000;

vector<vector<pair<ll, ll>>> adj;
vector<vector<pair<ll, ll>>> adjr;
ll dx[N], dy[N], dz[N];
ll dxr[N], dyr[N], dzr[N];

void di(ll s, int f) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll >>, greater<>> q;
    if (f == 0) dx[s] = 0;
    if (f == 1) dy[s] = 0;
    if (f == 2) dz[s] = 0;

    q.push({0, s});
    while (!q.empty()) {
        ll d_v = q.top().first;
        ll v = q.top().second;
        q.pop();

        if (f == 0 && d_v != dx[v]) continue;
        if (f == 1 && d_v != dy[v]) continue;
        if (f == 2 && d_v != dz[v]) continue;

        for (auto edge: adj[v]) {
            ll len = edge.first;
            ll to = edge.second;

            if (f == 0 && dx[v] + len < dx[to]) {
                dx[to] = dx[v] + len;
                q.push({dx[to], to});
            }
            if (f == 1 && dy[v] + len < dy[to]) {
                dy[to] = dy[v] + len;
                q.push({dy[to], to});
            }
            if (f == 2 && dz[v] + len < dz[to]) {
                dz[to] = dz[v] + len;
                q.push({dz[to], to});
            }
        }
    }
}

void dir(ll s, int f) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll >>, greater<>> q;
    if (f == 3) dxr[s] = 0;
    if (f == 4) dyr[s] = 0;
    if (f == 5) dzr[s] = 0;

    q.push({0, s});
    while (!q.empty()) {
        ll d_v = q.top().first;
        ll v = q.top().second;
        q.pop();

        if (f == 3 && d_v != dxr[v]) continue;
        if (f == 4 && d_v != dyr[v]) continue;
        if (f == 5 && d_v != dzr[v]) continue;

        for (auto edge: adjr[v]) {
            ll len = edge.first;
            ll to = edge.second;

            if (f == 3 && dxr[v] + len < dxr[to]) {
                dxr[to] = dxr[v] + len;
                q.push({dxr[to], to});
            }
            if (f == 4 && dyr[v] + len < dyr[to]) {
                dyr[to] = dyr[v] + len;
                q.push({dyr[to], to});
            }
            if (f == 5 && dzr[v] + len < dzr[to]) {
                dzr[to] = dzr[v] + len;
                q.push({dzr[to], to});
            }
        }
    }
}

void Achilles1() {
    ll n, m;
    ll u, v, c;
    cin >> n >> m;
    adj.resize(n + 1);
    adjr.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> c;
        adj[u].pp({c, v});
        adjr[v].pp({c, u});
    }
    for (int i = 0; i <= n; ++i) {
        dx[i] = dxr[i] = 10000000000000;
        dy[i] = dyr[i] = 10000000000000;
        dz[i] = dzr[i] = 10000000000000;
    }
    ll x, y, z;
    cin >> x >> y >> z;
    di(x, 0);
    di(y, 1);
    di(z, 2);
    dir(x, 3);
    dir(y, 4);
    dir(z, 5);

    ll ans = 10000000000000, node;


    for (int i = 1; i <= n; i++) {
        if (dx[i] + dy[i] + dzr[i] < ans || (dx[i] + dy[i] + dzr[i] == ans && z < node)) {
            ans = dx[i] + dy[i] + dzr[i];
            node = z;
        }
        if (dx[i] + dyr[i] + dz[i] < ans || (dx[i] + dyr[i] + dz[i] == ans && y < node)) {
            ans = dx[i] + dyr[i] + dz[i];
            node = y;
        }
        if (dxr[i] + dy[i] + dz[i] < ans || (dxr[i] + dy[i] + dz[i] == ans && x < node)) {
            ans = dxr[i] + dy[i] + dz[i];
            node = x;
        }
    }

    if (ans == 10000000000000) {
        cout << -1;
    } else
        cout << node << ' ' << ans;
}

//XD

int main() {
    Achilles
    int tt = 1;
//    cin >> tt;
    while (tt--) Achilles1();
}
