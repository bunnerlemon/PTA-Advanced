#include <bits/stdc++.h>
using namespace std;
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)
const int maxn = 25;
struct Point {
    queue<int> customer;
    int occur_serve_start_time;
};
Point window[maxn];
int need_time[1005]; //每个客户需要的服务时间
int finish_time[1005]; //每个客户服务结束的时间
int n, m;
//选择一个当前最适合的队列
int choose() {
    int id = 0, min_num = window[0].customer.size(), min_time = window[0].occur_serve_start_time + need_time[window[0].customer.front()];
    for(int i = 1; i < n; i++) {
        if(min_num < window[i].customer.size()) continue;
        if(min_num > window[i].customer.size()) {
            id = i, min_num = window[i].customer.size(), min_time = window[i].occur_serve_start_time + need_time[window[i].customer.front()];
        }
        else if(min_time > window[i].occur_serve_start_time + need_time[window[i].customer.front()]) {
            id = i, min_time = window[i].occur_serve_start_time + need_time[window[i].customer.front()];
        }
    }
    return id;
} 
void output(int tm) {
    //printf("%02d:%02d\n", 8 + tm / 60, tm % 60);
    int hh = 8 + tm / 60, mm =  tm % 60;
    if(hh > 17) cout << "Sorry" << endl;
    else printf("%02d:%02d\n", 8 + tm / 60, tm % 60);
}
int main() {
    //fin;
    //ios::sync_with_stdio(false);
    int k, q;
    cin >> n >> m >> k >> q;
    for(int i = 1; i <= k; i++) {
        cin >> need_time[i];
    }
    int start;
    for(start = 1; start <= k; start++) {
        int rol = (start - 1) / n;
        int col = (start - 1) % n;
        if(rol < m) {
            window[col].customer.push(start);
            if(rol == 0) window[col].occur_serve_start_time = 0;
        }
        else break;
    }
    while(start <= k) {
        int id = choose();
        int x = window[id].customer.front();
        finish_time[x] = window[id].occur_serve_start_time + need_time[x];
        window[id].customer.pop();
        window[id].customer.push(start);
        window[id].occur_serve_start_time = finish_time[x];
        start++;
    }
    for(int i = 0; i < n; i++) {
        while(!window[i].customer.empty()) {
            int x =  window[i].customer.front();
            window[i].customer.pop();
            //cout << "test : " << x << endl;
            finish_time[x] = window[i].occur_serve_start_time + need_time[x];
            window[i].occur_serve_start_time = finish_time[x];
        }
    }
    while(q--) {
        int x;
        cin >> x;
        if(finish_time[x] - need_time[x] >= 540) cout << "Sorry" << endl;
        else output(finish_time[x]);
    }
    return 0;
}