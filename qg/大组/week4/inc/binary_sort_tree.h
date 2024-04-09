//
// Created by eke_l on 2021/4/21.
//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int

typedef int ElemType;

typedef struct Node{
    ElemType value;
    struct Node *left, *right;
}Node,*NodePtr;

typedef struct BinarySortTree{
    NodePtr root;
}BinarySortTree,*BinarySortTreePtr;

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr T){
    T->root = NULL;
    return true;
}

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr T, ElemType e){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) return failed;
    newNode->value = e;
    newNode->left = newNode->right = NULL;
    Node **p = &(T->root);
    while (*p) {
        if (e < (*p)->value) {
            p = &((*p)->left);
        } else {
            p = &((*p)->right);
        }
    }
    *p = newNode;
    return true;
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr T, ElemType e){
    Node **p = &(T->root);
    Node *q;
    while (*p && (*p)->value != e) {
        if (e < (*p)->value) {
            p = &((*p)->left);
        } else {
            p = &((*p)->right);
        }
    }
    if (!*p) return failed;
    q = *p;
    *p = (*p)->left;
    free(q);
    return true;

}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr T, ElemType e){
    Node *p = T->root;
    while (p) {
        if (p->value == e) {
            return true;
        } else if (e < p->value) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return failed;
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(NodePtr T, void (*visit)(NodePtr))//非递归实现
{
    Node *stack[100], *p = T;
    int top = -1;
    while (p || top != -1) {
        while (p) {
            visit(p);
            stack[++top] = p;
            p = p->left;
        }
        if (top != -1) {
            p = stack[top--];
            p = p->right;
        }
    }
    return true;
}

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(NodePtr T, void (*visit)(NodePtr))//递归实现
{
    if(T==NULL){
        return true;
    }
    if (T!=NULL) {
        visit(T);
        BST_preorderR(T->left, visit);
        BST_preorderR(T->right, visit);
    }
}

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(NodePtr T, void (*visit)(NodePtr)){
    Node *stack[100], *p = T;
    int top = -1;
    while (p || top != -1) {
        while (p) {
            stack[++top] = p;
            p = p->left;
        }
        if (top != -1) {
            p = stack[top--];
            visit(p);
            p = p->right;
        }
    }
    return true;
}

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(NodePtr T, void (*visit)(NodePtr)){
    if(T==NULL){
        return true;
    }
    if (T!=NULL) {
        BST_preorderR(T->left, visit);
        visit(T);
        BST_preorderR(T->right, visit);
    }
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(NodePtr T, void (*visit)(NodePtr)){
    if (T == NULL) {
        return true;
    }
    NodePtr stack[100], prev = NULL, curr;
    int top = -1;
    stack[++top] = T;
    while (top != -1) {
        curr = stack[top--];
        // 如果当前节点没有左孩子或右孩子，或者它的左孩子和右孩子都已经访问过�?
        if ((curr->left == NULL && curr->right == NULL) ||
            (prev != NULL && (prev == curr->left || prev == curr->right))) {
            visit(curr);
            prev = curr;
        } else {
            // 否则先将右孩子入栈，再左孩子入栈
            if (curr->right != NULL) {
                stack[++top] = curr->right;
            }
            if (curr->left != NULL) {
                stack[++top] = curr->left;
            }
        }
    }

}

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(NodePtr T, void (*visit)(NodePtr)){
    if(T==NULL){
        return true;
    }
    if (T!=NULL) {
        BST_preorderR(T->left, visit);
        visit(T);
        BST_preorderR(T->right, visit);
    }
}

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(NodePtr T, void (*visit)(NodePtr)){
    if (!T) return true;
    Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = T;
    while (front < rear) {
        Node *p = queue[front++];
        visit(p);
        if (p->left) queue[rear++] = p->left;
        if (p->right) queue[rear++] = p->right;
    }

}
// 访问节点函数（打印节点值）
void visitNode(Node *node) {
    printf("%d ", node->value);
}
// 释放二叉树节点的内存
void freeTreeNode(NodePtr node) {
    if (node == NULL) {
        return;
    }

    // 先释放左子树
    freeTreeNode(node->left);
    // 再释放右子树
    freeTreeNode(node->right);

    // 最后释放当前节点
    free(node);
}

// 释放整个二叉树的内存
void freeTree(NodePtr root) {
    freeTreeNode(root);
}


