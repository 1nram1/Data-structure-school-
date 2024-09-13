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

void merge() {
    
}


void mergesort_linklist(){

}

void Mergesort_linklist(){

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
        Mergesort(nums);
        for(int a : nums) {
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}