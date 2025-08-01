/*118. Pascal's Triangle
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:
Input: numRows = 1
Output: [[1]]
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
        vector<int>temp;
        temp.push_back(1);
        int j=1;
        while(j<i){
             temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
             j++;
        }
         temp.push_back(1);
         ans.push_back(temp);
        
         }
        return ans;
    }
};
