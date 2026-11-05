int gcdex(int a, int b, int &x, int &y) {
    if (a < b)
        return gcdex(b, a, y, x);
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x0, y0;
    int d = gcdex(b, a % b, x0, y0);
    x = y0;
    y = x0 - (a / b) * y0;
    return d;
}
