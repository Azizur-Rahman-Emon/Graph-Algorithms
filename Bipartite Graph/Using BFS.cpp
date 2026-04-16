#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int color[N]; // -1 = not visited, 0/1 = two colors

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

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

    int answer = 0;

    for (int i = 1; i <= n; i++) {
        if (color[i] != -1) continue;

        queue<int> q;
        q.push(i);
        color[i] = 0;

        int cnt0 = 1, cnt1 = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;

                    if (color[v] == 0) cnt0++;
                    else cnt1++;

                    q.push(v);
                }
            }
        }

        answer += max(cnt0, cnt1);
    }

    cout << answer << '\n';
}
