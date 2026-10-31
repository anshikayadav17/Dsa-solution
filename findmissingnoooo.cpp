#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {3, 0, 1};

    int n = arr.size();

    int sum = n * (n + 1) / 2;

    for (int x : arr) {
        sum -= x;
    }

    cout << "Missing Number: " << sum;

    return 0;
}
