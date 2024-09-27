#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
     int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0, length = tokens.size(); i < length; ++i) {
            string s = tokens[i];
            if (s == "+" || s == "-" || s == "/" || s == "*") {
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            if(s == "+") {
                st.push(num2 + num1);
            }
            if(s == "-") {
                st.push(num2 - num1);
            }
            if(s == "/") {
                st.push(num2 / num1);
            }
            if(s == "*") {
                st.push(num2 * num1);
            }
            } else {
                st.push(stoi(s));
            }
        }
        int result = st.top();
        return result;
    }

};
int main() {
    freopen("in.txt", "r", stdin);
    Solution sl;
    string line, token;
    getline(cin, line);
    istringstream ss(line);
    vector<string> tokens;
    while (getline(ss, token, ',')) {
        tokens.push_back(token);
    }
    cout << sl.evalRPN(tokens) << endl;
    return 0;
}