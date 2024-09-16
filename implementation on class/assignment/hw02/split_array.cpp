#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

void split_array (vector<int> arr, int k1, int k2, int N) {
    vector<int> less_than_k1, bewteen_k1_and_k2, greater_than_k2;
    for (int i = 0; i < N; ++i) {        
        if (arr[i] < k1) {
            less_than_k1.push_back(arr[i]);
        } else if (arr[i] > k2) {
            greater_than_k2.push_back(arr[i]);
        } else {
            bewteen_k1_and_k2.push_back(arr[i]);
        }
    }
    for (int num : less_than_k1) {
        cout << num << " ";
    }
     for (int num : bewteen_k1_and_k2) {
        cout << num << " ";
    }
     for (int num : greater_than_k2) {
        cout << num << " ";
    }
    cout << endl;
}


int main() {
    //freopen("in.txt", "r", stdin);
    
    int k1 = 0, k2 = 0, N = 0, num = 0;
    vector<int> nums;
    cin >> k1 >> k2 >> N;
    if (k1 > k2) {
        cout << "false" << endl;
        return 0;
    }
    while (cin >> num) {
        nums.push_back(num);
    }
    split_array(nums, k1, k2, N);
    
    return 0;
}