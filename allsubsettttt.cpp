#include <iostream>
#include <vector>
using namespace std;

void generate(vector<int>& arr, int index,
              vector<int>& current) {

    if (index == arr.size()) {
        cout << "{ ";

        for (int x : current)
            cout << x << " ";

        cout << "}" << endl;
        return;
    }

    current.push_back(arr[index]);
    generate(arr, index + 1, current);

    current.pop_back();
    generate(arr, index + 1, current);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> current;

    generate(arr, 0, current);

    return 0;
}
