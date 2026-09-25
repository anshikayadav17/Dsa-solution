class Solution {
public:

    bool isPalindrome(string s, int start, int end) {

        while (start < end) {

            if (s[start] != s[end]) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }


    void backtrack(string s, int start,
                   vector<string>& current,
                   vector<vector<string>>& result) {

        if (start == s.length()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.length(); end++) {

            if (isPalindrome(s, start, end)) {

                string part = s.substr(start, end - start + 1);

                current.push_back(part);

                backtrack(s, end + 1, current, result);

                current.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {

        vector<vector<string>> result;

        vector<string> current;

        backtrack(s, 0, current, result);

        return result;
    }
};
