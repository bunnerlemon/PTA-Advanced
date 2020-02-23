#include <bits/stdc++.h>
using namespace std;
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)
const int maxn = 35;
int n;
int post[maxn], in[maxn];
vector<int> p[maxn];

void process(int post_l, int post_r, int in_l, int in_r, int fa) {
    if(post_l > post_r) return ;
    int root = post[post_r];
    if(fa != -1) {
        p[fa].push_back(root);
    }
    int pos;
    for(pos = in_l; pos <= in_r; pos++) if(in[pos] == root) break;
    int left_len = pos - in_l, right_len = in_r - pos;
    process(post_l, post_l + left_len - 1, in_l, pos - 1, root);
    process(post_r - right_len, post_r - 1, pos + 1, in_r, root);
}

vector<int> level_traversal(int root) {
    queue<int> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for(int i = 0; i < p[x].size(); i++) {
            q.push(p[x][i]);
        }
    }
    return ans;
}

int main() {
    // fin;
    // fout;
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> post[i];
    for(int i = 0; i < n; i++) cin >> in[i];
    process(0, n - 1, 0, n - 1, -1);
    vector<int> level_traverse = level_traversal(post[n-1]);
    for(int i = 0; i < level_traverse.size(); i++) {
        if(i) cout << " " << level_traverse[i];
        else cout << level_traverse[i];
    }
    cout << endl;
    return 0;
}