//22 march, 2020
/* Functions correctly completed:
   insert, search, in-order, pre-order, post-order,
   find minimum, find maximum,
   Size of a Binary Tree or number of nodes in binary tree
   Find the Minimum depth or Height of a Binary Tree.
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* root = NULL;

//Insertion of a Node in BST
struct node* insert(int d) {
    struct node *t, *parrent;
    t = (struct node*)malloc(sizeof(struct node));

    t->data = d;
    t->left = NULL;
    t->right = NULL;

    parrent = root;

    if(root == NULL) {
        root = t;
    }
    else {
        struct node* curr;
        curr = root;
        //Traversing for find the parrent
        while(curr) {
            parrent = curr;
            if(t->data > curr->data) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }
        //Insertion of node after finding the parrent
        if(t->data > parrent->data) {
            parrent->right = t;
        }
        else {
            parrent->left = t;
        }
    }
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
struct node* FindMin(struct node* root) {
   struct node* current;
   current = root;
   //while((current != NULL) && (current->left != NULL))
   while(current && current->left != NULL) {
    current = current->left;
   }
   return current;
}

//Find Maximum Value
struct node* FindMax(struct node* root) {
   struct node* current;
   current = root;

   while(current && current->right != NULL) {
    current = current->right;
   }
   return current;
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

int main() {

    insert(50);
    insert(30);
    insert(20);
    insert(40);
    insert(70);
    insert(60);
    insert(80);

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

    struct node* min;
    min = FindMin(root);
    printf("Minimum value: %d\n", min->data);

    struct node* max;
    max = FindMax(root);
    printf("Maximum value: %d\n", max->data);

    int s;
    s = size(root);
    printf("Size = %d\n", s);

    int Depth;
    Depth = MaxDepth(root);
    printf("Depth: %d\n", Depth);

    return 0;
}
