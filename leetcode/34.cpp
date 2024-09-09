#include<iostream>
using namespace std;
#include<vector>

int lower_bound(vector<int> &nums, int target);
int upper_bound(vector<int> &nums,int target);


vector<int> searchRange(vector<int>& nums, int target) {
   if (nums.empty()) return vector<int> {-1,-1}; //uniform initialize
   int lower = lower_bound(nums,target);
   int upper = upper_bound(nums,target) - 1;

   if (lower == nums.size() || nums[lower] != target) {
    return {-1,-1};
   }
   return {lower,upper};
}

// helper method
int lower_bound(vector<int> &nums, int target) {
   size_t l = 0, r = nums.size(), mid;
   while (l < r) {
    mid = (l + r) / 2;
    if (nums[mid] >= target) {
        r = mid;
    } else {
        l = mid + 1;
    }
   }
   return l;
}

int upper_bound(vector<int> &nums,int target) {
    size_t l = 0, r = nums.size(), mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (nums[mid] > target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return 1;
}