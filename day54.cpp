/*Max Difference You Can Get From Changing an Integer
You are given an integer num. You will apply the following steps to num two separate times:
Pick a digit x (0 <= x <= 9).
Pick another digit y (0 <= y <= 9). Note y can be equal to x.
Replace all the occurrences of x in the decimal representation of num by y.
Let a and b be the two results from applying the operation to num independently.
Return the max difference between a and b.
Note that neither a nor b may have any leading zeros, and must not be 0.
Example 1:
Input: num = 555
Output: 888
Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
The second time pick x = 5 and y = 1 and store the new integer in b.
We have now a = 999 and b = 111 and max difference = 888
Example 2:
Input: num = 9
Output: 8
Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
The second time pick x = 9 and y = 1 and store the new integer in b.
We have now a = 9 and b = 1 and max difference = 8*/
class Solution {
public:
    int maxDiff(int num) {
       string s=to_string(num);
       string maxi="",mini="";
        string maxnum=s,minnum=s;
       for(auto i:s){
        if(i!='9'){
            maxi=i;
            break;
        }
       }
       if(s[0]!='1')
       { mini=s[0];
       for(auto &i:minnum){
        if(i==mini[0]){
            i='1';
        }
      }
       }
     else{
       for(int i=1;i<s.size();i++){
        if(s[i]!='1'&&s[i]!='0'){
            mini=s[i];
            break;
        }
       }
        for(auto &i:minnum){
        if(i==mini[0]){
            i='0';
        }
      }
     }
     
      for(auto &i:maxnum){
        if(i==maxi[0]){
            i='9';
        }
      }
       
    int a =stoi(maxnum),b=stoi(minnum);
    return a-b;
    }
};
