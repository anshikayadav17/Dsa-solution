#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {0, 1, 0, 3, 12};

    int index = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            swap(arr[index], arr[i]);
            index++;
        }
    }

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}
