#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 18) - 1;
struct Change {
    int t, x, y;
    Change(int t, int x, int y):t(t),x(x),y(y){}
};

vector<Change> vec[maxn];
int a[maxn], seg[maxn * 2 + 20][101];

void printAll(int n) {
    for (int i = 1; i <= n; i++) printf("%d%c", seg[1][i], " \n"[i == n]);
}

void update(int t, int x, int y) {
    seg[t += maxn][x] = y;
    for (t >>= 1; t; t >>= 1) {
        int chl = t << 1, chr = chl | 1;
        for (int i = 1; i <= 100; i++) {
            seg[t][i] = seg[chr][seg[chl][i]];
        }
    }
}


void init() {
    for (int t = 1; t < maxn * 2 + 20; t++)
    for (int i = 1; i <= 100; i++)
        seg[t][i] = i;
}


int main() {
    int n = get(), q;
    for (int i = 1; i <= n; i++) a[i] = get();
    q = get();
    for (int t = 1; t <= q; t++) {
        int l = get(), r = get(), x = get(), y = get();
        if (x != y) {
            vec[l].push_back(Change(t, x, y));
            vec[r + 1].push_back(Change(t, x, x));
        }
    }
    init();

    for (int i = 1; i <= n; i++) {
        for (auto cg: vec[i]) update(cg.t, cg.x, cg.y);
        printf("%d%c", seg[1][a[i]], " \n"[i == n]);
    }

}

