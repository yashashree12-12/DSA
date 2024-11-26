// A. Construct an expression tree from postfix expression and perform non- recursive
// In-order traversals
#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct TreeNode 
{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* constructTree(const string& postfix) 
{
    stack<TreeNode*> stk;
    
    for (char ch : postfix) 
    {
        if (isalnum(ch)) 
        {
            stk.push(new TreeNode(ch));
        } 
        else 
        {
            TreeNode* node = new TreeNode(ch);
            node->right = stk.top();
            stk.pop();
            node->left = stk.top(); 
            stk.pop();
            stk.push(node);
        }
    }
    return stk.top();
}

void inOrderTraversal(TreeNode* root) 
{ 
    stack<TreeNode*> stk;
    TreeNode* current = root;
    
    while (current != nullptr || !stk.empty()) 
    {
        while (current != nullptr) 
        {
            stk.push(current);
            current = current->left;
        }

        current=stk.top();
        stk.pop();
        cout<<current->val<<" ";
        
        current = current->right;
    }
}

int main()
{
    string postfix;
    cout<<"enter the postfix expression: ";
    cin>>postfix;
    TreeNode* root =constructTree(postfix);

    cout<<"In-order traversal: ";
    inOrderTraversal(root);
    cout<<endl;

    return 0;
}
