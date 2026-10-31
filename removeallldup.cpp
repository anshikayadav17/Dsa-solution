#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4};

    int index = 0;

    for (int i = 1; i < arr.size(); i++) {

        if (arr[i] != arr[index]) {
            index++;
            arr[index] = arr[i];
        }
    }

    cout << "Unique elements: ";

    for (int i = 0; i <= index; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nCount: " << index + 1;

    return 0;
}
