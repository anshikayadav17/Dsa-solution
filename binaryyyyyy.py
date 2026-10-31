#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12};

    int target = 10;

    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            cout << "Found at index: " << mid;
            return 0;
        }

        else if (arr[mid] < target) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    cout << "Not Found";

    return 0;
}
