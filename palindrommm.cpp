class Solution {
public:
    int minCut(string s) {
        int n = s.length();

        // palindrome[i][j] tells us whether
        // s[i...j] is a palindrome
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        // Build palindrome table
        for (int length = 1; length <= n; length++) {

            for (int i = 0; i + length <= n; i++) {

                int j = i + length - 1;

                // Length 1
                if (length == 1) {
                    palindrome[i][j] = true;
                }

                // Length 2
                else if (length == 2) {
                    palindrome[i][j] = (s[i] == s[j]);
                }

                // Length >= 3
                else {
                    palindrome[i][j] =
                        (s[i] == s[j]) &&
                        palindrome[i + 1][j - 1];
                }
            }
        }

        // dp[i] = minimum cuts needed for s[0...i]
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {

            // If s[0...i] itself is a palindrome,
            // we don't need any cut.
            if (palindrome[0][i]) {
                dp[i] = 0;
            }

            else {
                // Try every possible partition
                dp[i] = i;

                for (int j = 1; j <= i; j++) {

                    // If s[j...i] is palindrome,
                    // make a cut before j.
                    if (palindrome[j][i]) {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};
