// question link: https://www.geeksforgeeks.org/problems/search-in-a-matrix--021840/0

// User function Template for C++
class Solution {
  public:
    // Function to search a given integer in a matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == x){  
                    return true;
                }
            }
        }
        return false;
    }
};
