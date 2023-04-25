#include <iostream>
using namespace std;

int main() {
    int num = 10; 
    int *ptr = &num;

    cout << "Value of num: " << *ptr << "\n";

    *ptr = 66;
    cout << "Value of num: " << num << "\n";

    return 0;
};