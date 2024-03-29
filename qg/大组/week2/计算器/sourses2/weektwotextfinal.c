#include <stdio.h>
#include "stdlib.h"
#include <conio.h>
//#include "LinkStack.h"
typedef char ElemType;
typedef struct StackNode        //ѹջ�ͳ�ջ����ջ������(�����ջ��ָǰһ��)
{
    ElemType data;;//����
    struct node* next;//ָ��
}StackNode,*LinkStackPtr;
typedef struct seqstack
{
    int count;              //��¼ջ�Ĵ�С
    StackNode* top;         //ָ��ջ��Ԫ��
}phead;
phead*  initstack()//����ջ
{
    phead* istack=(phead*)malloc(sizeof(phead));//Ϊͷ�ڵ����ռ�
    if(istack!=NULL)//��׳���ж�
    {
        istack->top=NULL;
        istack->count=0;
    }
    return istack;
}
int isempty(phead* istack)//�ж�ջΪ��
{
    if(istack->top==NULL)
    {
        return 1;//ջΪ��
    }
    return 0;//ջ��Ϊ��
}
StackNode* getTopLStack(phead* istack)//��ȡջ��Ԫ�ص����ݽڵ�
{
    if(istack->count!=0)//ջ��Ϊ��
    {
        return istack->top;//���ص���ջ�������ݽڵ������ջ����Ԫ��
    }
    return NULL;
}
StackNode* seqstack_pop(phead* istack)//����ջ��Ԫ��
{
    if(isempty(istack)==0)//ջ��Ϊ��
    {
        StackNode* account=istack->top;//��¼ջ�������ݽڵ�
        istack->top=istack->top->next;//ָ��ջ����һ��Ԫ��
        istack->count--;//��¼ջ�Ĵ�С
        return account;//���ص��������ݽڵ�
    }
    return NULL;
}
void seqstack_push(phead* istack,char x)//ѹջ(��ջ)
{
    StackNode* temp;//����ѹջ�����ݽڵ�
    temp=(StackNode*)malloc(sizeof(StackNode));
    temp->data=x;//���������
    temp->next=istack->top;//����ջ�������ݽڵ�
    istack->top=temp;//�䵱ջ��
    istack->count++;//��¼ջ��С�ı仯
    return;
}
//��������׺���ʽת��׺���ʽ�ĺ���
char buffer[256]={0};//����������ÿ�����ݶ���ʼ��Ϊ'\0'(\0��ascill����0)
//bufferΪ�����
void char_put(char ch)//�������ַ������������
{
    static int index=0;//static���徲̬����,�ź����б�ʾindexֻ��ʼ��һ��,ֻ����index�ĸı�
    buffer[index++]=ch;
}
int priority(char ch)//�����Ƚ����ȼ�
{
    int ret=0;
    switch(ch)
    {
        case '+'://case��͸,����һ��caseû��break���ʱ���������ִ��
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
int is_number(char ch)//�ǲ�������
{
    return(ch>='0'&&ch<='9');//���ַ���1�����򷵻�0
}
int is_operator(char ch)//�ǲ��������
{
    return(ch=='+'||ch=='-'||ch=='*'||ch=='/');
}
int is_left(char ch)//�ǲ���������
{
    return(ch=='(');
}
int is_right(char ch)//�ǲ���������
{
    return(ch==')');
}
int is_letter(char ch){
    return(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z');
}
int transform(char str[])//ʹ��const��������,������������׺ת���ɺ�׺
{
    phead* istack=initstack();//����һ��ջ
    int i=0;
    while(str[i]!='\0')//���������ַ���
    {
        //�ж��ǲ�����ĸ
        if(is_letter(str[i])==1) {
        return -1;
        }
        //�ж��ǲ�������
        else if(is_number(str[i])==1)
        {
            if(is_number(str[i+1])==1)//����1Ҳ������,��ֱ�ӷ�
            {
                char_put(str[i]);//����ֱ�ӷ�������(�����)
            }
            else//���治������,���һ���ո���Ϊ�ָ���
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
            if(isempty(istack)==0)//ջ��Ϊ��
            {
                while((isempty(istack)==0)&&(priority(str[i])<=(priority(getTopLStack(istack)->data))))//ջ��Ϊ�ղ�������������ȼ�������ջ��
                {
                    char_put(seqstack_pop(istack)->data);//����������ջ���͵���ֱ������������
                    char_put(' ');
                }
            }
            seqstack_push(istack,str[i]);//�ٽ����������ջ
        }
        else if(is_left(str[i]))//������ֱ����ջ
        {
            seqstack_push(istack,str[i]);
        }
        else if(is_right(str[i]))//�ж��ǲ���������
        {
            while(is_left(getTopLStack(istack)->data)!=1)//ջ�����������ŵ����
            {
                char_put(seqstack_pop(istack)->data);//�������洢�������
                if(isempty(istack)==1)//ջΪ����δ�ҵ�������
                {
                    printf("û��ƥ�䵽������\n");
                    return -1;
                }
            }
            //��ʱƥ�䵽��������
            seqstack_pop(istack);
            //����������,���ﲢ���ñ���,���������������
        }
        else
        {
            printf("�в���ʶ����ַ�\n");
            return -1;
        }
        i++;
    }
    //���������Ѿ�
    if(str[i]=='\0')//�ɹ��������ַ���ĩβ
    {
        while(isempty(istack)==0)//����ȫ��ջ��Ԫ��
        {
            if(getTopLStack(istack)->data=='(')//ջ��Ԫ��Ϊ������
            {
                printf("��û��ƥ�䵽��'(',ȱ��')'\n");
                return -1;
            }
            char_put(seqstack_pop(istack)->data);//��ջ��Ԫ�ط������մ�
        }
    }
    /*else
    {
        printf("����û����ɣ�\n");
    }*/
    return 1;
}

//�·�Ϊ�����׺���ʽ��Ҫ�ĺ���
typedef struct node1//�����ջ������ջ
{
    int val;//����
    struct node1* next;//ָ��
}StackNode1;
typedef struct seqstack1
{
    int size;//��¼ջ�Ĵ�С
    StackNode1* top;//ָ��ջ��Ԫ��
}phead1;
phead1*  initstack1()//����ջ
{
    phead1* istack=(phead1*)malloc(sizeof(phead1));//Ϊͷ�ڵ����ռ�
    if(istack!=NULL)//��׳���ж�
    {
        istack->top=NULL;
        istack->size=0;
    }
    return istack;
}
int isempty1(phead1* istack)//�ж�ջΪ��
{
    if(istack->top==NULL)
    {
        return 1;//ջΪ��
    }
    return 0;//ջ��Ϊ��
}
int seqstack_top1(phead1* istack)//��ȡջ��Ԫ��
{
    if(istack->size!=0)//ջ��Ϊ��
    {
        return istack->top->val;//���ص���ջ��������
    }
    return 99999;
}
int seqstack_pop1(phead1* istack)//����ջ��Ԫ��
{
    if(isempty1(istack)==0)//ջ��Ϊ��
    {
        int account=istack->top->val;//��¼ջ�������ݽڵ�
        istack->top=istack->top->next;//ָ��ջ����һ��Ԫ��
        istack->size--;//��¼ջ�Ĵ�С
        return account;//���ص��������ݽڵ�
    }
    return 99999;
}
void seqstack_push1(phead1* istack,int x)//ѹջ(��ջ)
{
    StackNode1* temp;//����ѹջ�����ݽڵ�
    temp=(StackNode1*)malloc(sizeof(StackNode1));
    temp->val=x;//���������
    temp->next=istack->top;//����ջ�������ݽڵ�
    istack->top=temp;//�䵱ջ��
    istack->size++;//��¼ջ��С�ı仯
}
int express(int left,int right,char op)//opΪ�����,����������
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
int calculate(char str[])//�����׺���ʽ
{
    phead1* istack2=initstack1();//����ջ
    int i=0;
    while(str[i]!='\0')//����������׺���ʽ
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
            //�ɹ���ȡ����
            seqstack_push1(istack2,atoi(a));//����������ջ
        }
        else if(is_operator(str[i])==1)
        {
            int right=seqstack_pop1(istack2);
            int left=seqstack_pop1(istack2);
            int ret=express(left,right,str[i]);
            if(ret==999)//����Ϊ0��
            {
                printf("ILLEGAL");
                return 999;
            }
            seqstack_push1(istack2,ret);//��������ջ
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
        char str[1024] = {0};//������ÿ��Ԫ�ظ�ֵΪ'\0'
        printf("����������������ʽ:\n");
        scanf("%s", str);
        int number = transform(str);
        if (number == -1) {
            printf("������ı��ʽ�д���");
        }
        //�·������׺���ʽ
        int num = calculate(buffer);
        if (num == 999) {
            return 0;
        }
        if(number !=-1){
        printf("%d\n", num);
        }
    }
}
 