#include <bits/stdc++.h>
using namespace std;
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)

struct node {
    int hh, mm, ss;
    int pro_time;
    int time_ss;
    int time_to_8;
    bool operator < (const node & b) {
        if(hh != b.hh) return hh < b.hh;
        else if(mm != b.mm) return mm < b.mm;
        else return ss < b.ss;
    }
};

struct win {
    int end_time;
};

win window[105];

vector<node> customer;

int n, k;

bool notServer(node x) {
    return x.time_ss > 17 * 3600;
}

int choose_window(node x) {
    int id = 0;
    for(int i = 1; i < k; i++) {
        if(window[i].end_time < window[id].end_time) {
            id = i;
        }
    }
    int start_time = window[id].end_time;
    window[id].end_time = (window[id].end_time < x.time_to_8 ? x.time_to_8 : window[id].end_time) + x.pro_time;
    int wait_time = x.time_to_8 > start_time ? 0 : (start_time - x.time_to_8);
    //cout << wait_time << endl;
    return wait_time;
}

int main() {
    //fin;
    //fout;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++) window[i].end_time = 0;
    for(int i = 0; i < n; i++) {
        node new_node;
        scanf("%d:%d:%d %d", &new_node.hh, &new_node.mm, &new_node.ss, &new_node.pro_time);
        new_node.time_ss = new_node.hh * 3600 + new_node.mm * 60 + new_node.ss;
        new_node.time_to_8 = new_node.time_ss - 8 * 3600;
        new_node.pro_time = new_node.pro_time * 60;
        customer.push_back(new_node);
    }
    sort(customer.begin(), customer.end());
    int num = 0;
    double wait_time = 0;
    for(int i = 0; i < (int)customer.size(); i++) {
        if(notServer(customer[i])) break;
        wait_time += (double)choose_window(customer[i]);
        num++;
    }
    wait_time /= num;
    if(num) {
        printf("%.1f\n", wait_time / 60);
    }
    return 0;
}