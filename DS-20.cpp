#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int height;
    struct Node *left, *right;
} Node;

int height(Node *n) { return n ? n->height : 0; }
int max(int a, int b) { return a > b ? a : b; }

Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) { printf("Memory allocation failed\n"); exit(1); }
    node->key = key; node->left = node->right = NULL; node->height = 1;
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(Node* n) { return n ? height(n->left) - height(n->right) : 0; }

Node* insertNode(Node* node, int key) {
    if (!node) return newNode(key);
    if (key < node->key) node->left = insertNode(node->left, key);
    else if (key > node->key) node->right = insertNode(node->right, key);
    else return node; // duplicate keys not allowed

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // LL
    if (balance > 1 && key < node->left->key) return rightRotate(node);
    // RR
    if (balance < -1 && key > node->right->key) return leftRotate(node);
    // LR
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RL
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

Node* minValueNode(Node* node) {
    Node* cur = node;
    while (cur && cur->left) cur = cur->left;
    return cur;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        // node with one or no child
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) { // no child
                free(root);
                return NULL;
            } else { // one child
                Node* t = temp;
                free(root);
                return t;
            }
        } else {
            // node with two children: get inorder successor
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node
    if (!root) return root;

    // update height and rebalance
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) { root->left = leftRotate(root->left); return rightRotate(root); }
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) { root->right = rightRotate(root->right); return leftRotate(root); }

    return root;
}

Node* searchNode(Node* root, int key) {
    if (!root || root->key == key) return root;
    return (key < root->key) ? searchNode(root->left, key) : searchNode(root->right, key);
}

void preOrder(Node* root) {
    if (root) { printf("%d ", root->key); preOrder(root->left); preOrder(root->right); }
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    printf("Preorder traversal: ");
    preOrder(root); printf("\n");

    root = deleteNode(root, 40);
    printf("After deleting 40: ");
    preOrder(root); printf("\n");

    printf("Search 25: %s\n", searchNode(root, 25) ? "Found" : "Not Found");
    return 0;
}

