int getVertex(int x) {
    if (x > 0) return (x - 1) * 2;
    if (x < 0) return (abs(x) - 1) * 2 + 1;
}

void addEdge(int x, int y) {
    g[x].push_back(y);
    gt[y].push_back(x);
}

void addOR(int x, int y) {
    int vx = getVertex(x);
    int vy = getVertex(y);
    addEdge(vx ^ 1, vy);
    addEdge(vy ^ 1, vx);
}

int variable(int x) {
     return (x / 2 + 1) * (x % 2 == 0 ? 1 : -1);
}

pair<bool, vector<int>> twoSAT(int n, vector<pair<int, int>> ORs) v{
    int m = ORs.size();
    int V = 2 * n;
    for (int i = 0; i < V; i++) {
        g[i].clear();
        gt[i].clear();
    }
    for (int i = 0; i < m; i++) {
        int x = ORs[i].first;
        int y = ORs[i].second;
        addOR(x, y);
    }
    vector<int> comps = SCC(V);
    bool ans = true;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int v1 = i * 2;
        int v0 = i * 2 + 1;
        if (comp[v1] == comp[v0])
            ans = false;
        else if (comp[v1] > comp[v0])
            res.push_back(variable(v1));
        else
            res.push_back(variable(v0));
    }
    return make_pair(ans, res);
}
