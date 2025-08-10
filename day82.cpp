/*869. Reordered Power of 2
You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
Return true if and only if we can do this so that the resulting number is a power of two.
Example 1:
Input: n = 1
Output: true
Example 2:
Input: n = 10
Output: false*/
class Solution {
    void recursion(string s,int i,int j,vector<string>&temp){
        if(i==j-1){
            temp.push_back(s);
            return ;
        }
        for(int k=i;k<j;k++){
             if (i != k && s[i] == s[k]) continue;
            swap(s[i], s[k]);
            recursion(s, i+1, j, temp);
        }
    }
    bool checkpoweroftwo(vector<string>&temp){
        for(auto i:temp){
            if(i[0]=='0') continue;
            int x=stoi(i);
            if(((1<<30) % x == 0)) return true;
         }
      return false;  
    }
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        vector<string>temp;
        recursion(s,0,s.size(),temp);
        return checkpoweroftwo(temp);
    }
};
