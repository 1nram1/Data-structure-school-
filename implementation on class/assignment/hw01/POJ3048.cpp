#include<iostream>
using namespace std;
#include<cmath>
#include<vector>

int max_primer_factor(int number) {
    int max_factor = -1;
    while (number % 2 == 0) {
        max_factor = 2;
        number /= 2;
    }

    for (int i = 3; i <= sqrt(number); i += 2) {
        while (number % i == 0) {
            max_factor = i;
            number /= i;
        }
    }

    if (number > 2) {
        max_factor = number;
    }
    return max_factor;  
}

int main() {
    freopen("in.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int number_of_input = 0;
    cin >> number_of_input;
    vector<int> input(number_of_input);
    for (int i = 0; i < number_of_input; ++i) {
        cin >> input[i];
    }
    int MaxFactor = -1;
    int result = 0;
    int max_factor_item = 0;
    for (const int item : input) {
        max_factor_item = max_primer_factor(item);
        if (max_factor_item > MaxFactor) {
            MaxFactor = max_factor_item;
            result = item;
        }
    }
    cout << result ;
    return 0;
}