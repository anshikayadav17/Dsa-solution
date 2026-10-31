#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {1, 3, 5, 7};
    vector<int> b = {2, 4, 6, 8};

    vector<int> result;

    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j])
            result.push_back(a[i++]);
        else
            result.push_back(b[j++]);
    }

    while (i < a.size())
        result.push_back(a[i++]);

    while (j < b.size())
        result.push_back(b[j++]);

    for (int x : result)
        cout << x << " ";

    return 0;
}
