#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status         //��ʾ��ǰ�����ʵ��״̬
{
    error = 0,
	success = 1,
    illegal = -1
} Status;

typedef int ElemType;

typedef  struct StackNode       // ������ջ�ڵ�ṹ��
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack          // ������ջ�ṹ��
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//��ջ
Status initLStack(LinkStack *stack);//��ʼ��ջ
Status isEmptyLStack(LinkStack *stack);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack *stack,ElemType *e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack *stack);//���ջ
Status destroyLStack(LinkStack *stack);//����ջ
Status LStackLength(LinkStack *stack,int *length);//���ջ����
Status pushLStack(LinkStack *stack,ElemType data);//��ջ
Status popLStack(LinkStack *stack,ElemType *data);//��ջ


#endif 
