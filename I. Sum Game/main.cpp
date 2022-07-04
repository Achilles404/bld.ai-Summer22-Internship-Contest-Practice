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
    ll a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    b = b * (b + 1) / 2;
    a--;
    a = a * (a + 1) / 2;
    b -= a;
    if (b & 1) {
        cout << "Hoss";
    } else {
        cout << "Nasser";
    }
}

//XD

int main() {
    Achilles
    int tt = 1;
//    cin >> tt;
    while (tt--) Achilles1();
}
