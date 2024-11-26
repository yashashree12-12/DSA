// B. Construct an expression tree from postfix expression and perform non- recursive
// In-order, pre-order and post-order traversals.

#include<iostream>
#include<stack>
using namespace std;

struct treeNode
{
    char value;
    treeNode* left;
    treeNode* right;

    treeNode(char val)
    {
        value = val;
        left= right=nullptr;
    }

};

treeNode* constructTree(const string& postfix) 
{
    stack<treeNode*> stk;
    
    for (char ch : postfix) 
    {
        if (isalnum(ch)) 
        {
            stk.push(new treeNode(ch));
        } 
        else 
        {
            treeNode* node = new treeNode(ch);
            node->right = stk.top();
            stk.pop();
            node->left = stk.top(); 
            stk.pop();
            stk.push(node);
        }
    }
    return stk.top();
}

void inorder(treeNode* root)
{
    stack<treeNode*>s;
    treeNode* current=root;

    while(current !=nullptr || !s.empty())
    {
        while(current != nullptr)
        {
            s.push(current);
            current = current->left;
        }
        current=s.top();
        s.pop();
        cout<<current->value<<" ";
        current=current->right;
    }
}

void preorder(treeNode* root)
{
    if(!root) return;
    stack<treeNode*>s;
    s.push(root);

    while(!s.empty())
    {
        treeNode* current =s.top();
        s.pop();
        cout<<current->value<<" ";

        if(current->right) s.push(current->right);
        if(current->left) s.push(current->left);
    }
}

void postOrder(treeNode* root)
{
    if(!root) return;

    stack<treeNode*>s1,s2;
    s1.push(root);

    while(!s1.empty())
    {
        treeNode* current =s1.top();
        s1.pop();
        s2.push(current);

        if(current->left) s1.push(current->left);
        if(current->right) s1.push(current->right);
    }

    while(!s2.empty())
    {
        cout<<s2.top()->value <<" ";
        s2.pop();
    }
}

int main()
{
    string postfix="ab+cde+**";
    treeNode* root=constructTree(postfix);

    cout<<"In-order Traversal: ";
    inorder(root);
    cout<<endl;

    cout<<"Pre-order Traversal: ";
    preorder(root);
    cout<<endl;

    cout<<"Post-order Traversal: ";
    postOrder(root);
    cout<<endl;

    return 0;

}