bool used[N];
int mt[N], mt_left[N];
vector<int> g[N];

bool kuhn(int x) {
    if (used[x]) return false;
    used[x] = true;
    for (auto y : g[x])
        if (mt[y] == -1) {
            mt[y] = x;
            mt_left[x] = y;
            return true;
        }
    for (auto y : g[x])
        if (kuhn(mt[y])) {
            mt[y] = x;
            mt_left[x] = y;
            return true;
        }
    return false;
}

void max_matching() {
    for (int i = 0; i < n1; i++)
        mt_left[i] = -1;
    for (int i = 0; i < n2; i++)
        mt[i] = -1;
    while (true) {
        bool changed = false;
        for (int i = 0; i < n1; i++)
            used[i] = false;
        for (int i = 0; i < n1; i++)
            if (mt_left[i] == -1)
                changed |= kuhn(i);
        if (! changed)
            break;
    }
}
