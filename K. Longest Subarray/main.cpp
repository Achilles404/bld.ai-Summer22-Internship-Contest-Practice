#include <bits/stdc++.h>

using namespace std;
#define Achilles ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ull unsigned long long
#define ll long long
#define pp push_back
#define M 1000000007
const int N = 100005;
const int INF = 1000000;

int arr[N], n, k;

int lenOfLongSubarr() {

    unordered_map<int, int> um;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == k) maxLen = i + 1;
        if (um.find(sum) == um.end()) um[sum] = i;

        if (um.find(sum - k) != um.end()) {
            if (maxLen < (i - um[sum - k]))
                maxLen = i - um[sum - k];
        }
    }

    return maxLen;
}

void Achilles1() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << lenOfLongSubarr();
}

//XD

int main() {
    Achilles
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int tt = 1;
//    cin >> tt;
    while (tt--) Achilles1();
}
