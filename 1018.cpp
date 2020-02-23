#include <bits/stdc++.h>
using namespace std;
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)

const int maxn = 505;

struct node {
    int id, tm;
    node(int id, int tm) {
        this->id = id;
        this->tm = tm;
    }
};

vector<node> p[maxn];

int graph[maxn][maxn];

int cur_stored[maxn];
int capacity, n, pro_station, m;
int min_dis[maxn];
void dijstra() {
    bool vis[maxn];
    memset(vis, false, sizeof(vis));
    vis[0] = true;
    for(int i = 0; i <= n; i++) min_dis[i] = graph[0][i]; 
    for(int i = 1; i <= n; i++) {
        int cur_dis = 100000000, id = 0;
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && min_dis[j] < cur_dis) {
                id = j, cur_dis = min_dis[j];
            }
        }
        vis[id] = true;
        //cout << "id = " << id << endl;
        for(int j = 1; j <= n; j++) {
            if(!vis[j]) {
                min_dis[j] = min(min_dis[j], graph[id][j] + min_dis[id]);
            }
        }
    }
}
vector<int> trace, ans_trace;
int send = 100000000;
int take_back = 0;
void cal_send(int &sent, int &back) {
    int ave = capacity >> 1;
    for(int i = 1; i < (int)trace.size(); i++) {
        if(cur_stored[trace[i]] < ave) {
            int cur_store = cur_stored[trace[i]] + back;
            back = 0;
            if(cur_store > ave) back = cur_store - ave;
            else if(cur_store < ave) sent += (ave - cur_store);
        }
        else {
            back += (cur_stored[trace[i]] - ave);
        }
    }
}

bool vis[maxn];
void dfs(int root, int length) {
    if(root == pro_station) {
        if(length != min_dis[pro_station]) {
            return ;
        }
        int cur_send = 0, cur_back = 0;
        cal_send(cur_send, cur_back);
        if(cur_send < send || (cur_send == send && cur_back < take_back)) {
            send = cur_send;
            take_back = cur_back;
            ans_trace = trace;
        }
    }
    for(int i = 0; i < p[root].size(); i++) {
        if(!vis[p[root][i].id]) {
            vis[p[root][i].id] = true;
            trace.push_back(p[root][i].id);
            dfs(p[root][i].id, length + p[root][i].tm);
            trace.pop_back();
            vis[p[root][i].id] = false;
        }
    }
}

void output() {
    int sent = 0, back = 0;
    int ave = capacity >> 1;
    for(int i = 1; i < (int)ans_trace.size(); i++) {
        if(cur_stored[ans_trace[i]] < ave) {
            cur_stored[ans_trace[i]] += back;
            back = 0;
            if(cur_stored[ans_trace[i]] > ave) back = cur_stored[ans_trace[i]] - ave;
            else if(cur_stored[ans_trace[i]] < ave) sent += (ave - cur_stored[ans_trace[i]]);
        }
        else {
            back += (cur_stored[ans_trace[i]] - ave);
        }
        cout << ans_trace[i] << " " << sent << " " << back << endl;
    }
}

int main() {
    // fin;
    // fout;
    ios::sync_with_stdio(false);
    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            graph[i][j] = 100000000;
        }
    }
    cin >> capacity >> n >> pro_station >> m;    
    for(int i = 1; i <= n; i++) {
        cin >> cur_stored[i];
    }
    for(int i = 0; i < m; i++) {
        int from, to, taken_time;
        cin >> from >> to >> taken_time;
        graph[from][to] = graph[to][from] = taken_time;
        p[from].push_back(node(to, taken_time));
        p[to].push_back(node(from, taken_time));
    }
    dijstra();
    trace.push_back(0);
    dfs(0, 0);
    cout << send << " ";
    for(int i = 0; i < ans_trace.size(); i++) {
        if(i == 0) cout << ans_trace[i];
        else cout << "->" << ans_trace[i];
    }
    cout << " " << take_back << endl;
    //output();
    return 0;
}