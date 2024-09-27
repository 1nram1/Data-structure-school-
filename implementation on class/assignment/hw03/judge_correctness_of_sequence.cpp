#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

bool is_valid_sequence(vector<char> &str1, vector<char> &str2, int n) {
    stack<char> st;
    int i = 0, j = 0;
    while (i < n) {
        st.push(str1[i++]);
        while(!st.empty() && str2[j] == st.top()) {
            st.pop();
            j++;
        }    
    }
    return st.empty();
}

int main() {
    int N = 0;
    // cin 只读取数字，会在缓冲区中残留一个换行符
    // 如果cin后直接跟一个getline, 它会读取这个残留的换行符
    // 结果line1变成一个空字符串
    cin >> N;

    //cin.ignore是为了清除缓冲区在残留的换行符，确保后续的
    //getline能正确读取完整的一行输入
    cin.ignore();
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    istringstream iss1(line1), iss2(line2);
    char token;
    vector<char> str1, str2;
    while (iss1 >> token) {
        str1.push_back(token);
    }
    while (iss2 >> token) {
        str2.push_back(token);
    }
    // if (is_valid_sequence(str1, str2, N)) {
    //     cout << "true" << endl;
    // } else {
    //     cout << "false" << endl;
    // }

    // 最后不能加换行符（endl），加了换行符就是错误的
    cout << (is_valid_sequence(str1, str2, N) ? "true" : "false") ;
    return 0;
}