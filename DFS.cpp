#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j) {

    int m = grid.size();
    int n = grid[0].size();

    if (i < 0 || j < 0 || i >= m || j >= n ||
        grid[i][j] == '0')
        return;

    grid[i][j] = '0';

    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0'},
        {'1', '0', '0', '1'},
        {'0', '0', '1', '1'},
        {'0', '0', '0', '0'}
    };

    int count = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {

            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }

    cout << "Number of Islands: " << count;

    return 0;
}
