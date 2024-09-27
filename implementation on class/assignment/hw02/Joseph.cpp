#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(nullptr) {}
};


class Joseph {
public:
    ListNode *dummy;
    int size ;
    Joseph(int n) {
        size = n;
        dummy = new ListNode(0);
        ListNode *p = dummy;
        for (int i = 1; i <= n; ++i) {
            p -> next = new ListNode(i);
            p = p -> next;
        }
    }
    void solution(int pw) {
        // 默认至少有一个元素
        vector<int> result;
        ListNode *p = dummy -> next, *pre = dummy;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < pw - 1; ++j) {
                pre = p;
                p = (!(p -> next)) ? dummy -> next : p -> next;
            }
            result.push_back(p -> val);
            //这个if语句，是为了处理当链表中只剩下一个结点的情况
            if (pre == p) {
                pre = dummy;
            }
            pre -> next = p -> next;
            delete p;
            p = pre -> next;
            //这个语句是处理，删之前的p指向的是链表中的最后一个结点，p没有成功的达到循环的效果
            if (!p) {
                p = dummy -> next;
            }
        }
        rebuild(result);
    }

    void rebuild(vector<int> arr) {
        ListNode *p = dummy;
        for (int i = 0; i < size; ++i) {
            p -> next = new ListNode(arr[i]);
            p = p -> next;
        }
    }
    void print() {
        ListNode *p =dummy;
        for (int i = 0; i < size; ++i) {
            p = p -> next;
            cout << setw(4) << p -> val;
        }
        cout << endl;
    }
};



int main() {
    int M = 0, pw = 0;
    cin >> M;
    Joseph js(M);
    while (cin >> pw) {
        js.solution(pw);       
    }
    js.print();
    return 0;
}