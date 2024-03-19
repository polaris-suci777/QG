#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "dulinkedlist.h"
Status InitList_DuL(DuLinkedList *L) {          //初始化链表
    DuLinkedList List;
    List = (DuLinkedList)malloc(sizeof(DuLNode));
    if(List == NULL)
    {
        printf("内存分配失败\n");
        return error;
    }
    List->next = NULL;
    List->prior = NULL;
    *L = List;
    return success;
}

void DestroyList_DuL(DuLinkedList *L) {          //摧毁链表
    DuLinkedList temp;
    while(*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);             //释放内存
    }
}

Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {               //头插法插入数据
    if(p->next == NULL)//当链表为空时，直接连接p、q
    {
        p->next = q;
        q->prior = p;
    }
    else
    {
        DuLinkedList temp;
        temp = p->next;
        p->next = q;
        q->next = temp;
        temp->prior = q;
        q->prior = p;
        return success;
    }
}

Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {            //尾插法插入数据
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    q->prior = p;
}

Status DeleteList_DuL(DuLNode *p, ElemType *e) {            //删除数据
    if(p->next == NULL)
    {
        printf("链表为空，无法删除\n");
        return error;
    }
    else
    {
        DuLinkedList posNode = p->next, posNodeFront = p;
        //找到删除结点的位置
        while(posNode->data != *e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if(posNode == NULL)
            {
                printf("找不到该数据\n");
                return error;
            }
        }
        if(posNode->next != NULL)
        {
            posNodeFront->next = posNode->next;
            posNode->next->prior = posNodeFront;
        }
        else
        {
            posNodeFront->next = NULL;
        }
        free(posNode);
        return success;
    }
}

void TraverseList_DuL(DuLinkedList L) {             //遍历链表
    if(L == NULL)
    {
        printf("链表未创建，请先创建链表\n");
    }
    else if(L->next == NULL)
    {
        printf("当前链表为空\n");
    }
    else
    {
        DuLinkedList temp = L->next;
        while(temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

char MenuText[9][50]={             //菜单
        "双链表ADT",
        "menu1.创建空链表",
        "menu2.销毁链表",
        "menu3.头插法插入数据",
        "menu4.尾插法插入数据",
        "menu5.删除数据",
        "menu6.遍历链表",
        "menu7.退出",
        "请输入对应的数字(1-7)"
};

void show(void)     //菜单演示
{
    int i;
    printf("\n=================================================================\n");
    for (i=0;i<9;i++){
        printf("<<%s>>\n",MenuText[i]);
    }
    printf("\n=================================================================\n");
}
int main(void)
{
    int choice, num = 0;
    DuLinkedList head;
    head = NULL;
    do
    {
        show();
        scanf("%d",&choice);
        system("cls");
        switch(choice)
        {
            case 1://创建空链表
            {
                if(InitList_DuL(&head))
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
                DestroyList_DuL(&head);
                printf("链表销毁成功\n");
                break;
            }
            case 3://头插法插入数据
            {
                if(head == NULL)
                {
                    printf("链表未创建，请先创建链表\n");
                }
                else
                {
                    DuLinkedList newNode;
                    if(InitList_DuL(&newNode))
                    {
                        printf("请输入数据：");
                        scanf("%d", &newNode->data);
                        if(InsertBeforeList_DuL(head, newNode))
                        {
                            printf("数据插入成功\n");
                        }
                        else
                        {
                            printf("数据插入失败\n");
                        }
                    }
                    else
                    {
                        printf("数据插入失败\n");
                    }
                }
                break;
            }
            case 4://尾插法插入数据
            {
                if(head == NULL)
                {
                    printf("链表未创建，请先创建链表\n");
                }
                else
                {
                    DuLinkedList newNode;
                    if(InitList_DuL(&newNode))
                    {
                        printf("请输入数据：");
                        scanf("%d", &newNode->data);
                        if(InsertAfterList_DuL(head, newNode))
                        {
                            printf("数据插入成功\n");
                        }
                        else
                        {
                            printf("数据插入失败\n");
                        }
                    }
                    else
                    {
                        printf("数据插入失败\n");
                    }
                }
                break;
            }
            case 5://删除数据
            {
                if(head == NULL)
                {
                    printf("链表未创建，请先创建链表\n");
                }
                else
                {
                    printf("你想删除哪个数据：");
                    scanf("%d", &num);
                    if(DeleteList_DuL(head, &num))
                    {
                        printf("数据删除成功\n");
                    }
                    else
                    {
                        printf("数据删除失败\n");
                    }
                }
                break;
            }
            case 6://遍历链表
            {
                TraverseList_DuL(head);
                break;
            }
            case 7://退出程序
            {
                DestroyList_DuL(&head);
                break;
            }
            default:
            {
                printf("请重新输入数字!(1-7)\n");
                break;
            }
        }
    } while (choice != 7);
    return 0;
}
