#include <bits/stdc++.h>
using namespace std;
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)
const int maxn = 105;
struct node {
    string id;
    int score;
    int list_id;
    bool operator < (const node & b) {
        if(score == b.score) return id < b.id;
        else return score > b.score;
    }
};
vector<node> p[maxn];
int index_list[maxn];
int rank_list[maxn];
int n, m;
int choose() {
    int id = -1, max_score;
    string testee;
    for(int i = 1; i <= n; i++) {
        if(index_list[i] >= (int)p[i].size()) continue;
        if(id == -1) {
            id = i, testee = p[i][index_list[i]].id, max_score = p[i][index_list[i]].score;
            continue;
        }
        if(p[i][index_list[i]].score > max_score) max_score = p[i][index_list[i]].score, id = i, testee = p[i][index_list[i]].id;
        else if(p[i][index_list[i]].score == max_score && p[i][index_list[i]].id < testee) {
            testee = p[i][index_list[i]].id;
            id = i;
        }
    }
    index_list[id]++;
    return id;
}
int main() {
    //fin, fout;
    ios::sync_with_stdio(false);
    cin >> n;
    int num = 0;
    for(int i = 1; i <= n; i++) {
        cin >> m;
        num += m;
        while(m--) {
            node testee;
            cin >> testee.id >> testee.score;
            testee.list_id = i;
            p[i].push_back(testee);
        }
        sort(p[i].begin(), p[i].end());
    }
    for(int i = 0; i < maxn; i++) index_list[i] = 0, rank_list[i] = 1;
    int cur_score = 0, cur_rank = 1;
    cout << num << endl;
    for(int i = 0; i < num; i++) {
        int id = choose();
        cout << p[id][index_list[id] - 1].id << " ";
        if(i == 0) {
            cur_score = p[id][index_list[id] - 1].score;
            cout << 1 << " " << p[id][index_list[id] - 1].list_id << " ";
        }
        else {
            if(p[id][index_list[id] - 1].score == cur_score) {
                cout << cur_rank << " " << p[id][index_list[id] - 1].list_id << " ";
            }
            else {
                cout << i + 1 << " " << p[id][index_list[id] - 1].list_id << " ";
                cur_rank = i + 1;
                cur_score = p[id][index_list[id] - 1].score;
            }
        }
        if(index_list[id] == 1) {
            cout << 1 << endl;
        }
        else {
            if(p[id][index_list[id] - 1].score == p[id][index_list[id] - 2].score) cout << rank_list[id] << endl;
            else {
                cout << index_list[id] << endl;
                rank_list[id] = index_list[id];
            }
        }
    }
    return 0;
}