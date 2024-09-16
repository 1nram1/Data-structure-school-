#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode (ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* reverseList (ListNode *head) {
        ListNode *cur = head, *pre = nullptr, *tmp;
        while (cur) {
            tmp = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    void reorderList(ListNode* head) {
        ListNode *mid = middleNode(head), *result = head;
        ListNode *head2 = reverseList(mid);
        while (head2 -> next) {
            ListNode *nxt = head -> next;
            ListNode *nxt2 = head2 -> next;
            head -> next = head2;
            head2 -> next = nxt;
            head = nxt;
            head2 = nxt2;
        }

    }
};



ListNode* creatLinkList(vector<int> arr) {
    int length = arr.size();
    if (!length) {
        return nullptr;
    }
    ListNode *head = new ListNode(arr[0]), *p = head;
    for (int i = 1; i < length; ++i) {
        p -> next = new ListNode(arr[i]);
        p = p -> next;
    }
    return head;
}

void printLinkList(ListNode* ls) {
    for (ListNode *p = ls; p != nullptr; p = p->next) {
        cout << p -> val <<" ";
    }
    cout << endl;
}



int main() {
    freopen("in.txt", "r", stdin);
    string line;
    Solution sl;
    int num = 0;
    vector<int> nums = {};
    while (cin >> num) {
        nums.push_back(num);
    }
        ListNode *ls = creatLinkList(nums);
        sl.reorderList(ls);
        printLinkList(ls);
    return 0;
}
