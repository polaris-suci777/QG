#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
#include "LinkStack.h"
// 初始化链栈
Status initLStack(LinkStack* stack) {
    stack->top = NULL;
    stack->count = 0;
    return success;
}

// 判断链栈是否为空
Status isEmptyLStack(LinkStack* stack) {
    if (stack->top==NULL){
        return error;
    }
    else return success;
}

// 得到栈顶元素
Status getTopLStack(LinkStack* stack,ElemType *e) {
    if (isEmptyLStack(stack)==error) {
        printf("Stack is empty, cannot get top element.\n");
        *e=-1;
        return illegal;
    }
    *e=stack->top->data;
    return success;
}

// 清空链栈
Status clearLStack(LinkStack* stack) {
    StackNode* temp;
    while (stack->top != NULL) {
        temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    stack->count = 0;
    return success;
}

// 销毁链栈
Status destroyLStack(LinkStack* stack) {
    clearLStack(stack);
    stack->top = NULL;
    stack->count = 0;
    return success;
}

// 检测链栈长度
Status LStackLength(LinkStack* stack,int *length) {
    *length=stack->count;
    return success;
}

// 入栈操作
Status pushLStack(LinkStack* stack, ElemType data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->count++;
    return success;
}

// 出栈操作
Status popLStack(LinkStack* stack,ElemType *data) {
    if (isEmptyLStack(stack)==error) {
        printf("Stack is empty, cannot pop.\n");
        *data = -1;
        return illegal;
    }
    StackNode* temp = stack->top;
    *data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->count--;
    return success;
}
char MenuText[8][50]={             //菜单
        "链表的基本功能实现",
        "menu1.入栈",
        "menu2.出栈",
        "menu3.得到栈顶元素",
        "menu4.清空栈",
        "menu5.销毁栈",
        "menu6.检测栈长度",
        "menu7.停止",
};
void show(void)     //菜单演示
{
    int i;
    printf("\n=================================================================\n");
    for (i=0;i<8;i++){
        printf("<<%s>>\n",MenuText[i]);
    }
    printf("\n=================================================================\n");
}

    int main() {
        LinkStack stack;
        initLStack(&stack);
        ElemType choice, data,length;
        while (1) {
            show();
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("想要推入什么元素： ");
                    scanf("%d", &data);
                    pushLStack(&stack, data);
                    printf("元素入栈成功\n");
                    break;
                case 2:
                    popLStack(&stack,&data);
                    if (data != -1) {
                        printf("推出元素为： %d\n", data);
                    }
                    break;
                case 3:
                    getTopLStack(&stack,&data);
                    if (data != -1) {
                        printf("栈顶元素为: %d\n", data);
                    }
                    break;
                case 4:
                    clearLStack(&stack);
                    printf("清空栈的元素\n");
                    break;
                case 5:
                    destroyLStack(&stack);
                    printf("摧毁栈\n");
                    isEmptyLStack(&stack); // 重新初始化栈，以便继续操作
                    break;
                case 6:
                    length=LStackLength(&stack,&length);
                    printf("栈的个数为: %d\n", length);
                    break;
                case 7:
                    printf("停止\n");
                    exit(0);
                default:
                    printf("不合法的操作，请再输入一遍.\n");
                    break;
            }
        }
}