#include <iostream>
#include <set>
using namespace std;

set<int> myset;

int main() {
  freopen("in.txt", "r", stdin);
  int a_item, b_item,item;
  cin >> a_item >> b_item;
  while (a_item--) { 
    cin >> item;
    myset.insert(item);
  }
  while (b_item--) {
    cin >> item;
    myset.insert(item);
  }
  for (auto it = myset.begin(); it != myset.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}
