#include<stdio.h>
#include<stdlib.h>

typedef struct ASTNode{
    char op;
    struct ASTNode *left;
    struct ASTNode *right;
    int val;
}ASTNode;

ASTNode *makeNode(char op,ASTNode *left,ASTNode *right);
ASTNode *makeLeaf(int val);
void printAST(ASTNode *node);
