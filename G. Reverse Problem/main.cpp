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

struct Node {
    string val;
    int inDeg = 0;
    int outDeg = 0;
    vector<Node *> neighbours = {};

    Node(string &a) : val(a) {}
};


void DFS(Node *node, vector<char> &path) {
    while (node != nullptr && node->outDeg != 0) {
        auto neighbour = node->neighbours[--node->outDeg];
        DFS(neighbour, path);
    }
    if (node != nullptr) {
        path.push_back(node->val[1]);
    }
}


vector<char> Euler(vector<Node *> &nodes, int edges) {
    int st = 0, en = 0;
    for (auto &node: nodes) {
        if (node == nullptr)continue;
        if (abs(node->outDeg - node->inDeg) > 1) return {};
        if (node->outDeg - node->inDeg == 1) st++;
        else if (node->inDeg - node->outDeg == 1) en++;
    }

    if (!((st == 0 && en == 0) || (st == 1 && en == 1))) return {};

    vector<char> path;
    for (auto &node: nodes) {
        if (node == nullptr)continue;
        if ((st == 0 && node->outDeg > 0) || (st == 1 && node->outDeg - node->inDeg == 1)) {
            DFS(node, path);
            path.push_back(node->val[0]);
            break;
        }
    }

    if (path.size() != edges + 2) return {};
    reverse(path.begin(), path.end());
    return path;
}

int id;


void Achilles1() {
    int n;
    cin >> n;
    vector<string> s(n - 2);
    vector<Node *> nodes(4 * n);
    map<string, int> idx;
    for (int i = 0; i < n - 2; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n - 2; i++) {
        string pref;
        pref += s[i][0];
        pref += s[i][1];
        string suf;
        suf += s[i][1];
        suf += s[i][2];
        if (pref == suf) {
            Node *cur;
            if (idx.find(pref) == idx.end()) {
                idx[pref] = id++;
                cur = new Node(pref);
            } else {
                cur = nodes[idx[pref]];
            }
            cur->outDeg++;
            cur->inDeg++;
            cur->neighbours.push_back(cur);
            nodes[idx[pref]] = cur;
        } else {
            Node *prN;
            Node *sufN;
            if (idx.find(pref) == idx.end()) {
                idx[pref] = id++;
                prN = new Node(pref);
            } else {
                prN = nodes[idx[pref]];
            }
            if (idx.find(suf) == idx.end()) {
                idx[suf] = id++;
                sufN = new Node(suf);
            } else {
                sufN = nodes[idx[suf]];
            }
            prN->outDeg++;
            sufN->inDeg++;
            prN->neighbours.push_back(sufN);
            nodes[idx[pref]] = prN;
            nodes[idx[suf]] = sufN;
        }
    }
    auto path = Euler(nodes, n - 2);
    if (!path.empty()) {
        cout << "YES\n";
        for (auto &ch: path) cout << ch;
        cout << '\n';
    } else
        cout << "NO\n";
}

//XD

int main() {
    Achilles
    int tt = 1;
//    cin >> tt;
    while (tt--) Achilles1();
}
