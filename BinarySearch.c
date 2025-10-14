#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}


void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int search(struct Node* root, int value) {
    if (root == NULL) 
        return 0;  
    if (root->data == value) 
        return 1;  
    if (value < root->data) 
        return search(root->left, value);
    else
        return search(root->right, value);
}


struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) return root;
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, value, n, val;
    
        printf("\nMenu:\n");
        printf("1. Insert\n2. Search\n3. View\n4. Delete\n5. Exit\n");
     while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice==1)
               {
                printf("\nEnter total number of values to insert: ");
                scanf("%d", &n);
                printf("Enter Values:");
                for (int i = 1; i <= n; i++) {
                    scanf("%d", &value);
                    root = insert(root, value);
                }
                
               }
        else if (choice==2)
                      {
                        printf("\nEnter value to search: ");
                       scanf("%d", &val);
                       if (search(root, val))
                          printf("%d found in BST.\n", val);
                     else
                             printf("%d not found in BST.\n", val);
                       
                      }
         else if(choice==3)
                { 
                printf("\nInorder Traversal: ");
                inorder(root);
                printf("\nPreorder Traversal: ");
                preorder(root);
                printf("\nPostorder Traversal: ");
                postorder(root);
                printf("\n");
                
                }
         else if(choice==4)
                { 
                printf("\nEnter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                
                }
         else if(choice==5)
                { 
                printf("\nExiting...\n");
                exit(0);  
                }
           else         
                {
                printf("Invalid choice!\n");
        }
    }

    return 0;
}































