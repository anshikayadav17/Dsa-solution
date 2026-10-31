#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2, 2, 1, 1, 2, 2, 2};

    int candidate = 0;
    int count = 0;

    for (int x : arr) {
        if (count == 0)
            candidate = x;

        if (x == candidate)
            count++;
        else
            count--;
    }

    count = 0;

    for (int x : arr) {
        if (x == candidate)
            count++;
    }

    if (count > arr.size() / 2)
        cout << "Majority Element: " << candidate;
    else
        cout << "No majority element";

    return 0;
}
