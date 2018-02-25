#include <iostream>
#include <queue>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};
node *enter(int num1){
    node *newnode = new node;
    newnode->data = num1;
    newnode->left = NULL;
    newnode->right = NULL;
}
void levelOrder(node *root){
    queue <node *> q1,q2;
    q1.push(root);
    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            if(q1.front()->left != NULL)
                q2.push(q1.front()->left);

            if(q1.front()->right != NULL)
                 q2.push(q1.front()->right);
            cout<<q1.front()->data<<"\t";
            q1.pop();
        }
        while (!q2.empty())
        {
            if (q2.front()->left != NULL)
                q1.push(q2.front()->left);

            if (q2.front()->right != NULL)
                q1.push(q2.front()->right);

            cout << q2.front()->data << " ";
            q2.pop();
        }
    }
}
int main()
{
    node *root = enter(8);
    root->left = enter(10);
    root->right = enter(3);
    root->left->left = enter(4);
    root->left->right = enter(5);
    root->right->right = enter(6);

    levelOrder(root);
    return 0;
}
