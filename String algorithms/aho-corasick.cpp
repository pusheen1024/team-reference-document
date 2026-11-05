int go[N][A];
int suflink[N];
int p[N];
char pch[N];

void aho_corasick(int root) {
    suflink[root] = root;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < A; i++)
            if (next_node[u][i] != -1) {
                int v = next_node[u][i];
                p[v] = u;
                pch[v] = i;
                if (u == root) suflink[v] = root;
                else suflink[v] = go[suflink[u]][i];
                q.push(v);
                go[u][i] = v;
            }
            else if (u == root) go[u][i] = root;
            else go[u][i] = go[suflink[u]][i];
    }
}
