#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int color[N]; // -1 = not visited

bool dfs(int u, int c) {
    color[u] = c;

    for (auto v : adj[u]) {
        if (color[v] == -1) {
            if (!dfs(v, c ^ 1)) return false;
        }
        else {
            if (color[v] == color[u]) return false; // conflict
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        color[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ok = true;

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            if (!dfs(i, 0)) {
                ok = false;
                break;
            }
        }
    }

    if (ok) cout << "Bipartite\n";
    else cout << "Not Bipartite\n";
}
