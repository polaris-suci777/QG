#include <stdio.h>
#include "stdlib.h"
#include <conio.h>
//#include "LinkStack.h"
typedef char ElemType;
typedef struct StackNode        //压栈和出栈都在栈顶进行(这里的栈顶指前一段)
{
    ElemType data;;//数据
    struct node* next;//指针
}StackNode,*LinkStackPtr;
typedef struct seqstack
{
    int count;              //记录栈的大小
    StackNode* top;         //指向栈顶元素
}phead;
phead*  initstack()//创建栈
{
    phead* istack=(phead*)malloc(sizeof(phead));//为头节点分配空间
    if(istack!=NULL)//健壮性判断
    {
        istack->top=NULL;
        istack->count=0;
    }
    return istack;
}
int isempty(phead* istack)//判断栈为空
{
    if(istack->top==NULL)
    {
        return 1;//栈为空
    }
    return 0;//栈不为空
}
StackNode* getTopLStack(phead* istack)//获取栈顶元素的数据节点
{
    if(istack->count!=0)//栈不为空
    {
        return istack->top;//返回的是栈顶的数据节点而不是栈顶的元素
    }
    return NULL;
}
StackNode* seqstack_pop(phead* istack)//弹出栈顶元素
{
    if(isempty(istack)==0)//栈不为空
    {
        StackNode* account=istack->top;//记录栈顶的数据节点
        istack->top=istack->top->next;//指向栈顶下一个元素
        istack->count--;//记录栈的大小
        return account;//返回弹出的数据节点
    }
    return NULL;
}
void seqstack_push(phead* istack,char x)//压栈(入栈)
{
    StackNode* temp;//进行压栈的数据节点
    temp=(StackNode*)malloc(sizeof(StackNode));
    temp->data=x;//填充数据域
    temp->next=istack->top;//连接栈顶的数据节点
    istack->top=temp;//充当栈顶
    istack->count++;//记录栈大小的变化
    return;
}
//下面是中缀表达式转后缀表达式的函数
char buffer[256]={0};//即对数组中每个数据都初始化为'\0'(\0的ascill码是0)
//buffer为结果串
void char_put(char ch)//用来将字符放入放入结果串
{
    static int index=0;//static定义静态变量,放函数中表示index只初始化一次,只保留index的改变
    buffer[index++]=ch;
}
int priority(char ch)//用来比较优先级
{
    int ret=0;
    switch(ch)
    {
        case '+'://case穿透,即上一个case没有break语句时会继续向下执行
        case '-':
            ret=1;
            break;
        case '*':
        case '/':
            ret=2;
            break;
    }
    return ret;
}
int is_number(char ch)//是不是数字
{
    return(ch>='0'&&ch<='9');//数字返回1，否则返回0
}
int is_operator(char ch)//是不是运算符
{
    return(ch=='+'||ch=='-'||ch=='*'||ch=='/');
}
int is_left(char ch)//是不是左括号
{
    return(ch=='(');
}
int is_right(char ch)//是不是右括号
{
    return(ch==')');
}
int is_letter(char ch){
    return(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z');
}
int transform(char str[])//使用const保护数据,函数用来将中缀转换成后缀
{
    phead* istack=initstack();//创建一个栈
    int i=0;
    while(str[i]!='\0')//遍历整个字符串
    {
        //判断是不是字母
        if(is_letter(str[i])==1) {
        return -1;
        }
        //判断是不是数字
        else if(is_number(str[i])==1)
        {
            if(is_number(str[i+1])==1)//后面1也是数字,则直接放
            {
                char_put(str[i]);//数字直接放入结果串(即输出)
            }
            else//后面不是数字,添加一个空格作为分隔符
            {
                char_put(str[i]);
                char_put(' ');
            }
        }
        else if(is_operator((str[i]))==1)
        {
            if(str[i+1]=='0'&&str[i]=='/')
            {
                printf("ILLEGAL");
                return 0;
            }
            if(isempty(istack)==0)//栈不为空
            {
                while((isempty(istack)==0)&&(priority(str[i])<=(priority(getTopLStack(istack)->data))))//栈不为空并且新运算符优先级不高于栈顶
                {
                    char_put(seqstack_pop(istack)->data);//满足条件的栈顶就弹出直到不满足条件
                    char_put(' ');
                }
            }
            seqstack_push(istack,str[i]);//再将该运算符入栈
        }
        else if(is_left(str[i]))//左括号直接入栈
        {
            seqstack_push(istack,str[i]);
        }
        else if(is_right(str[i]))//判断是不是右括号
        {
            while(is_left(getTopLStack(istack)->data)!=1)//栈顶不是左括号的情况
            {
                char_put(seqstack_pop(istack)->data);//弹出并存储到结果串
                if(isempty(istack)==1)//栈为空仍未找到左括号
                {
                    printf("没有匹配到左括号\n");
                    return -1;
                }
            }
            //此时匹配到了左括号
            seqstack_pop(istack);
            //弹出左括号,这里并不用保存,即两个括号相抵消
        }
        else
        {
            printf("有不能识别的字符\n");
            return -1;
        }
        i++;
    }
    //遍历完了已经
    if(str[i]=='\0')//成功遍历到字符串末尾
    {
        while(isempty(istack)==0)//弹出全部栈中元素
        {
            if(getTopLStack(istack)->data=='(')//栈顶元素为左括号
            {
                printf("有没有匹配到的'(',缺少')'\n");
                return -1;
            }
            char_put(seqstack_pop(istack)->data);//将栈中元素放入最终串
        }
    }
    /*else
    {
        printf("遍历没有完成！\n");
    }*/
    return 1;
}

//下方为计算后缀表达式需要的函数
typedef struct node1//这里的栈是整型栈
{
    int val;//数据
    struct node1* next;//指针
}StackNode1;
typedef struct seqstack1
{
    int size;//记录栈的大小
    StackNode1* top;//指向栈顶元素
}phead1;
phead1*  initstack1()//创建栈
{
    phead1* istack=(phead1*)malloc(sizeof(phead1));//为头节点分配空间
    if(istack!=NULL)//健壮性判断
    {
        istack->top=NULL;
        istack->size=0;
    }
    return istack;
}
int isempty1(phead1* istack)//判断栈为空
{
    if(istack->top==NULL)
    {
        return 1;//栈为空
    }
    return 0;//栈不为空
}
int seqstack_top1(phead1* istack)//获取栈顶元素
{
    if(istack->size!=0)//栈不为空
    {
        return istack->top->val;//返回的是栈顶的数据
    }
    return 99999;
}
int seqstack_pop1(phead1* istack)//弹出栈顶元素
{
    if(isempty1(istack)==0)//栈不为空
    {
        int account=istack->top->val;//记录栈顶的数据节点
        istack->top=istack->top->next;//指向栈顶下一个元素
        istack->size--;//记录栈的大小
        return account;//返回弹出的数据节点
    }
    return 99999;
}
void seqstack_push1(phead1* istack,int x)//压栈(入栈)
{
    StackNode1* temp;//进行压栈的数据节点
    temp=(StackNode1*)malloc(sizeof(StackNode1));
    temp->val=x;//填充数据域
    temp->next=istack->top;//连接栈顶的数据节点
    istack->top=temp;//充当栈顶
    istack->size++;//记录栈大小的变化
}
int express(int left,int right,char op)//op为运算符,返回运算结果
{
    switch (op)
    {
        case '+':
            return left+right;
        case '-':
            return left-right;
        case '*':
            return left*right;
        case '/':
            if(right==0)
            {
                return 999;
            }
            return left/right;
        default:
            break;
    }
    return -1;
}
int getsize(phead1* stack)
{
    return stack->size;
}
int calculate(char str[])//计算后缀表达式
{
    phead1* istack2=initstack1();//创建栈
    int i=0;
    while(str[i]!='\0')//遍历整个后缀表达式
    {
        char a[6]={0};
        int index=0;
        if(is_number(str[i])==1)
        {
            while(is_number(str[i])==1)
            {
                a[index]=str[i];
                index++;
                i++;
            }
            //成功读取数字
            seqstack_push1(istack2,atoi(a));//将该整数入栈
        }
        else if(is_operator(str[i])==1)
        {
            int right=seqstack_pop1(istack2);
            int left=seqstack_pop1(istack2);
            int ret=express(left,right,str[i]);
            if(ret==999)//除数为0了
            {
                printf("ILLEGAL");
                return 999;
            }
            seqstack_push1(istack2,ret);//运算结果入栈
        }
        else if(str[i]==' ')
        {

        }
        else
        {
            printf("error\n");
            break;
        }
        i++;
    }
    if(str[i]=='\0'&&getsize(istack2))
    {
        return seqstack_top1(istack2);
    }
    return 0;
}
int main() {
    while (1) {
        char str[1024] = {0};//将数组每个元素赋值为'\0'
        printf("请输入四则运算表达式:\n");
        scanf("%s", str);
        int number = transform(str);
        if (number == -1) {
            printf("你输入的表达式有错误");
        }
        //下方计算后缀表达式
        int num = calculate(buffer);
        if (num == 999) {
            return 0;
        }
        if(number !=-1){
        printf("%d\n", num);
        }
    }
}
 