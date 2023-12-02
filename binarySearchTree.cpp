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

    void insertIntoBST(node* &root, int d)
    {
        if(root == NULL)
        {
            root = new node(d);
            return;
        }

        if(d>root->data)
        insertIntoBST(root->right, d);
        else
        insertIntoBST(root->left, d);
    }

    void takeInput(node* &root)
    {
        int data;
        cout<<"Enter the data to be entered: ";
        cin>>data;
        while(data != -1)
        {
            insertIntoBST(root, data);
            cout<<"Enter the data to be entered: ";
            cin>>data;
        }
    }

    node* minValue(node* root)
    {
        if(root == NULL)
        return NULL;

        node* temp = root;
        while(temp->left != NULL)
        temp = temp->left;
        return temp;
    }

    node* deleteNode(node* root, int val)
    {
        if(root == NULL)
        return NULL;

        if(root->data == val)
        {
            if(root->left == NULL && root->right == NULL)
            {
               delete root;
               return NULL;
            }

            if(root->left != NULL && root->right == NULL)
            {
                node* temp = root->left;
                delete root;
                return temp;
            }

            if(root->left == NULL && root->right != NULL)
            {
                node* temp = root->right;
                delete root;
                return temp;
            }

            if(root->left != NULL && root->right != NULL)
            {
                int min = minValue(root->right) -> data;
                root->data = min;
                root->right = deleteNode(root->right, min);
                return root;
            }
        }
        else if(root->data > val)
        {
            root->left = deleteNode(root->left, val);
            return root;
        }
        else
        {
            root->right = deleteNode(root->right, val);
            return root;
        }
    }

    void levelOrderTraversal(node* root)
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

};



int main()
{
    node* root = NULL;

   
    root->takeInput(root);

    cout<<"Printing the BST: "<<endl;
    root->levelOrderTraversal(root);

    cout<<"Enter a node to be deleted: ";
    int x;
    cin>>x;
    root = root->deleteNode(root,x);

    cout<<"Printing the BST: "<<endl;
    root->levelOrderTraversal(root);

    return 0;
}