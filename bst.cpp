#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* FindMin(Node *node) {
    if(node == NULL) {
        return NULL;
    }
    if(node->left)
        return FindMin(node->left);
    else
        return node;
}
Node* FindMax(Node *node) {
    if(node == NULL) {
        return NULL;
    }
    if(node->right) 
        return(FindMax(node->right));
    else
        return node;
}
Node *Insert(Node *node,int data) {
    if(node==NULL) {
        Node *temp;
        temp=new Node;
        temp -> data = data;
        temp -> left = temp -> right = NULL;
        return temp;
    }
    if(data >(node->data)) {
        node->right = Insert(node->right,data);
    }
    else if(data < (node->data)) {
        node->left = Insert(node->left,data);
    }
    return node;
}
Node * Delet(Node *node, int data) {
    Node *temp;
    if(node == NULL) {
        cout<<"Element Not Found";
    }
    else if(data < node->data) {
        node->left = Delet(node->left, data);
    }
    else if(data > node->data) {
        node->right = Delet(node->right, data);
    }
    else {
        if(node->right && node->left){
            temp = FindMin(node->right);
            node -> data = temp->data;
            node -> right = Delet(node->right,temp->data);
        }
        else {
            temp = node;
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;
            free(temp); 
        }
    }
    return node;
}
Node * Find(Node *node, int data) {
    if(node == NULL) {
        return NULL;
    }
    if(data > node->data) {

        return Find(node->right,data);
    }
    else if(data < node->data) {
        return Find(node->left,data);
    }
    else {
        return node;
    }
}
void Inorder(Node *node) {
    if(node == NULL) {
        return;
    }
    Inorder(node->left);
    cout<<node->data<<" ";
    Inorder(node->right);
}
void Preorder(Node *node) {
    if(node==NULL) {
        return;
    }
    cout<<node->data<<" ";
    Preorder(node->left);
    Preorder(node->right);
}
void Postorder(Node *node) {
    if(node == NULL) {
        return;
    }
    Postorder(node->left);
    Postorder(node->right);
    cout<<node->data<<" ";
}
int main() {
    Node *root = NULL,*temp;
    int n;
    while(1) {
        cout << "\n1 - Insert\n";
        cout << "2 - Delete\n";
        cout << "3 - Inorder traversal\n";
        cout << "4 - Preorder traversal\n";
        cout << "5 - Postorder traversal\n";
        cout << "6 - Find Minimum\n";
        cout << "7 - Find Maximum\n";
        cout << "8 - Search\n";
        cout << "9 - Exit\n";
        cout << "Enter choice:";
        cin >> n;
        switch(n) {
        case 1:
            cout<<"Enter element to be insert: ";
            cin>>n;
            root = Insert(root, n);
            cout<<"\nElements in BST are: ";
            Inorder(root);
            break;
        case 2:
            cout<<"Enter element to be deleted: ";
            cin>>n;
            root = Delet(root,n);
            cout<<"\nAfter deletion elements in BST are: ";
            Inorder(root);
            break;
        case 3:
            cout<<"\nInorder Travesals is: ";
            Inorder(root);
            break;
        case 4:
            cout<<"\nPreorder Traversals is: ";
            Preorder(root);
            break;
        case 5:
            cout<<"\nPostorder Traversals is: ";
            Postorder(root);
            break;
        case 6:
            temp = FindMin(root);
            cout<<"\nMinimum element is: "<<temp->data;
            break;
        case 7:
            temp = FindMax(root);
            cout<<"\nMaximum element is: "<<temp->data;
            break;
        case 8:
            cout<<"\nEnter element to be searched:";
            cin>>n;
            temp = Find(root,n);
            if(temp==NULL) {
                cout<<"\nElement is not found";
            }
            else {
                cout<<"\nElement "<<temp->data<<" is Found";
            }
            break;
        case 9:
            exit(0);
            break;
        default:
            cout<<"\nEnter correct choice: ";
            break;
        }
    }
    return 0;
}