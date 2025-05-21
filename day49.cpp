/*Set Matrix Zeroes
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.
Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]*/
class Solution {
    void makezero(int row,int col,vector<vector<int>>&matrix ){
int left=col-1,right=col+1,up=row-1,down=row+1;
while(left>=0 or right<matrix[0].size() or up >=0 or down<matrix.size()){
    if(left>=0){
        matrix[row][left]=0;
        left--;
    }
    if(right<matrix[0].size()){
         matrix[row][right]=0;
        right++;
    }
    if(up>=0){
        matrix[up][col]=0;
        up--;
    }
    if(down<matrix.size()){
        matrix[down][col]=0;
        down++;
    }
}
}
public:
    void setZeroes(vector<vector<int>>& matrix) {
       vector<pair<int,int>>temp;
      for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){
            temp.push_back({i,j});
            }
        }
      }
      for(auto it:temp){
        makezero(it.first,it.second,matrix);
      }
      
    }
};
