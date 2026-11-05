struct node {
    node *l, *r;
    rect value;
    node() : l(0), r(0), value() {};
    node(rect x) : l(0), r(0), value(x) {};
    node(node *l, node *r);
};
rect get_value(node *t) {
    if (!t) return rect();
    else return t->value;
}
node::node(node *l, node *r) {
    this->l = l;
    this->r = r;
    this->value = merge(get_value(l), get_value(r));
}
const int N = 1e5;
const int M = 1e7;
node buffer[M];
int counter = 0;

node* get_node(node x) {
    buffer[counter] = x;
    return &buffer[counter++];
}
node* build(int tl, int dr) {
    if (tl == dr)
        return get_node(node());
    else {
        int mid = (tl + dr) / 2;
        return get_node(node(build(tl, mid), build(mid+1, dr)));
    }
}
node* update(int i, rect value, node *t, int tl, int dr) {
    if (tl == dr)
        return get_node(node(value));
    else {
        int mid = (tl + dr) / 2;
        if (i <= mid) return get_node(node(update(i, value, t->l, tl, mid), t->r));
        else return get_node(node(t->l, update(i, value, t->r, mid+1, dr)));
    }
}
rect get(int l, int r, node *t, int tl, int dr) {
    if (l > r)
        return rect();
    if (l == tl && r == dr)
        return t->value;

    int mid = (tl + dr) / 2;
    rect value = rect();
    assert(t->l);
    assert(t->r);
    value = merge(value, get(l, min(mid, r), t->l, tl, mid));
    value = merge(value, get(max(l, mid+1), r, t->r, mid+1, dr));
    return value;
}
