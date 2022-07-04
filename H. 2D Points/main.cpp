#include <bits/stdc++.h>

using namespace std;
#define Achilles ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ull unsigned long long
#define ll long long
#define pii pair<int,int>
#define pp push_back
#define M 1000000007
const int N = 100005;
const int INF = 1000000;

ll RMQ[N][22], lg[N];

void pw() {
    lg[1] = 0;
    for (int i = 2; i < N; ++i) {
        lg[i] = lg[i / 2] + 1;
    }
}

ll query(ll l, ll r) {
    ll pwr = lg[r - l + 1];
    return max(RMQ[l][pwr], RMQ[r - (1 << pwr) + 1][pwr]);
}

void process(ll n) {
    for (int j = 1; j < 22; ++j)
        for (int i = 0; i + (1 << j) - 1 < n; ++i)
            RMQ[i][j] = max(RMQ[i][j - 1], RMQ[i + (1 << (j - 1))][j - 1]);
}


void Achilles1() {
    int n, k;
    cin >> n >> k;
    vector<int> v1(n);
    vector<int> v2(n);
    for (int i = 0; i < n; ++i) {
        cin >> v1[i] >> v2[i];
        RMQ[i][0] = v2[i] + v1[i];
    }
    pw();
    process(n);
    ll ans = -1;
    for (int i = 0; i < n; ++i) {
        auto x = upper_bound(v1.begin(), v1.end(), k + v1[i]) - v1.begin();
        x--;
        if (x - v1[i] <= k && x != i) {
            ans = max(ans, query(i + 1, x) + (v2[i] - v1[i]));
        }
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
