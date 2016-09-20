#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double EPS = 1e-8;

int sgn(double x) {
    return x < -EPS ? -1 : x > EPS;
}

double timeLine;
struct Circle {
    double x, y, r;
    void read() {
        scanf("%lf%lf%lf", &x, &y, &r);
    }
    double getY(int up) {
        return y + up * (sqrt(r * r - (x - timeLine) * (x - timeLine)));
    }
} c[N];

typedef pair<double, int> Event; //x
Event e[N << 1];

struct Node {
    int id, d;
    bool operator<(const Node& r) const {
        double y1 = c[id].getY(d), y2 = c[r.id].getY(r.d); //y
        return sgn(y1 - y2) ? y1 < y2 : d < r.d;
    }
};

int n, dep[N], p[N];
vector<int> G[N];

int dfs(int u) {
    int sg = 0;
    for(int v : G[u]) sg ^= dfs(v) + 1;
    return sg;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i) {
            c[i].read();
            e[2 * i - 1] = {c[i].x - c[i].r, i};
            e[2 * i] = {c[i].x + c[i].r, -i};
        }
        sort(e + 1, e + 2 * n + 1);

        set<Node> s;
        memset(dep, 0, sizeof dep);
        for(int i = 1; i <= 2 * n; ++i) {
            timeLine = e[i].first;
            int id = e[i].second;

            if(id < 0) {
                s.erase({ -id, 1});
                s.erase({ -id, -1});
                continue;
            }

            auto up = s.lower_bound({id, 1}), dw = up;
            if(up == s.end() || dw == s.begin()) {
                p[id] = 0;
                dep[id] = 1;
                G[0].push_back(id);
            } else if((--dw)->id == up->id) {
                p[id] = dw->id;
                dep[id] = dep[dw->id] + 1;
                G[dw->id].push_back(id);
            } else {
                if(dep[dw->id] == dep[up->id]) {
                    p[id] = p[dw->id];
                    dep[id] = dep[dw->id];
                    G[p[dw->id]].push_back(id);
                } else {
                    if(dep[dw->id] > dep[up->id]) swap(up, dw);
                    p[id] = dw->id;
                    dep[id] = dep[dw->id] + 1;
                    G[dw->id].push_back(id);
                }
            }

            s.insert({id, 1});
            s.insert({id, -1});
        }

//      for(int i = 1; i <= n; ++i) printf("%d->%d\n", p[i], i);

        puts(dfs(0) ? "Alice" : "Bob");
    }
    return 0;
}
/*
HDU 5299 Circles Game (圆的扫描线、树上sg)

平面上有N≤5×104个两两不交的圆，现在有两个人轮流选取圆。
每选到一个圆就要把这个圆及其内部的所有圆都删去，最后不能操作的人输。
问谁有必胜策略。
*/
