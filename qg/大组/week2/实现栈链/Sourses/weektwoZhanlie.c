#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
#include "LinkStack.h"
// ��ʼ����ջ
Status initLStack(LinkStack* stack) {
    stack->top = NULL;
    stack->count = 0;
    return success;
}

// �ж���ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* stack) {
    if (stack->top==NULL){
        return error;
    }
    else return success;
}

// �õ�ջ��Ԫ��
Status getTopLStack(LinkStack* stack,ElemType *e) {
    if (isEmptyLStack(stack)==error) {
        printf("Stack is empty, cannot get top element.\n");
        *e=-1;
        return illegal;
    }
    *e=stack->top->data;
    return success;
}

// �����ջ
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

// ������ջ
Status destroyLStack(LinkStack* stack) {
    clearLStack(stack);
    stack->top = NULL;
    stack->count = 0;
    return success;
}

// �����ջ����
Status LStackLength(LinkStack* stack,int *length) {
    *length=stack->count;
    return success;
}

// ��ջ����
Status pushLStack(LinkStack* stack, ElemType data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->count++;
    return success;
}

// ��ջ����
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
char MenuText[8][50]={             //�˵�
        "����Ļ�������ʵ��",
        "menu1.��ջ",
        "menu2.��ջ",
        "menu3.�õ�ջ��Ԫ��",
        "menu4.���ջ",
        "menu5.����ջ",
        "menu6.���ջ����",
        "menu7.ֹͣ",
};
void show(void)     //�˵���ʾ
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
                    printf("��Ҫ����ʲôԪ�أ� ");
                    scanf("%d", &data);
                    pushLStack(&stack, data);
                    printf("Ԫ����ջ�ɹ�\n");
                    break;
                case 2:
                    popLStack(&stack,&data);
                    if (data != -1) {
                        printf("�Ƴ�Ԫ��Ϊ�� %d\n", data);
                    }
                    break;
                case 3:
                    getTopLStack(&stack,&data);
                    if (data != -1) {
                        printf("ջ��Ԫ��Ϊ: %d\n", data);
                    }
                    break;
                case 4:
                    clearLStack(&stack);
                    printf("���ջ��Ԫ��\n");
                    break;
                case 5:
                    destroyLStack(&stack);
                    printf("�ݻ�ջ\n");
                    isEmptyLStack(&stack); // ���³�ʼ��ջ���Ա��������
                    break;
                case 6:
                    length=LStackLength(&stack,&length);
                    printf("ջ�ĸ���Ϊ: %d\n", length);
                    break;
                case 7:
                    printf("ֹͣ\n");
                    exit(0);
                default:
                    printf("���Ϸ��Ĳ�������������һ��.\n");
                    break;
            }
        }
}