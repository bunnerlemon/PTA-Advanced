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

map<string, vector<node> > mp;      //ÿ�����û��и�ͨ����¼

double per_price[24];

//������Ĵ���
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

//���������ڵ�֮���ʱ�䣬�Լ�����
void cal_all_time(node start, node end, double &money, int &tm) {
    //�����ߵ�ʱ���ʾ���������
    int start_m = (start.day - 1) * 24 * 60 + start.hh * 60 + start.mm;
    int end_m = (end.day - 1) * 24 * 60 + end.hh * 60 + end.mm;
    tm = end_m - start_m;     //����֮���ʱ��
    //��������֮��ķ���
    //��
    for(; start.day < end.day; start.day++) {
        for(; start.hh < 24; start.hh++) {
            money += (60 - start.mm) * per_price[start.hh];
            start.mm = 0;
        }
        start.hh = 0;
    }
    //ʱ
    for(; start.hh < end.hh; start.hh++) {
        money += (60 - start.mm) * per_price[start.hh];
        start.mm = 0;
    }
    //��
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
        //��ʱ������
        sort(x.begin(), x.end());
        bool isexit = true;     //���ͻ��Ƿ���������ͨ��ʱ���¼
        node start, end;        //���μ�¼�Ŀ�ʼ�������ڵ�
        bool flag = false;      //������ǵ�ǰ״̬��on-line����off-line
        double per_money = 0;   //���μ�¼�ķ���
        int per_tm = 0;         //���μ�¼��ʱ��
        double person_amount = 0;   //ÿ���˵��ܷ���
        for(int i = 0; i < (int)x.size(); i++) {
            //��ǰ״̬��off-line��������ҪѰ��on-line
            if(!flag && x[i].online) {
                start = x[i];
                flag = true;
                continue;
            }
            //��ǰ��on-line��������������on-line�����Ե�ǰ������on-lineΪ��׼
            if(flag && x[i].online) {
                start = x[i];
                continue;
            }
            //��ǰ��on-line��������off-line�������ļ�¼
            if(flag && !x[i].online) {
                end = x[i];
                flag = false;
                //�Ƿ��ǵ�һ����¼�����ǣ���������������·�
                if(isexit) {
                    cout << key->first;
                    printf(" %02d\n", x[0].month);
                    isexit = false;
                }
                //���㵱ǰ��¼��ʱ�䡢����
                cal_all_time(start, end, per_money, per_tm);
                //���
                output_per_record(start, end, per_tm, per_money);
                //���¿ͻ��ܷ���
                person_amount += per_money;
                per_money = 0;
                per_tm = 0;
            }
        }
        //���ÿͻ�����������¼������Ҫ����ܷ���
        //������������¼����isexit�����³�false�ˣ���114��
        if(!isexit) printf("Total amount: $%.2f\n", person_amount / 100.);
    }
    return 0;
}
