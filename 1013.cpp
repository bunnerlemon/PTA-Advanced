#include <bits/stdc++.h>
using namespace std;
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)
const int maxn = 1005;
vector<int> mp[maxn];
set<int> ans;
int f[maxn];

int _find(int x) {
    return x == f[x] ? x : _find(f[x]);
}

void join(int x, int y) {
    int u = _find(x), v = _find(y);
    if(u != v) {
        if(u > v) f[u] = v;
        else f[v] = u;
    }
}

int main() {
    fin;
    //fout;
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        mp[from].push_back(to);
        mp[to].push_back(from);
    }
    int occur;
    while(k--) {
        cin >> occur;
        ans.clear();
        for(int i = 0; i < maxn; i++) f[i] = i;
        f[occur] = 0;
        for(int i = 1; i <= n; i++) {
            if(i == occur) continue;
            for(int j = 0; j < mp[i].size(); j++) {
                if(mp[i][j] == occur) continue;
                join(i, mp[i][j]);
            }
        }
        for(int i = 1; i <= n; i++) {
            if(i == occur) continue;
            ans.insert(_find(i));
        }
        cout << ans.size() - 1 << endl;
    }
    return 0;
}