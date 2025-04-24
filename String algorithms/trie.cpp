struct node {
    map<char, int> go;
    int term;
    node() {};
};

node trie[N];
int sz = 0;

int new_node() {
    trie[sz].go.clear();
    trie[sz].term = -1;
    return sz++;
}

void add_string(string s, int i) {
    int cur = 0;
    for (char c : s) {
        if (! trie[cur].go.count(c)) {
            trie[cur].go[c] = new_node();
        }
        cur = trie[cur].go[c];
    }
    trie[cur].term = i;
}

int find(string t) {
    int cur = 0;
    for (char c : t) {
        if (! trie[cur].go.count(c)) return -1;
        cur = trie[cur].go[c];
    }
    return trie[cur].term;
}
