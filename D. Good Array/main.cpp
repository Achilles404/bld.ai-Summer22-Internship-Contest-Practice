#include <bits/stdc++.h>

using namespace std;
#define Achilles ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pp push_back
const int N = 100005;

void Achilles1() {
    ll n, x;
    cin >> n;
    stack<ll> s;
    for (ll i = 0; i < n; ++i) {
        cin >> x;
        if (s.empty()) {
            s.push(x);
        } else {
            if (s.top() == x) {
                s.pop();
            } else {
                s.push(x);
            }
        }
    }
    vector<ll> ans;
    while (!s.empty()) {
        ans.pp(s.top());
        s.pop();
    }
    cout << (int) ans.size() << '\n';
    for (int i = (int) ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << ' ';
    }
}

//XD

int main() {
    Achilles
    int tt = 1;
//    cin >> tt;
    while (tt--) Achilles1();
}
