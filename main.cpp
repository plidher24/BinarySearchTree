#include <iostream>
#include <climits>
using namespace std;


struct Node {
    int data;                //build to store nodes for binary search tree
    Node *left, *right;
};
Node* createNode(int integers)
{
    Node* treenode = new Node;
    treenode->left =
    treenode->right =
            nullptr;
    treenode->data = integers;

    return treenode;
}
Node* insert(Node* parent, int integers)     //allows to insert a node into the bst
{
    if (parent == nullptr)
        return createNode(integers);      //create new node if the root = null

    if (integers < parent->data)
        parent->left = insert(parent->left, integers);      //compare node to parent. If less than place as left child
    else                                                        //if greater than parent place as right child
        parent->right = insert(parent->right, integers);

    return parent;    //return parent
}

void inordertraversal(Node* parent)     //in-order traversal function
{
    if (parent == nullptr)
        return;

    inordertraversal(parent->left);
    cout << parent->data << " ";
    inordertraversal(parent->right);
}


int kthSmallestElement(Node* parent, int *currentnode, int kthelement)      //Find the kth smallest element in the BST
{
    if (parent == nullptr)
        return INT_MAX;
    int leftnode = kthSmallestElement(parent->left, currentnode, kthelement);
    if (++*currentnode == kthelement)
        return parent->data;
    if (leftnode != INT_MAX)
        return leftnode;
    return kthSmallestElement(parent->right, currentnode, kthelement);
}

int kthSmallestElement(Node* parent, int kthelement)
{
    int currentnode = 0;         //set current nodes to zero. Current node will keep track of nodes past so far to find kth smallest element
    return kthSmallestElement(parent, &currentnode, kthelement); //return parent root, current node, and kthsmallest element
}
void print();

int main()
{
    int c;
    cout << "Please enter an integer for the k-th smallest element: ";      //input for user to see what kth smallest element they want to see
    cin >> c;
    Node* parent = nullptr;  //null pointer
    int key[] = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99 };   //array of integers given
    for (int integers : key)
        parent = insert(parent, integers);
    int kthelement = c;                          //set input integer to the kth element
    int result = kthSmallestElement(parent, kthelement);

    if (result != INT_MAX)   // INT MAX = Maximum value for a variable of type int
        cout << result;
    else
        cout << "Error. Please type in an enter an integer for the k-th smallest element "; //catch errors if kth integer input is not correctly given

    cout<<"\nIn-Order traversal of the BST displayed below: ";    //print BST in in-order traversal style
    inordertraversal(parent);

    cout<<"\n65 is median ";  //state the median
    return 0;
}