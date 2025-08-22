/*3195. Find the Minimum Area to Cover All Ones I
You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.
Return the minimum possible area of the rectangle.
Example 1
Input: grid = [[0,1,0],[1,0,1]]
Output: 6
Explanation:
The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.
Example 2:
Input: grid = [[1,0],[0,0]]
Output: 1
Explanation:
The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.*/
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int i=INT_MAX,j=INT_MAX,l=-1,r=-1;
        for(int x=0;x<grid.size();x++){
            for(int y=0;y<grid[0].size();y++){
                if(grid[x][y]==1){
                    i=min(x,i);
                    j=min(y,j);
                    l=max(y,l);
                    r=max(x,r);
                }
            }
        }
        if (r == -1) return 0;
        return (r-i+1)*(l-j+1);
    }
};
