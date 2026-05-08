// Solution to https://atcoder.jp/contests/abc456/tasks/abc456_e
#include <string>
#include <vector>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

struct walk {
    int ic, nc, nd;
};

walk make_walk(int ic, int nc, int nd) {
    walk temp = { ic, nc, nd };
    return temp;
}

int main() {
    int t, n, m, i, j, u, v, temp, w;
    cin >> t;
    vector<string> h;
    stack<walk> vis;
    string hi;
    bool ans;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> g(n, vector<int>());
        vector<unordered_set<int>> gw(n, unordered_set<int>());
        for (i = 0; i < m; i++) {
            cin >> u >> v;
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }
        for (i = 0; i < n; i++)
            g[i].push_back(i);
        cin >> w;
        for (i = 0; i < n; i++) {
            cin >> hi;
            if (hi[0] == 'o')
                vis.push(make_walk(i, i, 1));
            h.push_back(hi);
        }
        while (!vis.empty()) {
            int ic = vis.top().ic;
            int nc = vis.top().nc;
            int nd = vis.top().nd;
            vis.pop();
            if (nd > w) {
               gw[ic].insert(nc);
            }
            else {
                for (j = 0; j < g[nc].size(); j++)
                    if (h[g[nc][j]][nd % w] == 'o')
                        vis.push(make_walk(ic, g[nc][j], nd + 1));
            }
        }
        for (i = 0; i < n; i++)
            g[i].clear();
        g.clear();
        ans = false;
        unordered_set<int> ec;
        vector<unordered_set<int>> rin(n, unordered_set<int>());
        for (i = 0; i < gw.size(); i++)
            for (int des : gw[i])
                rin[des].insert(i);
        unordered_set<int> new_orphan;
        for (i = 0; i < n; i++)
            if(gw[i].size() == 0)
                ec.insert(i);
        while(!ec.empty()) {
            for (int src : ec) {
                for (int des : rin[src]) {
                    if (gw[des].erase(src) > 0 && gw[des].size() == 0)
                        new_orphan.insert(des);
                }
                rin[src].clear();
            }
            ec.clear();
            for (int src : new_orphan)
                ec.insert(src);
            new_orphan.clear();
        }
        ans = false;
        for (i = 0; i < n; i++)
            if (gw[i].size() > 0) {
                ans = true;
                break;
            }
        cout << (ans ? "Yes" : "No") << endl;
        h.clear();
    }
}