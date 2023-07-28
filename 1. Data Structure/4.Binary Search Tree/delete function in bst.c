//26 March, 2020
//Correctly completed the deletion function
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
    while(current && current->left != NULL) {
        current = current->left;
    }
    return current;
}


//Deletion operation in BST
struct node* Delete(struct node* root, int data) {
    if(root == NULL) {
        return root;
    }
    if(data < root->data) {
        root->left = Delete(root->left, data);
    }
    else if(data > root->data){
        root->right = Delete(root->right, data);
    }
    else{
        //Case1: No Child
        if((root->left == NULL) && (root->right == NULL)) {
            free(root);
            root = NULL;
        }
        //Case2: One Child
        else if(root->left == NULL) { /*checking left subtree*/
            struct node* temp;
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) { /*checking right subtree*/
            struct node* temp;
            temp = root->left;
            free(root);
            return temp;
        }
        //Case3: Two Child
        else{
            struct node* temp;
            temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}



int main() {

    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

    insert(50);
    insert(30);
    insert(20);
    insert(40);
    insert(70);
    insert(60);
    insert(80);

    Inorder(root);
    printf("\n\n");

    //int del;
    //printf("Enter delete node: ");
    //scanf("%d", &del);
    Delete(root, 80);
    Inorder(root);
    printf("\n\n");

    Delete(root, 70);
    Inorder(root);
    printf("\n\n");

    Delete(root, 50);
    Inorder(root);
    printf("\n\n");
    return 0;
}
