#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include <sstream>
#include<string>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0, length = nums.size(); i < length; ++i) {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                vector<int> result = {iter->second, i};
                return result;
            }
            map[nums[i]] = i;
            //map.insert({nums[i], i})
            //map.insert(pair<int,int>(nums[i], i));
        }
        vector<int> b = {-1, -1};
        return b;
    }
};


int main() {
    freopen("in.txt", "r", stdin);
    string line;
    Solution sl;
    while (getline(cin, line)) {
        istringstream iss(line);
        int num = 0;
        vector<int> nums;
        while (iss >> num) {
            nums.push_back(num);
        }
        getline(cin, line);
        int target = stoi(line);
        vector<int> result = sl.twoSum(nums, target);
        for (int i = 0, length = result.size(); i < length; ++i) {
            cout << result[i] ;
            if (i < length - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}