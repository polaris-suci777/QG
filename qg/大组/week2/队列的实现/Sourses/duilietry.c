#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LQueue.h"
void get_type();
void get_int(void **data);
void get_float(void **data);
void get_char(void **data);
/*
//链式队列结构
typedef struct node
{
    void *data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    size_t length;            //队列长度
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;

char type;

char datatype[30];

void InitLQueue(LQueue *Q){                 //初始化队列
        Q->front = Q->rear = (Node*)malloc(sizeof(Node));
        if (Q->front == NULL){
            printf("内存空间分配失败");
            exit(1);                //程序因为异常导致的崩溃
        }
        Q->front->next = NULL;
        Q->length = 0;
}
void DestoryLQueue(LQueue *Q){          //队列销毁
    if(Q->front!= NULL)
    {
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear; //释放一块内存要做两点：1.释放指向它的指针。2.将该指针指向空
    }
}
Status IsEmptyLQueue(const LQueue *Q) {       //检查是否为空
    if(Q->front==Q->rear)
        return TRUE;
    else
        return FALSE;
}

void *GetHeadLQueue(LQueue *Q, void *e) {//得到队列的头部
        e= Q->front->next->data;
        return(e);
}

int LengthLQueue(LQueue *Q){                //队列长度
    if (IsEmptyLQueue(Q) == TRUE) {
        printf("该队列是空的");
        return FALSE;
    }
    else{
        Node *p=Q->front;
        while(p->next!=Q->rear){
            Q->length++;
            p=p->next;
        }
        return TRUE;
    }
}
Status EnLQueue(LQueue *Q, void *idata){                 //入队操作
    Node *p=(Node*)malloc(sizeof(Node));
    if(!p) {
        printf("分配内存失败");
        return FALSE;
    }
    p->data=idata;
    p->next=NULL;
    Q->rear->next=p;
    Q->rear=p;
    if(Q->front->next==NULL)
        Q->front->next=p;
    Q->length++;
    return TRUE;
    /*if (Q->rear == NULL) {
        Q->front = Q->rear = p;
    } else {
        Q->rear->next = p;
        Q->rear = p;
    }
    Q->length++;
    return TRUE;
}

Status DeLQueue(LQueue *Q){         //出队操作
    /*if(Q->front==Q->rear){
        printf("队列为空，没有元素可以删除！");
        return  FALSE;}
    else
    {
        Q->front->next=Q->front->next->next;
    }
    return TRUE;*/
    /*if(Q->front==Q->rear)
        return FALSE;
    Node *p=Q->front->next;

    Q->front->next=p->next;
    if(Q->rear==p)
        Q->rear=Q->front;
    free(p);
    return TRUE;
}

void ClearLQueue(LQueue *Q){
    Node *p,*q;
    Q->rear=Q->front;
    p=Q->front->next;
    Q->front->next=NULL;//只留下头结点
    while(p)
    {
    q=p;
    p=p->next;
    free(q);
    }
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)) {       //遍历队列
    if (IsEmptyLQueue(Q) == TRUE) {
        printf("该队列是空的");
        return FALSE;
    }
    else {
        Node *current = Q->rear;
        while (current != NULL) {
            foo(current->data);
            current = current->next;
        }
        return TRUE;
    }
}

/*Node *p;
   p=Q->front->next;                                   //p指向第一个元素
   if (IsEmptyLQueue(Q) == TRUE) {
       printf("该队列是空的");
       return FALSE;
   }
   printf("当前队列共计%d个元素",Q->length);
   printf("------------------------------当前队列元素为：-------------------");
   while(p!=Q->rear)
   {
       printf("%d",*(int*)p->data);
       p=p->next;//不能用p++
   }
   printf("%d",*(int*)p->data);
   return TRUE;

void LPrint(void *data){
    if(type=='i' ){
        int* intData = (int*)data;
        printf("%d ", *intData);
    }
        //printf("%d ",*(int *)data); }
    else if(type=='f'){
             printf("%f ",*(float *)data);
         }
    else if(type=='c'){
             printf("%c ",*(char *)data);
         }
}
*/

void get_type()
{
    while(1)
    {
        type = '\0';
        printf("Please give me what kind of the data you want to keep:\n");
        printf("'i' means int, 'f' means float while 'c' means char!\n");
        scanf("%c", &type);
        while(getchar() != '\n');
        if(type=='i' || type=='f' || type=='c')
            break;
        else
        {
            system("cls");
            printf("Please don't give me others!\n");
        }
    }
}
void get_data(void **data)
{
    if(type == 'i')
        get_int(data);
    else if(type == 'f')
        get_float(data);
    else if(type == 'c')
        get_char(data);
}

