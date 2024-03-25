/***************************************************************************************
 *    File Name                :    LQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                    :   Mac OS
 *    Create Data                :    2020.4.2
 *    Author/Corportation        :   Chuan Shi
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

/**************************************************************
 *    Struct Define Section
 **************************************************************/
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

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
//void InitLQueue(LQueue *Q);
void InitLQueue(LQueue *Q){                 //��ʼ������
    Q->front = Q->rear = (Node*)malloc(sizeof(Node));
    if (Q->front == NULL){
        printf("�ڴ�ռ����ʧ��");
        exit(1);                //������Ϊ�쳣���µı���
    }
    Q->front->next = NULL;
    Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
//void DestoryLQueue(LQueue *Q);
void DestoryLQueue(LQueue *Q){          //��������
    if(Q->front!= NULL)
    {
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear; //�ͷ�һ���ڴ�Ҫ�����㣺1.�ͷ�ָ������ָ�롣2.����ָ��ָ���
    }
}
/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
//Status IsEmptyLQueue(const LQueue *Q);
Status IsEmptyLQueue(const LQueue *Q) {       //����Ƿ�Ϊ��
    if(Q->front==Q->rear)
        return TRUE;
    else
        return FALSE;
}
/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param          e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
//Status GetHeadLQueue(LQueue *Q, void *e);
void *GetHeadLQueue(LQueue *Q, void *e) {//�õ����е�ͷ��
    e= Q->front->next->data;
    return(e);
}
/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
//int LengthLQueue(LQueue *Q);
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
/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
//Status EnLQueue(LQueue *Q, void *data);
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
    return TRUE;}
/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
//Status DeLQueue(LQueue *Q);
    Status DeLQueue(LQueue *Q){
        if(Q->front==Q->rear)
        return FALSE;
    Node *p=Q->front->next;

    Q->front->next=p->next;
    if(Q->rear==p)
        Q->rear=Q->front;
    free(p);
    return TRUE;
}
/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
//void ClearLQueue(LQueue *Q);            //�������
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
/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
//Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q));       //��������
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
/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
//void LPrint(void *q);
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
/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED


