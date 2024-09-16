#include<iostream>
using namespace std;
#include<vector>
#include<sstream>


// array-version
void merge(vector<int>& array, int low, int mid, int high) {
    vector<int> sub_ar(high - low + 1);
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) 
    {
        if (array[i] <= array[j]) {
            sub_ar[k++] = array[i++];
        } else {
            sub_ar[k++] = array[j++];
        }
    }
    while (i <= mid) {
        sub_ar[k++] = array[i++];
    }
    while (j <= high) {
        sub_ar[k++] = array[j++];
    }
    for (k = 0, i = low; i <= high; ++k, ++i) {
        array[i] = sub_ar[k];
    }
}



void mergesort(vector<int>& item, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergesort(item, left, mid);
    mergesort(item, mid + 1, right);
    merge(item, left, mid, right);
}



void Mergesort(vector<int>& items) {
    mergesort(items, 0, items.size() - 1);
}

//linklist-version

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


//返回值为指向中间那个结点的指针
ListNode* middleNode(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next && fast->next->next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}


//返回值为merge后的链表的头节点
ListNode* merge(ListNode *l1, ListNode *l2) {
    ListNode dummy(0), *p = &dummy;
    while (l1 && l2) {
        if (l1 -> val < l2 -> val) {
            p -> next = l1;
            l1 = l1 -> next;    
        } else {
            p -> next = l2;
            l2 = l2 -> next;
        }
        p = p -> next;
    }
    p -> next = l1 ? l1 : l2;
    return dummy.next;
}


// 返回值为sort后的链表的头节点
ListNode* mergesort_linklist(ListNode *head){
    if (!head || !head -> next) {
        return head;
    }
    ListNode *mid = middleNode(head);
    ListNode *p = mid -> next;
    mid -> next = nullptr;
    ListNode *left = mergesort_linklist(head);
    ListNode *right = mergesort_linklist(p);
    return merge(left, right);
}

ListNode* create_linklist(vector<int> arr) {
    int size = arr.size();
    if (!size) {
        return nullptr;
    }
    ListNode *head = new ListNode(arr[0]), *cur = head;
    for (int i = 1; i < size; ++i) {
        cur -> next = new ListNode(arr[i]);
        cur = cur -> next; 
    }
    return head;
}


int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        int num = 0;
        vector<int> nums = {};
        while (iss >> num) {
            nums.push_back(num);
        }
        ListNode *input = create_linklist(nums);
        ListNode *result = mergesort_linklist(input);
        for (ListNode *p = result; p != nullptr; p = p -> next) {
            cout << p -> val << " ";
        }
        cout << endl;
    }
    return 0;
}