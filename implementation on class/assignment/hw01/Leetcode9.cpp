#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    


    bool isPalindrome (int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int reverse_number = 0;
        while (x > reverse_number) {
            reverse_number = reverse_number * 10 + x % 10;
            x /= 10; 
        }
        return x == reverse_number || x == reverse_number / 10;
    }


};

class Solution_2 {
    public:
        bool isPalindrome (int x) {
            if (x < 0) return false;
            int origin = x;
            int reversed = 0;
            while (x != 0) {
                int digit = x % 10 ;
                reversed = reversed * 10 + digit;
                x /= 10;
            }
            return reversed == origin;
        }
};

class Solution_3 {
    public:
        bool isPalindrome (int x) {
            int div = 1;
            if (x < 0) return false;
            while ((x / div) >= 10) div *= 10;
            while (x) {
                int left = x / div;
                int right = x % 10;
                if (left != right) return false;
                
                x = (x % div) / 10;
                div /= 100;
            }
            return true;
        }
};

int main() {
    freopen("in.txt", "r", stdin);
    int input = 0;
    Solution sl;
    while (cin >> input) {
        cout << (sl.isPalindrome(input) ? 1 : 0) << endl;

    }
    return 0;
}