#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int max_count = 1;

        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> slope_count;
            int local_max = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                // Reduce fraction to simplest form using GCD
                int g = std::gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Standardize negative signs so identical slopes yield identical strings
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                // Convert slope fraction into a unique hash map key
                string slope_key = to_string(dy) + "/" + to_string(dx);
                slope_count[slope_key]++;
                
                local_max = max(local_max, slope_count[slope_key]);
            }

            // Include the anchor point itself (+1)
            max_count = max(max_count, local_max + 1);
        }

        return max_count;
    }
};
