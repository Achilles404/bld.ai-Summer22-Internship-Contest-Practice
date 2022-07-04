#include <bits/stdc++.h>

using namespace std;
#define Achilles ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ull unsigned long long
#define ll long long
#define pp push_back
#define M 1000000007
const int N = 100005;
const int INF = 1000000;
ll n, h;
ll a[N];

bool f(ll x) {
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (a[i] + (x - 1)) / x;
    }
    return sum <= h;
}

void Achilles1() {
    cin >> n >> h;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll l = 1, r = 1000000000000, mid, ans;
    while (l <= r) {
        mid = (l + r) / 2;
        if (f(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
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
