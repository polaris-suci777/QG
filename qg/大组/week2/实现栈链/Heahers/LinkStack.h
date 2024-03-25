#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status         //表示当前代码的实现状态
{
    error = 0,
	success = 1,
    illegal = -1
} Status;

typedef int ElemType;

typedef  struct StackNode       // 定义链栈节点结构体
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack          // 定义链栈结构体
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//链栈
Status initLStack(LinkStack *stack);//初始化栈
Status isEmptyLStack(LinkStack *stack);//判断栈是否为空
Status getTopLStack(LinkStack *stack,ElemType *e);//得到栈顶元素
Status clearLStack(LinkStack *stack);//清空栈
Status destroyLStack(LinkStack *stack);//销毁栈
Status LStackLength(LinkStack *stack,int *length);//检测栈长度
Status pushLStack(LinkStack *stack,ElemType data);//入栈
Status popLStack(LinkStack *stack,ElemType *data);//出栈


#endif 
