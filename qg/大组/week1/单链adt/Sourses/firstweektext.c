#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "linkedlist.h"

Status InitList(LinkedList *L) {            //初始化链表
    LinkedList list;
    list = (LinkedList)malloc(sizeof(LNode));
    if(list == NULL)
    {
        printf("内存分配失败\n");
        return error;
    }
    list->next = NULL;
    *L = list;
    return success;
}

void DestroyList(LinkedList *L) {           //摧毁链表
    LinkedList temp;
    while(*L != NULL)               //判断是否是空链表，防止程序崩溃
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);         //释放内存
    }
}

Status InsertList(LNode *p, ElemType data) {            //插入链表
    LinkedList current = p;
    LinkedList newNode = (LinkedList)malloc(sizeof(LNode));

    if(newNode == NULL)             //判断是否是空链表，防止程序崩溃
    {
        printf("内存分配失败\n");
        return error;
    }
    newNode->data = data;
    newNode->next = NULL;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return success;
}

Status DeleteList(LNode *p, ElemType e) {       //删除链表
    LinkedList posNode = p->next;
    LinkedList posNodeFront = p;
    if(posNode == NULL)
    {
        printf("链表为空，无法删除\n");
    }
    else
    {
        while(posNode->data != e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if(posNode == NULL)
            {
                printf("没有该数据\n");
                return error;
            }
        }
        posNodeFront->next = posNode->next;
        free(posNode);
        return success;
    }
}

void TraverseList(LinkedList L) {           //遍历链表
    LinkedList temp;

    temp = L->next;
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Status SearchList(LinkedList L, ElemType e) {           //寻找数据
    while(L != NULL)
    {
        if(L->data == e)
        {
            return success;
        }
        L = L->next;
    }
    return error;
}
Status ReverseList(LinkedList *L) {             //反转链表
    LNode *newHead;		//储存每次反转后的第一个节点
    LNode *p1;			//每次都指向前一个节点
    LNode *p2;			// 储存未反转前的下一个节点
    p1=(*L)->next;
    p2=p1->next;
    p1->next=NULL;
    newHead=p1;
    while (p2!= NULL) {
        p1=p2;
        p2=p1->next;
        p1->next=newHead;
        newHead=p1;
    }
    (*L)->next=newHead;
}

LNode* FindMidNode(LinkedList L) {              //查找中间数据
    LinkedList slow = L, fast = L;
    while(fast != NULL && slow != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Status IsLoopList(LinkedList L) {           //是否成环
    LinkedList fast = L, slow = L;
    while(fast->next != NULL && slow->next != NULL)
    {
        slow = slow->next;
        if((fast = fast->next->next) == NULL)
            return error;
        if(fast == slow)
            return success;
    }
    return error;
}

char MenuText[12][50]={             //菜单
        "单链表ADT",
        "menu1.创建空链表",
        "menu2.销毁链表",
        "menu3.插入结点",
        "menu4.删除结点",
        "menu5.遍历链表",
        "menu6.查找数据",
        "menu7.反转链表",
        "menu8.判断链表是否成环",
        "menu9.查找中间结点",
        "menu10.退出",
        "请输入对应的数字(1-10)"
};
void show(void)     //菜单演示
{
    int i;
    printf("\n=================================================================\n");
    for (i=0;i<12;i++){
            printf("<<%s>>\n",MenuText[i]);
    }
    printf("\n=================================================================\n");
}
int main(void)
{
    int choice, num = 0;
    LinkedList head = NULL;
    do
    {
        show();
        scanf("%d",&choice);
        system("cls");
        switch(choice)
        {
            case 1://创建空链表
            {
                if(InitList(&head))
                {
                    printf("空链表创建成功\n");
                }
                else
                {
                    printf("空链表创建失败\n");
                }
                break;
            }
            case 2://销毁链表
            {
                DestroyList(&head);
                printf("链表销毁完成\n");
                break;
            }
            case 3://插入数据
            {
                if(head == NULL)
                {
                    printf("链表为空， 请先创建链表\n");
                }
                else
                {
                    printf("请输入数据：");
                    scanf("%d", &num);
                    if(InsertList(head, num))
                    {
                        printf("数据插入成功\n");
                    }
                    else
                    {
                        printf("数据插入失败\n");
                    }
                }
                break;
            }
            case 4://删除数据
            {
                printf("你想删除哪个数据：");
                scanf("%d", &num);
                if(DeleteList(head, num))
                {
                    printf("数据删除成功\n");
                }
                else
                {
                    printf("数据删除失败\n");
                }
                break;
            }
            case 5://遍历链表
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("链表不存在或者只存在一个空的头结点\n");
                }
                else
                {
                    TraverseList(head);
                }
                break;
            }
            case 6://查找数据
            {
                printf("请输入你要查找的数据：");
                scanf("%d", &num);
                if(SearchList(head, num))
                {
                    printf("该数存在\n");
                }
                else
                {
                    printf("该数不存在\n");
                }
                break;
            }
            case 7://反转链表
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("链表为空或者链表只含有两个结点\n");
                    printf("链表反转失败\n");
                }
                else
                {
                    if(ReverseList(&head))
                    {
                        printf("链表反转成功\n");
                    }
                    else
                    {
                        printf("链表反转失败\n");
                    }

                }
                break;
            }
            case 8://判断链表是否成环
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("链表为空\n");
                }
                else
                {
                    if(IsLoopList(head))
                    {
                        printf("链表成环\n");
                    }
                    else
                    {
                        printf("链表没有成环\n");
                    }
                }
                break;
            }
            case 9://查找中间结点
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("这是空链表\n");
                }
                else
                {
                    printf("链表中间储存的值为%d\n", (FindMidNode(head))->data);
                }
                break;
            }
            case 10://销毁链表
            {
                DestroyList(&head);
                break;
            }
            default:
            {
                printf("请重新输入数字！(1-11)\n");
                break;
            }
        }
    } while (choice != 10);

    return 0;
}
