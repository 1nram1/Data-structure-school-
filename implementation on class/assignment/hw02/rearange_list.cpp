#include<iostream>
using namespace std;

struct Listnode {
    int val;
    Listnode *next;
    Listnode(int x) : val(x), next(NULL) {}
};


int main() {
    freopen("in.txt", "r", stdin);

    return 0;
}