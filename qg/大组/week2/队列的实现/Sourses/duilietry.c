#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LQueue.h"
void get_type();
void get_int(void **data);
void get_float(void **data);
void get_char(void **data);
/*
//��ʽ���нṹ
typedef struct node
{
    void *data;                   //������ָ��
    struct node *next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;                   //��ͷ
    Node *rear;                    //��β
    size_t length;            //���г���
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;

char type;

char datatype[30];

void InitLQueue(LQueue *Q){                 //��ʼ������
        Q->front = Q->rear = (Node*)malloc(sizeof(Node));
        if (Q->front == NULL){
            printf("�ڴ�ռ����ʧ��");
            exit(1);                //������Ϊ�쳣���µı���
        }
        Q->front->next = NULL;
        Q->length = 0;
}
void DestoryLQueue(LQueue *Q){          //��������
    if(Q->front!= NULL)
    {
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear; //�ͷ�һ���ڴ�Ҫ�����㣺1.�ͷ�ָ������ָ�롣2.����ָ��ָ���
    }
}
Status IsEmptyLQueue(const LQueue *Q) {       //����Ƿ�Ϊ��
    if(Q->front==Q->rear)
        return TRUE;
    else
        return FALSE;
}

void *GetHeadLQueue(LQueue *Q, void *e) {//�õ����е�ͷ��
        e= Q->front->next->data;
        return(e);
}

int LengthLQueue(LQueue *Q){                //���г���
    if (IsEmptyLQueue(Q) == TRUE) {
        printf("�ö����ǿյ�");
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
Status EnLQueue(LQueue *Q, void *idata){                 //��Ӳ���
    Node *p=(Node*)malloc(sizeof(Node));
    if(!p) {
        printf("�����ڴ�ʧ��");
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

Status DeLQueue(LQueue *Q){         //���Ӳ���
    /*if(Q->front==Q->rear){
        printf("����Ϊ�գ�û��Ԫ�ؿ���ɾ����");
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
    Q->front->next=NULL;//ֻ����ͷ���
    while(p)
    {
    q=p;
    p=p->next;
    free(q);
    }
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)) {       //��������
    if (IsEmptyLQueue(Q) == TRUE) {
        printf("�ö����ǿյ�");
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
   p=Q->front->next;                                   //pָ���һ��Ԫ��
   if (IsEmptyLQueue(Q) == TRUE) {
       printf("�ö����ǿյ�");
       return FALSE;
   }
   printf("��ǰ���й���%d��Ԫ��",Q->length);
   printf("------------------------------��ǰ����Ԫ��Ϊ��-------------------");
   while(p!=Q->rear)
   {
       printf("%d",*(int*)p->data);
       p=p->next;//������p++
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
    /* �˴�����������������Ǹ������ͼ��������Ǹ�д������̫���ˣ�����......���û���ʵ  */
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
            printf("1.�������Ƿ�Ϊ��;\n");
            printf("2.�鿴��ͷԪ��;\n");
            printf("3.��������ӵ�������;\n");
            printf("4.��һ�����ֳ���;\n");
            printf("5.��ȡ�����������е����нڵ�;\n");
            printf("6.��ȡ���еĳ���;\n");
            printf("7.ɾ�����в�ֹͣ����;\n");
            printf("������������ѡ�񣬲����һ������:\n");
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