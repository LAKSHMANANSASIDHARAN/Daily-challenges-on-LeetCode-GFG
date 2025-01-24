/*Detect Loop in linked list:
problem stating is they have given the linked list ,that may or may not have loop .So we need to find that is the given Linked list loop or not.
Algorithm is very simple "tortoise and hare" .In simple words fast and slow pointer . Slow will go one step forward while fast will go two step forward in one iteration.
I can sure that two pointers will meet if the given LL are Loop . Otherwise it wouldn't.*/
class Solution {
  public:
  
    bool detectLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow) {// it that two meets ,will return ture
        return true;
    }
}
return false;

    }
};
// Lets Talk about the time complexity is O(n)and space complexity is O(1)

