/*3446. Sort Matrix by Diagonals
You are given an n x n square matrix of integers grid. Return the matrix such that:
The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
The diagonals in the top-right triangle are sorted in non-decreasing order.
Example 1:
Input: grid = [[1,7,3],[9,8,2],[4,5,6]]
Output: [[8,2,3],[9,6,7],[4,5,1]]
Explanation:
The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:
[1, 8, 6] becomes [8, 6, 1].
[9, 5] and [4] remain unchanged.
The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:
[7, 2] becomes [2, 7].
[3] remains unchanged.
Example 2:
Input: grid = [[0,1],[1,2]]
Output: [[2,1],[1,0]]
Explanation:
The diagonals with a black arrow must be non-increasing, so [0, 2] is changed to [2, 0]. The other diagonals are already in the correct order.
Example 3:
Input: grid = [[1]]
Output: [[1]]
Explanation:
Diagonals with exactly one element are already in order, so no changes are needed.*/
class Solution {
    void insert(vector<vector<int>>& grid, vector<int>& temp, int i, int j,
                bool check) {
        if (check)
            sort(temp.rbegin(), temp.rend());
        else
            sort(temp.begin(), temp.end());
        int s = 0, l = i, r = j;
        while (s < temp.size()) {
            grid[l][r] = temp[s];
            l++;
            r++;
            s++;
        }
    }
    void process(vector<vector<int>>& grid, int i, int j, bool check) {
        vector<int> temp;
        int k = i, l = j;
        while (k < grid.size() && l < grid.size()) {
            temp.push_back(grid[k][l]);

            l++;
            k++;
        }
        insert(grid, temp, i, j, check);
    }

public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int j = 0, l = 1;
        for (int i = 0; i < grid.size() - 1; i++) {
            process(grid, i, j, true);
            process(grid, j, l, false);
            l++;
        }
        return grid;
    }
};
