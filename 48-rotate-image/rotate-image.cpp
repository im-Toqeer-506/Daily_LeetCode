class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();//this will give number of rows
      for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
        int temp = matrix[n - 1 - j][i]; //this line temp = bottom left
           matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];//this line ->bottom left = bottom right

            matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];//this line->bottom right = top right

            matrix[j][n - 1 - i] = matrix[i][j];//this line-> top right = top left
            
              matrix[i][j] = temp;// this line -> top left = temp

        }
        }
    }
};