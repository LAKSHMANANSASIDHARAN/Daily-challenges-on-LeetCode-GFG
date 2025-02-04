/*Maximum Ascending Subarray Sum
They have given array that has some subarray with ascending order we need to find which subarray has maximum sum!!
Its sounds like easy. But do this in O(n) is a task;
Lets see the exmaple
Example 1:
Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.
Example 2:
Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.
Example 3:
Input: nums = [12,17,15,13,10,11,12]
Output: 33
Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.
*/
int maxAscendingSum(vector<int>& arr) {
      int i=0;int j=1;
      int sum=arr[i];
      int maxi=arr[i];
      while(j<arr.size()){
        if(arr[i]<arr[j]){ // if we found ascending subarray do the sum 
            sum+=arr[j];
            i++;
            j++;
           
        }
        else{ // if not make sum as 0 change the i as j and increment the j ;
           i=j;
           sum=0;
           sum+=arr[j];
           j++;
        }
         maxi=max(maxi,sum); //find the maximum
      }  
      return maxi;
    }
