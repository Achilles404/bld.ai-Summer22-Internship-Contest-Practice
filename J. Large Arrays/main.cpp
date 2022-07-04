#include <bits/stdc++.h>

using namespace std;
#define Achilles ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ull unsigned long long
#define ll long long
#define pp push_back
#define M 1000000007
const int N = 100005;
const int INF = 1000000;

void Achilles1() {
    ll n, m, x, y;
    cin >> n >> x >> m >> y;
    ll tar, l, r, prev, mid;

    if ((n + m) & 1) {
        ll ans = 0;
        l = 0, r = 1e18, tar = (n + m + 1) / 2;
        while (l <= r) {
            mid = (l + r) / 2;
            prev = min(mid / x, n) + min(mid / y, m);
            if (prev >= tar) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << setprecision(1) << fixed << (ans * 1.0) << '\n';
    } else {

        ll ans1 = 0;
        tar = (n + m + 1) / 2, l = 0, r = 1e18;
        while (l <= r) {
            mid = (l + r) / 2;
            prev = min(mid / x, n) + min(mid / y, m);
            if (prev >= tar) ans1 = mid, r = mid - 1;
            else l = mid + 1;
        }

        tar++;
        l = 0, r = 1e18;
        ll ans2 = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            prev = min(mid / x, n) + min(mid / y, m);
            if (prev >= tar) ans2 = mid, r = mid - 1;
            else l = mid + 1;
        }

        cout << setprecision(1) << fixed << (ans1 + ans2) / 2.0 << '\n';
    }
}

//XD

int main() {
    Achilles
// #ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
// #endif
    int tt = 1;
//    cin >> tt;
    while (tt--) Achilles1();
}
