#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> d(n+1);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        sum += d[i];
    }

    if (sum != 2LL * (n - 1)) {
        cout << "BRAK\n";
        return 0;
    }

    queue<int> internal;
    priority_queue<int, vector<int>, greater<int>> leaf;

    for (int i = 1; i <= n; i++) {
        if (d[i] == 1) leaf.push(i);
        else if (d[i] > 1) internal.push(i);
    }

    vector<pair<int,int>> edges;

    for (int i = 0; i < n-2; i++) {
        if (leaf.empty() || internal.empty()) {
            cout << "BRAK\n";
            return 0;
        }
        int u = leaf.top(); leaf.pop();
        int v = internal.front(); internal.pop();

        edges.push_back({u, v});
        if (--d[v] == 1) leaf.push(v);
        else internal.push(v);
    }

    // 마지막 두 leaf 연결
    int u = leaf.top(); leaf.pop();
    int v = leaf.top(); leaf.pop();
    edges.push_back({u, v});

    for (auto [a,b]: edges) {
        cout << a << " " << b << "\n";
    }
}
