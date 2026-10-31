#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    string s = "abcabcbb";

    unordered_set<char> st;

    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < s.size(); right++) {

        while (st.find(s[right]) != st.end()) {
            st.erase(s[left]);
            left++;
        }

        st.insert(s[right]);

        maxLength = max(maxLength, right - left + 1);
    }

    cout << "Longest Length: " << maxLength;

    return 0;
}
