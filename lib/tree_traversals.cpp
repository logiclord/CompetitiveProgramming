#include <stdio.h>
#include <stdlib.h>
#include<stack>
#include<iostream>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return(node);
}

/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void printPostorder(struct node* node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    printf("%d ", node->data);
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    printf("%d ", node->data);

    /* now recur on right child */
    printInorder(node->right);
}

/* Given a binary tree, print its nodes in inorder*/
void printPreorder(struct node* node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    printf("%d ", node->data);

    /* then recur on left sutree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}


void printPreorderItr(struct node* root)
{
    stack<node *> pendingStack;
    while(root!=NULL || !pendingStack.empty())
    {
        if(root!=NULL)
        {
            printf("%d ", root->data);
            if(root->right != NULL)
                pendingStack.push(root->right);
            root = root->left;
        }
        else
        {
            root = pendingStack.top();
            pendingStack.pop();
        }
    }
}


void printInorderItr(struct node* root)
{
    stack<node *> parentStack;
    while(root!=NULL || !parentStack.empty())
    {
        if(root!=NULL)
        {
            parentStack.push(root);
            root = root->left;
        }
        else
        {
            root = parentStack.top();
            parentStack.pop();
            printf("%d ", root->data);
            root = root->right;
        }
    }
}

void printPostorderItr(struct node* root)
{
    struct node * prev = NULL, *cur = NULL;
    stack<node *> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        cur = pendingNodes.top();
        if(prev==NULL || prev->left==cur || prev->right ==cur)
        {
            if(cur->left!=NULL)
            {
                pendingNodes.push(cur->left);
            }
            else if(cur->right != NULL)
            {
                pendingNodes.push(cur->right);
            }
            else
            {
                printf("%d ", cur->data);
                pendingNodes.pop();
            }
        }
        else if(prev == cur->left)
        {
            if(cur->right != NULL)
            {
                pendingNodes.push(cur->right);
            }
            else
            {
                printf("%d ", cur->data);
                pendingNodes.pop();
            }
        }
        else if(prev == cur->right)
        {
            printf("%d ", cur->data);
            pendingNodes.pop();
        }
        prev = cur;
    }
}

void printPreorderMorris(struct node * root)
{
    while(root!=NULL)
    {
        if(root->left == NULL)
        {
            printf("%d ", root->data);
            root = root->right;
        }
        else
        {
            struct node * temp = root->left;
            while(temp->right!=NULL && temp->right!=root)
            {
                temp = temp->right;
            }

            if(temp->right == NULL)
            {
                printf("%d ", root->data);
                temp->right = root;
                root = root->left;
            }
            else if(temp->right == root)
            {
                temp->right = NULL;
                root = root->right;
            }
        }
    }
}


void printInorderMorris(struct node * root)
{
    while(root!=NULL)
    {
        if(root->left == NULL)
        {
            printf("%d ", root->data);
            root = root->right;
        }
        else
        {
            struct node * temp = root->left;
            while(temp->right!=NULL && temp->right!=root)
            {
                temp = temp->right;
            }

            if(temp->right == NULL)
            {
                temp->right = root;
                root = root->left;
            }
            else if(temp->right == root)
            {
                printf("%d ", root->data);
                temp->right = NULL;
                root = root->right;
            }
        }
    }
}

void printPreorderParent(struct node * root)
{
    while(root!=NULL)
    {
        printf("%d ", root->data);
        if(root->left!=NULL)
            root = root->left;
        else if(root->right!=NULL)
            root = root->right;
        else
        {
            //struct node * temp = root->parent;
            while(root!=NULL)
            {
                if(root->parent!=NULL && root->parent->left == root && root->parent->right!=NULL)
                {
                    root = root->parent->right;
                    break;
                }
                root = root->parent;
            }
        }
    }
}


void printInorderParent(struct node * root)
{
    while(root!=NULL)
    {
        if(root->left!=NULL)
            root = root->left;
        else if(root->right!=NULL)
            root = root->right;
        else
        {
            printf("%d ", root->data);
            while(root!=NULL)
            {
                if(root->parent!=NULL && root->parent->left == root && root->parent->right!=NULL)
                {
                    printf("%d ", root->parent->data);
                    root = root->parent->right;
                    break;
                }
                root = root->parent;
            }
        }
    }
}


void printPostorderParent(struct node * root)
{
    while(root!=NULL)
    {
        if(root->left!=NULL)
            root = root->left;
        else if(root->right!=NULL)
            root = root->right;
        else
        {
            printf("%d ", root->data);
            while(root!=NULL)
            {
                if(root->parent!=NULL && root->parent->left == root && root->parent->right!=NULL)
                {
                    root = root->parent->right;
                    break;
                }
                else if(root->parent!=NULL && root->parent->right == root )
                {
                    printf("%d ", root->parent->data);
                }
                root = root->parent;
            }
        }
    }
}

int main()
{
    struct node *root  = newNode(1);
    root->parent = NULL;
    root->left             = newNode(2);
    root->left->parent = root;
    root->right           = newNode(3);
    root->right->parent = root;
    root->left->left     = newNode(4);
    root->left->left->parent =  root->left;
    root->left->right   = newNode(5);
    root->left->right->parent =     root->left;

    printf("\n Preorder traversal of binary tree is \n");
    printPreorderItr(root);
    printf("\n");
    printPreorder(root);
    printf("\n");
    printPreorderMorris(root);
    printf("\n");
    printPreorderParent(root);


    printf("\n Inorder traversal of binary tree is \n");
    printInorderItr(root);
    printf("\n");
    printInorder(root);
    printf("\n");
    printInorderMorris(root);
    printf("\n");
    printInorderParent(root);
    printf("\n Postorder traversal of binary tree is \n");
    printPostorderItr(root);
    printf("\n");
    printPostorder(root);
    printf("\n");
    printPostorderParent(root);
    getchar();
    return 0;
}
