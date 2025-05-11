mt19937 rnd(time(NULL));
struct Node {
    int x;
    int y;
    int sz;
    bool rev;
    Node* l;
    Node* r;
    Node() {};
};
typedef Node* treap;
typedef pair<treap, treap> ptt;

treap newNode(int x, int y, int sz, Node* l, Node* r) {
    treap t = new Node();
    t->x = x;
    t->y = y;
    t->sz = sz;
    t->rev = 0;
    t->l = l;
    t->r = r;
    return t;
}
treap createNode(int x) {
    return newNode(x, rnd(), 1, NULL, NULL);
}
int getSize(treap t) {
    if (! t) return 0;
    return t->sz;
}
treap fix (treap t) {
    if (t) t->sz = 1 + getSize(t->l) + getSize(t->r);
    return t;
}
treap rev(treap t) {
    if (t) t->rev ^= 1;
    return t;
}
treap push(treap t) {
    if (! t) return t;
    if (t->rev) {
        t->l = rev(t->l);
        t->r = rev(t->r);
        swap(t->l, t->r);
        t->rev = 0;
    }
    return fix(t);
}
treap merge(treap a, treap b) {
    if (! a) return b;
    if (! b) return a;
    a = push(a);
    b = push(b);
    if (a->y > b->y) {
        a->r = merge(a->r, b);
        return fix(a);
    }
    else {
        b->l = merge(a, b->l);
        return fix(b);
    }
}
ptt splitK(treap t, int k) {
    if (getSize(t) <= k) return {t, NULL};
    if (k == 0) return {NULL, t};
    t = push(t);
    int szl = getSize(t->l);
    if (szl < k) {
        ptt p = splitK(t->r, k - szl - 1);
        t->r = p.first;
        return {fix(t), p.second};
    }
    else {
        ptt p = splitK(t->l, k);
        t->l = p.second;
        return {p.first, fix(t)};
    }
}
treap revSeg(treap t, int l, int r) {
    ptt p = splitK(t, l);
    ptt q = splitK(p.second, r - l);
    q.first = rev(q.first);
    t = merge(p.first, merge(q.first, q.second));
    return fix(t);
}
treap shift(treap t, int l, int r) {
    ptt p = splitK(t, l);
    ptt q = splitK(p.second, r - l);
    treap seg = q.first;
    ptt s = splitK(seg, getSize(seg) - 1);
    seg = merge(s.second, s.first);
    t = merge(merge(p.first, seg), q.second);
    return fix(t);
}
treap createfromVector(const vector<int> &a) {
    treap t = NULL;
    for (auto x: a) t = merge(t, createNode(x));
    return t;
}
void getVector(treap t, vector<int> &a) {
    if (! t) return;
    t = push(t);
    getVector(t->l, a);
    a.push_back(t->x);
    getVector(t->r, a);
}
