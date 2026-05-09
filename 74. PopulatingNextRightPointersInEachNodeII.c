#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

struct Node *newNode(int val) {
    struct Node *node = malloc(sizeof(*node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
    return node;
}

struct Node *connect(struct Node *root) {
    struct Node *currentLevel = root;

    while (currentLevel != NULL) {
        struct Node dummy;
        dummy.val = 0;
        dummy.next = NULL;
        dummy.left = NULL;
        dummy.right = NULL;
        struct Node *tail = &dummy;

        while (currentLevel != NULL) {
            if (currentLevel->left != NULL) {
                tail->next = currentLevel->left;
                tail = tail->next;
            }
            if (currentLevel->right != NULL) {
                tail->next = currentLevel->right;
                tail = tail->next;
            }
            currentLevel = currentLevel->next;
        }

        currentLevel = dummy.next;
    }

    return root;
}

static void printByNext(struct Node *root) {
    struct Node *levelStart = root;
    while (levelStart != NULL) {
        struct Node *curr = levelStart;
        levelStart = NULL;

        while (curr != NULL) {
            printf("%d ", curr->val);
            if (levelStart == NULL) {
                if (curr->left != NULL) levelStart = curr->left;
                else if (curr->right != NULL) levelStart = curr->right;
            }
            curr = curr->next;
        }
        printf("#\n");
    }
}

int main(void) {
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(7);

    connect(root);
    printByNext(root);

    return 0;
}
