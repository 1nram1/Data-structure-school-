#include<iostream>
#include<queue>
#include<string>
using namespace std;


class Item {
public:
    int time;
    int value;
    Item(int a, int b) : value(a), time(b) {}
};

class Compare {
public:
    bool operator()(const Item &Item_1, const Item &Item_2) const{
        return Item_1.time < Item_2.time;
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    int n = 0, temp = 0;
    cin >> n;
    priority_queue<Item, vector<Item>, Compare> A, B, MA;
    for (int i = 0; i < n; ++i) {
        string s1, s2, s3;
        cin >> s1;
        if (s1 == "push") {
            cin >> s2 >> temp;
            if (s2 == "A") {
                A.push(Item(temp, i));
            } else {
                B.push(Item(temp, i));
            }
        } else if (s1 == "pop") {
            cin >> s2;
            if (s2 == "A") {
                if (A.empty()) {
                    cout << MA.top().value << endl;
                    MA.pop();
                } else {
                    cout << A.top().value << endl;
                    A.pop();
                }
            } else {
                if (B.empty()) {
                    cout << MA.top().value << endl;
                    MA.pop();
                } else {
                    cout << B.top().value << endl;
                    B.pop();
                }
                }
            } else {
                cin >> s2 >> s3;
                while(!A.empty()) {
                    MA.push(A.top());
                    A.pop();
                }
                while(!B.empty()) {
                    MA.push(B.top());
                    B.pop();
                }
            }
        }
    return 0;
}