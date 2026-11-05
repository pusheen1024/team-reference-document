using key = pair<ll, int>;
mt19937_64 mt;
uniform_int_distribution<ll> key_distribution(0, (ll)(1e18));

struct node {
    key x;
    ll y;
    node *left, *right;
    int leaf;
    ll sum;
    int subtree;
};
const node NONE = {{-1, -1}, -1, NULL, NULL, 0, 0, 0};

node get_node(const node *t) {
    if (t == NULL) return NONE;
    return *t;
}
const int M = 1e7;
node buffer[M];
int sz;

node* create_node(int index, bool leaf, ll key) {
    node *t = &buffer[sz++];
    t->x = {key, index};
    t->y = key_distribution(mt);
    t->left = t->right = NULL;
    t->leaf = leaf;
    t->sum = key;
    t->subtree = leaf;
    return t;
}
void recalc(node *t) {
    if (t == NULL) return;
    node a = get_node(t->left), b = get_node(t->right);
    t->sum = t->x.first + a.sum + b.sum;
    t->subtree = t->leaf + a.subtree + b.subtree;
}

pair<node*, node*> split(node *t, key k) {
    if (t == NULL)
        return {NULL, NULL};
    if (k >= t->x) {
        auto [t1, t2] = split(t->left, k);
        t->left = t2;
        recalc(t);
        return {t1, t};
    }
    else {
        auto [t1, t2] = split(t->right, k);
        t->right = t1;
        recalc(t);
        return {t, t2};
    }
}
pair<node*, node*> split(node *t, int to_left) {
    if (t == NULL)
        return {NULL, NULL};
    int x = get_node(t->left).subtree;
    if (to_left <= x) {
        auto [t1, t2] = split(t->left, to_left);
        t->left = t2;
        recalc(t);
        return {t1, t};
    }
    else {
        auto [t1, t2] = split(t->right, to_left - x - 1);
        t->right = t1;
        recalc(t);
        return {t, t2};
    }
}
node* merge(node *t1, node *t2) {
    if (t1 == NULL) return t2;
    if (t2 == NULL) return t1;
    if (t1->y > t2->y) {
        t1->right = merge(t1->right, t2);
        recalc(t1);
        return t1;
    }
    else {
        t2->left = merge(t1, t2->left);
        recalc(t2);
        return t2;
    }
}

node* unite(node *t1, node *t2) {
    if (t1 == NULL) return t2;
    if (t2 == NULL) return t1;
    if (t1->y < t2->y) swap(t1, t2);
    auto [t2l, t2r] = split(t2, t1->x);
    t1->left = unite(t1->left, t2l);
    t1->right = unite(t1->right, t2r);
    recalc(t1);
    return t1;
}
