//Count Servers that Communicate.
/*You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.
Return the number of servers that communicate with any other server.*/
/*Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.
Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.*/
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> row(rows, 0), col(cols, 0);
//we need to get the communication between two server .For that we need find out how server in row wise and also coloum wise. 
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int tol = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {  /* if we get the server then check it with row and coloum .the row and coloum array we already created 
                and stored the value accordoring to server . NOw check current server is connected with atlest its row or coloum server*/
                    tol++;
                }
            }
        }

        return tol;
    }
};
/* this problem may make you feel easy at first.But after you see all the test case only you will understand the real task */
