#include <bits/stdc++.h>
using namespace std;
#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)

struct node {
    int month, day, hh, mm;
    bool online;
    bool operator < (const node & b) {
        if(month != b.month) return month < b.month;
        else if(day != b.day) return day < b.day;
        else if(hh != b.hh) return hh < b.hh;
        else return mm < b.mm;
    }
};

map<string, vector<node> > mp;      //每个人用户有个通话记录

double per_price[24];

//对输入的处理
void process_tm(string name, string tm, string status, node & new_node) {
    if(status == "on-line") new_node.online = true;
    else new_node.online = false;
    for(int i = 0; i < 4; i++) {
        int t = 0;
        for(int j = i * 3; j < i * 3 + 2; j++) {
            t = t * 10 + (tm[j] - '0');
        }
        if(i == 0) new_node.month = t;
        else if(i == 1) new_node.day = t;
        else if(i == 2) new_node.hh = t;
        else new_node.mm = t;
    }
}

void input() {
    for(int i = 0; i < 24; i++) {
        cin >> per_price[i];
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string name, tm, status;
        cin >> name >> tm >> status;
        node new_node;
        process_tm(name, tm, status, new_node);
        mp[name].push_back(new_node);
    }
}

//计算两个节点之间的时间，以及费用
void cal_all_time(node start, node end, double &money, int &tm) {
    //将两者的时间表示到分再相减
    int start_m = (start.day - 1) * 24 * 60 + start.hh * 60 + start.mm;
    int end_m = (end.day - 1) * 24 * 60 + end.hh * 60 + end.mm;
    tm = end_m - start_m;     //两点之间的时间
    //计算两点之间的费用
    //日
    for(; start.day < end.day; start.day++) {
        for(; start.hh < 24; start.hh++) {
            money += (60 - start.mm) * per_price[start.hh];
            start.mm = 0;
        }
        start.hh = 0;
    }
    //时
    for(; start.hh < end.hh; start.hh++) {
        money += (60 - start.mm) * per_price[start.hh];
        start.mm = 0;
    }
    //分
    money += (end.mm - start.mm) * per_price[start.hh];
}

void output_per_record(node start, node end, int tm, double amount) {
    printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", start.day, start.hh, start.mm, end.day, end.hh, end.mm, tm, amount / 100);
}

int main() {
    //fin;
    //fout;
    //cout.precision(2);
    input();
    for(map<string, vector<node> >::iterator key = mp.begin(); key != mp.end(); key++) {
        vector<node> x = key->second;
        //按时间排序
        sort(x.begin(), x.end());
        bool isexit = true;     //本客户是否有完整的通话时间记录
        node start, end;        //单次记录的开始、结束节点
        bool flag = false;      //用来标记当前状态是on-line还是off-line
        double per_money = 0;   //单次记录的费用
        int per_tm = 0;         //单次记录的时间
        double person_amount = 0;   //每个人的总费用
        for(int i = 0; i < (int)x.size(); i++) {
            //当前状态是off-line，我们需要寻找on-line
            if(!flag && x[i].online) {
                start = x[i];
                flag = true;
                continue;
            }
            //当前是on-line，但是又碰到了on-line，则以当前碰到的on-line为基准
            if(flag && x[i].online) {
                start = x[i];
                continue;
            }
            //当前是on-line，碰到了off-line，完整的记录
            if(flag && !x[i].online) {
                end = x[i];
                flag = false;
                //是否是第一个记录，若是，则先输出姓名，月份
                if(isexit) {
                    cout << key->first;
                    printf(" %02d\n", x[0].month);
                    isexit = false;
                }
                //计算当前记录的时间、费用
                cal_all_time(start, end, per_money, per_tm);
                //输出
                output_per_record(start, end, per_tm, per_money);
                //更新客户总费用
                person_amount += per_money;
                per_money = 0;
                per_tm = 0;
            }
        }
        //若该客户存在完整记录，则需要输出总费用
        //若存在完整记录，则isexit被更新成false了，在114行
        if(!isexit) printf("Total amount: $%.2f\n", person_amount / 100.);
    }
    return 0;
}
