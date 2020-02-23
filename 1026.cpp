#include <bits/stdc++.h>
using namespace std;
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)
const int maxn = 105;
const int limit = 21 * 3600;
struct node {
    int hh, mm, ss;
    int tm;
    int time_ss;
    friend bool operator < (const node & a, const node & b) {
        return a.time_ss > b.time_ss;
    }
};
priority_queue<node> regular, vip;
int table[maxn];
int table_num[maxn];
int table_server_time[maxn];
int n, k, m;
void input() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        node new_node;
        int tag;
        scanf("%d:%d:%d %d %d", &new_node.hh, &new_node.mm, &new_node.ss, &new_node.tm, &tag);
        new_node.time_ss = new_node.hh * 3600 + new_node.mm * 60 + new_node.ss;
        if(tag) vip.push(new_node);
        else regular.push(new_node);
    }
    scanf("%d %d", &k, &m);
    int x;
    for(int i = 0; i < m; i++) scanf("%d", &x), table[x] = 1;
    for(int i = 0; i < k; i++) table_server_time[i] = 8 * 3600;
}
int choose() {
    int chosen_table = -1, min_time = -1;
    for(int i = 0; i < k; i++) {
        if(chosen_table == -1) { chosen_table = i, min_time = table_server_time[i]; }
        else {
            if(table_server_time[i] < min_time) {
                chosen_table = i, min_time = table_server_time[i];
            }
            else if(table_server_time[i] == min_time && table[chosen_table] && !table[i]) {
                chosen_table = i;
            }
        }
    }
    return chosen_table;
}
bool judge(int table_id, node customer) {
    if(table_server_time[table_id] + customer.tm * 60 > limit) return false;
    else return true;
}
void choose_regular(int table_id) {
    node x = regular.top();
    regular.pop();
    table_num[table_id]++;
    printf("%02d:%02d:%02d ", x.hh, x.mm, x.ss);
    if(x.time_ss >= table_server_time[table_id]) {
        printf("%02d:%02d:%02d %d\n",x.time_ss / 3600, (x.time_ss % 3600) / 60, (x.time_ss % 3600) % 60, 0);
        table_server_time[table_id] = x.time_ss + x.tm * 60;
    }
    else {
        int times = table_server_time[table_id];
        printf("%02d:%02d:%02d %d\n", times / 3600, (times % 3600) / 60, (times % 3600) % 60, (times - x.time_ss) % 60 == 0 ? (times - x.time_ss) / 60 : (times - x.time_ss) / 60 + 1);
        table_server_time[table_id] += x.tm * 60;
    }
}
node choose_customer() {
    if(!regular.empty() && !vip.empty()) {
        if(regular.top().time_ss < vip.top().time_ss) {
            node x = regular.top();
            regular.pop();
            return x;
        }
        else {
            node x = vip.top();
            vip.pop();
            return x;
        }
    }
    else if(!regular.empty() && vip.empty()) {
        node x = regular.top();
        regular.pop();
        return x;
    }
    else if(regular.empty() && !vip.empty()) {
        node x = vip.top();
        vip.pop();
        return x;
    }
}
void choose_vip_regular(int vip_first, int regular_first) {
    bool vip_arrive = (vip_first <= regular_first);
    int chosen_table = -1, min_time = -1;
    for(int i = 0; i < k; i++) {
        if(chosen_table == -1) { chosen_table = i, min_time = table_server_time[i]; }
        else {
            if(table_server_time[i] < min_time) { min_time = table_server_time[i], chosen_table = i; }
            else if(table_server_time[i] == min_time) {
                if(vip_arrive && !table[chosen_table] && table[i]) {
                    chosen_table = i;
                }
            }
        }
    }
}
//在同时有vip table和regular table时，vip客户会优先vip table
int main() {
    //fin, fout;
    input();
    for(int i = 0; i < n; i++) {
        int table_id = choose();
        //cout << "table_id = " << table_id << endl;
        if(!vip.empty()) {
            node x = vip.top();
            if(x.time_ss <= table_server_time[table_id] || regular.empty() || (x.time_ss <= regular.top().time_ss)) {
                vip.pop();
                if(judge(table_id, x)) {
                    table_num[table_id]++;
                    printf("%02d:%02d:%02d ", x.hh, x.mm, x.ss);
                    if(x.time_ss >= table_server_time[table_id]) {
                        printf("%02d:%02d:%02d %d\n",x.time_ss / 3600, (x.time_ss % 3600) / 60, (x.time_ss % 3600) % 60, 0);
                        table_server_time[table_id] = x.time_ss + x.tm * 60;
                    }
                    else {
                        int times = table_server_time[table_id];
                        printf("%02d:%02d:%02d %d\n", times / 3600, (times % 3600) / 60, (times % 3600) % 60, (times - x.time_ss) % 60 == 0 ? (times - x.time_ss) / 60 : (times - x.time_ss) / 60 + 1);
                        table_server_time[table_id] += x.tm * 60;
                    }
                }
                else {
                    continue;
                }
            }
            else {
                if(judge(table_id, regular.top())) {
                    choose_regular(table_id);
                }
                else {
                    regular.pop();
                    continue;
                }
            }
        }
        else {
            if(judge(table_id, regular.top())) {
                choose_regular(table_id);
            }
            else {
                regular.pop();
                continue;
            }
        }
    }
    for(int i = 0; i < k; i++) {
        if(i) printf(" %d", table_num[i]);
        else printf("%d", table_num[i]);
    }
    printf("\n");
    return 0;
}