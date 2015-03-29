class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int row = matrix.size();
        if(row < 1)
            return false;
        int col = matrix[0].size();
            
        int len = row * col;
        int first = 0;
        while(len > 0) {
            int half = len >> 1;
            if(matrix[(first+half)/col][(first+half)%col] < target) {
                first = first + half + 1;
                len = len - half - 1;
            }
            else if (matrix[(first+half)/col][(first+half)%col] > target) {
                len = half;
            }
            else if(matrix[(first+half)/col][(first+half)%col] == target)
                return true;
        }
        
        return false;
    }
};