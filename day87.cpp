/*498. Diagonal Traverse
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
Example 1:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
Example 2:
Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]*/
class Solution {
    void process(vector<int>&ans, vector<int>&temp, int count){
        if(count % 2 == 0 && temp.size() > 1) 
            reverse(temp.begin(), temp.end());
        for(auto i : temp) ans.push_back(i);
    }
   
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int count = 0;
        for(int i = 0; i < mat[0].size(); i++){
            int j = 0, k = i;
            vector<int> temp;
            while(k >= 0 && j < mat.size()){
                temp.push_back(mat[j][k]);
                k--;
                j++;
            }
            process(ans, temp, count);
            count++;
        } int ind=mat[0].size()-1;
        for(int i=1;i<mat.size();i++){
              int j=ind,k=i;
               vector<int> temp;
            while( j >=0 && k<mat.size()){
                temp.push_back(mat[k][j]);
                j--;
                k++;
            }
            process(ans, temp, count);
            count++;
        }
        
       
        return ans;
    }
};
