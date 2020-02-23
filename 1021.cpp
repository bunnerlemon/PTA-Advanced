#include <bits/stdc++.h>
using namespace std;
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)
const int maxn = 1e4+5;
const int inf = 0x3fffffff;
vector<int> graph[maxn];
int n;
int len = 0;
bool vis[maxn];
//深搜求最远节点
void dfs_longest_node(int root, int cur_len, set<int> &root_node) {
    if(cur_len > len) {
        //最长长度更新
        root_node.clear();
        root_node.insert(root);
        len = cur_len;
    }
    else if(cur_len == len) {
        //长度相等入集合
        root_node.insert(root);
    }
    for(int i = 0; i < (int)graph[root].size(); i++) {
        if(!vis[graph[root][i]]) {
            vis[graph[root][i]] = true;
            dfs_longest_node(graph[root][i], cur_len + 1, root_node);
            vis[graph[root][i]] = false;
        }
    }
}
void bfs(int root) {
    queue<int> q;
    vis[root] = true;
    q.push(root);
    int countx = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        countx++;
        for(int i = 0; i < (int)graph[x].size(); i++) {
            if(!vis[graph[x][i]]) q.push(graph[x][i]), vis[graph[x][i]] = true;
        }
    }
}
int main() {
    // fin;
    // fout;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //计算连通块数量
    int countx = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) bfs(i), countx++;
    }
    //连通块不止1个的情况
    if(countx != 1) {
        cout << "Error: " << countx << " components" << endl;
        return 0;
    }
    memset(vis, false, sizeof(vis));
    set<int> root_node1;    //最终所求节点集合
    //深搜第一遍求离节点1最远的所有节点
    vis[1] = true;
    dfs_longest_node(1, 0, root_node1);
    vis[1] = false;
    //cout << len << endl;
    for(set<int>::iterator iter = root_node1.begin(); iter != root_node1.end(); iter++) {
        //在这里利用求得的第一个节点求相应的最远节点
        //在这里有一个结论：到节点1最远的所有节点，再计算到这些节点最远的节点时，都是一样的，
        //即每个节点(计算出来的距离节点1最远的节点)计算出来的最远节点都是相同的
        //所以这里只需要计算一个就可以，亲测，全部计算会超时
        set<int> root_node2;
        vis[*iter] = true;
        dfs_longest_node(*iter, 0, root_node2);
        vis[*iter] = false;
        for(set<int>::iterator it = root_node2.begin(); it != root_node2.end(); it++) {
            root_node1.insert(*it);
        }
        break;
    }
    for(set<int>::iterator iter = root_node1.begin(); iter != root_node1.end(); iter++) {
        cout << *iter << endl;
    }
    return 0;
}