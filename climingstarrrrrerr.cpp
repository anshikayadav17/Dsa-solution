#include <iostream>
using namespace std;

int main() {

    int n = 5;

    if (n <= 2) {
        cout << n;
        return 0;
    }

    int first = 1;
    int second = 2;

    for (int i = 3; i <= n; i++) {

        int current = first + second;

        first = second;
        second = current;
    }

    cout << "Total Ways: " << second;

    return 0;
}