void get_int(void **data)
{
    printf("Please give me a int number:\n");
    int *p = (int*)malloc(sizeof(int));
    char s[50];
    int flag=1;
    while(1)
    {
        gets(s);
        if(*s == '-')
        {
            if(strlen(s) < 6)
            {
                int i;
                for(i=1; i<6 && s[i]!='\0'; i++)
                    if(s[i]<'0' || s[i]>'9');
                {
                    flag = 0;
                    break;
                }
                if(flag == 1)
                {
                    *p = 0;
                    for(i=1; i<6 && s[i]!='\0'; i++)
                        *p = (*p)*10 + s[i] - '0';
                    (*p) *= -1;
                    *data = (void*)p;
                    return;
                }
            }
        }
        else if(strlen(s) < 5)
        {
            int i;
            for(i=0; i<5 && s[i]!='\0'; i++)
                if(s[i]<'0' || s[i]>'9')
                {
                    flag = 0;
                    break;
                }
            if(flag == 1)
            {
                *p = 0;
                for(i=0; i<5 && s[i]!='\0'; i++)
                    *p = (*p)*10 + s[i] - '0';
                *data = (void*)p;
                return;
            }
        }
        printf("Please give me a right int number which is bigger than -10000 and smaller than 10000;\n");
    }
}

void get_float(void **data)
{
    printf("Please give me a float number:\n");
    float *p = (float*)malloc(sizeof(float));
    *p = (float)0.0;
    /* 此处可以用类比于上面那个函数和计算器中那个写，但是太长了，所以......靠用户诚实  */
    scanf("%f", p);
    *data = (void*)p;
    while(getchar() != '\n');
}

void get_char(void **data)
{
    printf("Please give me a char:\n");
    char *p = (char*)malloc(sizeof(char));
    *p = '0';
    scanf("%c", p);
    while(getchar() != '\n');
    *data = (void*)(p);
}
void show()
{
    LQueue* Q=(LQueue*)malloc(sizeof(LQueue));
    void *data;
    if(type == 'i')
        data = (void*)malloc(sizeof(int));
    else if(type == 'f')
        data = (void*)malloc(sizeof(float));
    else if(type == 'c')
        data = (void*)malloc(sizeof(char));
    //void *addData;
    int flag;
    InitLQueue(Q);
    while(1)
    {
        while(1)
        {
            flag = 0;
            printf("You can do these function:\n");
            printf("1.检查队列是否为空;\n");
            printf("2.查看列头元素;\n");
            printf("3.将数字添加到队列中;\n");
            printf("4.将一个数字出队;\n");
            printf("5.读取（遍历）队列的所有节点;\n");
            printf("6.获取队列的长度;\n");
            printf("7.删除队列并停止运行;\n");
            printf("现在请给我你的选择，并完成一个功能:\n");
            scanf("%d", &flag);
            while(getchar() != '\n');
            if(flag<1 || flag>7)
            {
                system("cls");
                printf("Please give me the right number!");
            }
            else
                break;
        }
        switch(flag)
        {
            case(1):
                if(IsEmptyLQueue(Q) == TRUE){
                    printf("The queue is empty now!You should add something!\n");
                    break;}
                else
                    printf("The queue is not empty now.\n");
                break;
            case(2):
                if(IsEmptyLQueue(Q) != TRUE){
                    //data=GetHeadLQueue(Q,data);
                    //LPrint(data);
                    if(type=='i' ){
                        printf("%d ",*(int *)GetHeadLQueue(Q,data)); }
                    else if(type=='f'){
                        printf("%f ",*(float *)GetHeadLQueue(Q,data));
                    }
                    else if(type=='c'){
                        printf("%c ",*(char *)GetHeadLQueue(Q,data));
                    }
                    break;
                }
                else
                    printf("The queue is empty now!You should add something!\n");
                break;
            case(3):
                if(type == 'i')
                    get_int(&data);    //adddata
                else if(type == 'f')
                    get_float(&data);
                else
                    get_char(&data);
                if(EnLQueue(Q, data) == TRUE)       //
                    printf("we have add it into the queue!\n");
                else
                {
                    printf("The room is full!!!\n");
                    exit(-1);
                }
                break;
            case(4):
                if(DeLQueue(Q) == TRUE)
                    printf("We have get the node out of the queue.\n");
                else
                    printf("The queue is empty now!\n");
            case(5):
                TraverseLQueue(Q,LPrint);
                break;
            case(6):
                if(LengthLQueue(Q) == TRUE)
                    printf("The length of the queue is %d.\n", Q->length);
                else
                {
                    printf("There is some wrong in the queue!!!\n");
                    exit(-1);
                }
                break;
            case(7):
                DestoryLQueue(Q);
                free(Q);
                return;
        }
    }

}
int main()
{
    get_type();
    show();
    return 0;
}