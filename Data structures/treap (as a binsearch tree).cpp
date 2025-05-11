ptt split(treap t, int x) {
    if (! t) return {t, t};
    if (t->x < x) {
        ptt p = split(t->r, x);
        t->r = p.first;
        return {fix(t), p.second};
    }
    else {
        ptt p = split(t->l, x);
        t->l = p.second;
        return {p.first, fix(t)};
    }
}
treap insert(treap t, int x) {
    ptt p = split(t, x);
    treap q = createNode(x);
    return merge(p.first, merge(q, p.second));
}
li sumltX(treap t, int x) {
    if (! t) return 0ll;
    if (t->x < x) return t->x + getSum(t->l) + sumltX(t->r, x);
    else return sumltX(t->l, x);
}
bool contains(treap t, int x) {
    if (! t) return false;
    if (t->x == x) return true;
    if (t->x > x) return contains(t->l, x);
    else return contains(t->r, x);
}
