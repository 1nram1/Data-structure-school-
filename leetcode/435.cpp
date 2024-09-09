#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int NonOverslapping (vector<vector<int>>& a) {
      if (a.empty()) {
            return 0;
      }
    sort(a.begin(), a.end(), [] (vector<int> a,vector<int> b) {return a[1] < b[1];});
    int result = 0;
    int prev = a[0][1];
    for(size_t i = 1, n =a.size(); i < n; ++i) {
         if (a[i][0] < prev) {
             ++result;
         } else {
            prev = a[i][1];        
            }
    }
    return result;
}
