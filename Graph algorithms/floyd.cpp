for (int i = 0; i < n; i++) {
    for (int v = 0; v < n; v++) {
        for (int u = 0; u < n; u++) {
            d[u][v] = min(d[u][v], d[u][i] + d[i][v]);
        }
    }
}
