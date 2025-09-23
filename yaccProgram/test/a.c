#include "a.h"

ASTNode *makeNode(char op,ASTNode *left,ASTNode *right){
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->op=op;
    node->left=left;
    node->right=right;
    node->val=0;
    return node;
}

ASTNode *makeLeaf(int val){
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->op=0;
    node->left=NULL;
    node->right=NULL;
    node->val=val;
    return node;
}

void printAST(ASTNode *node){
    if(node->left){
        printAST(node->left);
    }
    if(node->right){
        printAST(node->right);
    }
    if(node->op){
        printf("%c ",node->op);
    }else{
        printf("%d ",node->val);
    }
}