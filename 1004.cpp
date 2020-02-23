#include <bits/stdc++.h>
#define fin freopen("in.txt", "r", stdin)
using namespace std;
typedef long long ll;
const int maxn = 1005;
vector<int> p[maxn];   //����
int ans[maxn];         //ans[i]��ʾ��i���Ҷ�ӽڵ���
struct node {
    int level, id;
    node(int x, int y) : level(x), id(y) {}
};
int main() {
    fin;
    int n, m, id, x, k, max_level = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> id >> k;
        for(int j = 0; j < k; j++) { cin >> x; p[id].push_back(x); }
    }
    queue<node> Q;
    Q.push(node(0, 1));
    while(!Q.empty()) {
        node xx = Q.front();
        Q.pop();
        max_level = max(max_level, xx.level);                 //��������
        if((int) p[xx.id].size() == 0) ans[xx.level]++;       //����ýڵ���Ҷ�ӽڵ㣬��ò��Ҷ�ӽڵ���+1
        for(int i = 0; i < (int) p[xx.id].size(); i++) { 
            Q.push(node(xx.level + 1, p[xx.id][i]));
        }
    }
    for(int i = 0; i <= max_level; i++) if(i) cout << " " << ans[i]; else cout << ans[i];
    puts("");
    return 0;
}