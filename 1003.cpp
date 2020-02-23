#include <bits/stdc++.h>
#define fin freopen("in.txt", "r", stdin)
using namespace std;
typedef long long ll;
const int maxn = 5e2+5;
struct node {
    int t, l;   //team, length
    node(int x, int y) : t(x), l(y) {}

};

struct P {
    int t, l;    //target, length
    P(int x, int y) : t(x), l(y) {}
};

bool v[maxn];

int ans_road = 0, ans_team = 0;
vector<node> road;    //存结果，这时候结构体里是：t:num_team, l: length
int s, e;             //起始点、目标点
vector<node> p[maxn]; //存图，这时候结构体里是：t: target, l: length
int team[maxn];

void dfs(int cur, int t, int len) {
    if(cur == e) {
        road.push_back(node(t, len));
        return ;
    }
    for(int i = 0; i < p[cur].size(); i++) {
        if(!v[p[cur][i].t]) {
            v[p[cur][i].t] = true;
            dfs(p[cur][i].t, t + team[p[cur][i].t], len + p[cur][i].l);
            v[p[cur][i].t] = false;
        }
    }
} 

void output() {
    int min_road = 10000000;
    for(int i = 0; i < road.size(); i++) min_road = min(min_road, road[i].l);
    for(int i = 0; i < road.size(); i++) if(road[i].l == min_road) ans_road++, ans_team = max(ans_team, road[i].t);
    cout << ans_road << " " << ans_team << "\n";
}

int main() {
    fin;
    int n, m;
    cin >> n >> m >> s >> e;
    for(int i = 0; i < n; i++) cin >> team[i];
    for(int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        p[u].push_back(node(v, l)), p[v].push_back(node(u, l));
    }
    dfs(s, team[s], 0);
    output();
    return 0;
}