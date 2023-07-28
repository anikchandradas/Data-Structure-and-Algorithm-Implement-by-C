//Date: 22 March, 2020
/* operations: insertion operation passing with root,
    traverse, search, findmin, findmax,
    height of a binary tree, size of binary tree
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* A utility function to insert a new node with given data in BST */
struct node* insert(struct node* node, int data)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) {
        return newNode(data);
    }
    /* Otherwise, recur down the tree */
    if (data < node->data) {
        node->left  = insert(node->left, data);
    }
    else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    /* return the (unchanged) node pointer */
    return node;
}

//searching a node in bst
struct node*  search(struct node *root, int item) {
    struct node* t;
    t = root;
    while(t != NULL) {
        if(t->data == item) {
            return t;
        }
        if(item < t->data) {
            t = t->left;
        }
        else{
            t = t->right;
        }

    }
    return t;

}

//Postorder traversal of BST
void Postorder(struct node* t)
{
    if(t-> left != NULL) {
        Postorder(t->left);
    }
    if(t->right != NULL) {
        Postorder(t->right);
    }

    printf("%d ", t->data);
}

//Preorder traversal of BST
void Preorder(struct node* t) {
    printf("%d ", t->data);

    if(t->left != NULL) {
        Preorder(t->left);
    }

    if(t->right != NULL) {
        Preorder(t->right);
    }
}

//Inorder traversal of BST
void Inorder(struct node* t) {
    if(t->left != NULL) {
        Inorder(t->left);
    }

    printf("%d ", t->data);

    if(t->right != NULL) {
        Inorder(t->right);
    }
}


//Find Minimum value in BST
int FindMin(struct node* root) {
    if(root == NULL) {
        printf("Tree is empty.");
        return -1;
    }

    while(root->left != NULL) {
        root = root->left;
    }
    return root->data;

}

//Find Maximum Value
int FindMax(struct node* root) {
    if(root == NULL) {
        printf("Tree is Empty.");
        return -1;
    }

    while(root->right != NULL) {
        root = root->right;
    }
    return root->data;
}


//Size of a Binary Tree or number of nodes in binary tree
int size(struct node* node) {
    if(node == NULL) {
        return 0;
    }
    else{
        return(size(node->left)+1+size(node->right));
    }
}

//Find the Minimum depth or Height of a Binary Tree
int MaxDepth(struct node* node) {
    if(node == NULL) {
        return -1;
    }
    else {
        int lDepth = MaxDepth(node->left);
        int rDepth = MaxDepth(node->right);
        if(lDepth > rDepth) {
            return(lDepth+1);
        }
        else {
            return(rDepth+1);
        }
    }
}


// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // print inoder traversal of the BST
    Postorder(root);
    printf("\n\n");

    Preorder(root);
    printf("\n\n");

    Inorder(root);
    printf("\n\n");

    //searching item
    struct node* t;
    int val;
    printf("Enter value for search: ");
    scanf("%d", &val);
    t = search(root, val);

     if(t != NULL) {
        printf("Found %d\n", t->data);
     }
    else {
    printf("Not Found\n");
    }

    int min, max;

    min = FindMin(root);
    printf("Minimum value: %d\n", min);

    max = FindMax(root);
    printf("Maximum value: %d\n", max);

    int s;
    s = size(root);
    printf("Size = %d\n", s);

    int Depth;
    Depth = MaxDepth(root);
    printf("Depth: %d\n", Depth);

    return 0;
}
