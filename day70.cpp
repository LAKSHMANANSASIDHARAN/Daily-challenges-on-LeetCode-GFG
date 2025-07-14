/*Convert Binary Number in a Linked List to Integer

Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

 

Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string temp="";
        ListNode*tempnode=head;
        while(tempnode!=NULL){
            temp+=to_string(tempnode->val);
            tempnode=tempnode->next;
        }
        cout<<temp<<endl;
        //reverse(temp.begin(),temp.end());
     int ans = 0, pow = 1;
      for (int i = temp.size() - 1; i >= 0; i--) {
    if (temp[i] == '1') {
        ans += pow;
    }
    pow *= 2;
}
        return ans;
    }
};
