struct minS {
    stack<ptt> st;
    bool empty() {
        return st.empty();
    }
    int get() {
        if (st.empty()) return 0;
        return st.top().second;
    }
    void push(int x) {
        st.push({ x, min(x, get())});
    }
    int pop() {
        if (st.empty()) return 0;
        int x = st.top().first;
        st.pop();
        return x;
    }
};

struct minQ {
  min head;
  xorS tail;

  void fix() {
    if (head.empty()) {
      while (!tail.empty()) head.push(tail.pop());
    }
  }

  void push(int x) {
    tail.push(x);
  }

  void pop() {
    fix();
    if (!head.empty())
      head.pop();
  }

  int get() {
    return (tail.get() | head.get());
  }
};

struct venS {
  set<li> s;
  li d;
  venS() {
    d = 0;
  }
  void insert(int x) {
    s.insert(x - d);
  }
  void erase(int x) {
    s.erase(x - d);
  }
  bool check(int x) {
    return (s.find(x - d) != s.end());
  }
  void inc(int y) {
    d += y;
  }
};
