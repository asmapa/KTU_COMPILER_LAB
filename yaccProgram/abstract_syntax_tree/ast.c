#include "ast.h"

// 🧠 Creates an operator node (like '+', '-', '*', '/')
ASTNode* make_node(char op, ASTNode* left, ASTNode* right) {
    ASTNode* node = (ASTNode*) malloc(sizeof(ASTNode));
    node->op = op;
    node->left = left;
    node->right = right;
    node->value = 0; // only operator nodes have 0 as value
    return node;
}

// 🍃 Creates a leaf node (just a number)
ASTNode* make_leaf(int value) {
    ASTNode* node = (ASTNode*) malloc(sizeof(ASTNode));
    node->op = 0;        // leaf nodes have no operator
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    return node;
}

// 🖨️ Prints the AST in post-order traversal
void print_ast(ASTNode* node) {
    if (node->left)
        print_ast(node->left);

    if (node->right)
        print_ast(node->right);

    if (node->op)
        printf("%c ", node->op);
    else
        printf("%d ", node->value);
}
