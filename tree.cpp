#include <iostream>
#include <queue>
using namespace std;
class node
{
    public:
        int data;
        node* left;
        node* right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }   

    node* buildTree(node* root)
    {
        int data;
        cout<<"Enter the data: ";
        cin>>data;
        root = new node(data);
        if(data == -1)
            return NULL;
        cout<<"Enter the data to be inserted on the left side of "<<data<<endl;
        root->left = root->left->buildTree(root->left);
        cout<<"Enter the data to be inserted on the right side of "<<data<<endl;
        root->right = root->right->buildTree(root->right);
        return root;
    }

    void levelOrderTraversal(node *root)
    {
        queue <node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            node* temp = q.front();
            q.pop();
            if(temp == NULL)
            {
                cout<<endl;
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                cout<<temp->data<<" ";
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
    }

    void inorderTraversal(node* root)
    {
        if(root == NULL)
        return;

        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);

    }

    void preorderTraversal(node* root)
    {
        if(root == NULL)
        return;

        cout<<root->data<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);

    }

    void postorderTraversal(node* root)
    {
        if(root == NULL)
        return;

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->data<<" ";

    }

};

int main()
{
    node* root = NULL;
    root = root->buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //levelOrderTraversal 
    root->levelOrderTraversal(root);
    cout<<endl;
    root->inorderTraversal(root);
    cout<<endl;
    root->preorderTraversal(root);
    cout<<endl;
    root->postorderTraversal(root);
}