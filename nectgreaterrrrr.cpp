#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};

    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for (int i = arr.size() - 1; i >= 0; i--) {

        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        if (!st.empty())
            ans[i] = st.top();

        st.push(arr[i]);
    }

    for (int x : ans)
        cout << x << " ";

    return 0;
}
