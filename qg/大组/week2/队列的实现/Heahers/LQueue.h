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

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
//void InitLQueue(LQueue *Q);
void InitLQueue(LQueue *Q){                 //初始化队列
    Q->front = Q->rear = (Node*)malloc(sizeof(Node));
    if (Q->front == NULL){
        printf("内存空间分配失败");
        exit(1);                //程序因为异常导致的崩溃
    }
    Q->front->next = NULL;
    Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
//void DestoryLQueue(LQueue *Q);
void DestoryLQueue(LQueue *Q){          //队列销毁
    if(Q->front!= NULL)
    {
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear; //释放一块内存要做两点：1.释放指向它的指针。2.将该指针指向空
    }
}
/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
//Status IsEmptyLQueue(const LQueue *Q);
Status IsEmptyLQueue(const LQueue *Q) {       //检查是否为空
    if(Q->front==Q->rear)
        return TRUE;
    else
        return FALSE;
}
/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param          e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
//Status GetHeadLQueue(LQueue *Q, void *e);
void *GetHeadLQueue(LQueue *Q, void *e) {//得到队列的头部
    e= Q->front->next->data;
    return(e);
}
/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
//int LengthLQueue(LQueue *Q);
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
/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
//Status EnLQueue(LQueue *Q, void *data);
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
    return TRUE;}
/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
//void ClearLQueue(LQueue *Q);            //清除队列
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
/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
//Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q));       //遍历队列
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
/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
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


