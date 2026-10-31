#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> arr = {10, 5, 20, 8, 20};

    int largest = INT_MIN;
    int second = INT_MIN;

    for (int x : arr) {
        if (x > largest) {
            second = largest;
            largest = x;
        }
        else if (x > second && x != largest) {
            second = x;
        }
    }

    if (second == INT_MIN)
        cout << "No second largest element";
    else
        cout << "Second largest: " << second;

    return 0;
}
