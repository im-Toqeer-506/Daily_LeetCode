class Solution {
public:
    bool recursive(vector<vector<int>>& matrix, int target, int low, int high, int m) {
        if (low > high) {
            return false;
        }

        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;

        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] < target) {
            return recursive(matrix, target, mid + 1, high, m);
        } else {
            return recursive(matrix, target, low, mid - 1, m);
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        return recursive(matrix, target, 0, n * m - 1, m);
    }
};
