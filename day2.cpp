/*today I'm very happy to say this because I have solved my tree problem*/
/*Construct Binary Tree from Preorder and Postorder Traversal
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
If there exist multiple answers, you can return any of them.
Example 1:
Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
Example 2:
Input: preorder = [1], postorder = [1]
Output: [1]*/
#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

class tree {
public:
    int val;
    tree* left;
    tree* right;
    tree(int Val) {
        val = Val;
        left = nullptr;
        right = nullptr;
    }
};

void insertLeft(tree* temp, queue<tree*>& q) {
    q.front()->left = temp;
}

void insertRight(tree* temp, queue<tree*>& q) {
    q.front()->right = temp;
}

void printTree(tree* root) {
    if (!root) return;
    queue<tree*> q;
    q.push(root);
    while (!q.empty()) {
        tree* curr = q.front();
        q.pop();
        cout << curr->val << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    vector<int> arr1 = {1, 2, 4, 5, 3, 6, 7}; 
    vector<int> arr2 = {4, 5, 2, 6, 7, 3, 1}; 
    set<int> check;
    queue<tree*> q;
    
    tree* tree1 = new tree(arr1[0]);
    q.push(tree1);
    tree* temp = tree1;
    int count = 0;
    int i = 1, j = 0;

    while (i < arr1.size()) {
        if (check.find(arr2[j]) == check.end()) j++;

        if (arr1[i] != arr2[j] && count == 0) {
            check.insert(arr1[i]);
            tree* temp2 = new tree(arr1[i]);
            insertLeft(temp2, q);
            count++;
            q.push(temp2);
            i++;
            j++;
        } else if (arr1[i] != arr2[j] && count == 1) {
            tree* temp2 = new tree(arr1[i]);
            count = 0;
            insertRight(temp2, q);
            q.pop();
            i++;
            j++;
        } else {
            i++; j++;
        }
    }

    printTree(tree1);
}
