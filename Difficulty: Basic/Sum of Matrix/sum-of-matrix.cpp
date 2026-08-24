class Solution {
  public:
    int sumOfMatrix(vector<vector<int>>& mat) {
        // code here
        int s=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                s=s+mat[i][j];
            }
        }
        return s;
    }
};