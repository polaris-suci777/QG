#include "binary_sort_tree.h"
char MenuText[13][50]={             //菜单
        "二叉树排序ADT",
        "menu1.查找数据",
        "menu2.插入数据",
        "menu3.删除数据",
        "menu4.先序遍历(递归调用)",
        "menu5.先序遍历(非递归调用)",
        "menu6.中序遍历(递归调用)",
        "menu7.中序遍历(非递归调用)",
        "menu8.后序遍历(递归调用)",
        "menu9.后序遍历(非递归调用)",
        "menu10.层序遍历",
        "menu11.释放内存",
        "menu12.quit",
};
void show(void)     //菜单演示
{
    int i;
    printf("\n=================================================================\n");
    for (i=0;i<13;i++){
        printf("<<%s>>\n",MenuText[i]);
    }
    printf("\n=================================================================\n");
}
int main(){
    BinarySortTree BST;
    BST_init(&BST);
    ElemType data;
    while(1){
        int choose=0;
        system("color 3F");
        show();
        printf("\n请输入你的选择");
        scanf("%d",&choose);
        switch (choose) {
            case 1:
                printf("请输入你要查找的数据");
                scanf("%d",&data);
                // 查找节点
                if (BST_search(&BST, data) == true) {
                    printf("Node found!\n");
                } else {
                    printf("Node not found!\n");
                }
                break;
            case 2:
                printf("请输入你要插入的数据");
                scanf("%d",&data);
                BST_insert(&BST, data);
                printf("插入成功");
                break;
            case 3:
                printf("请输入你要删除的数据");
                scanf("%d",&data);
                if(BST_delete(&BST, data)==true){
                    printf("删除成功");
                }
                else {
                    printf("删除失败");
                }
                break;
            case 4:
                // 前序遍历（递归）
                if(BST.root==NULL){
                    printf("二叉树为空，请输入数据");
                }
                else {
                    printf("Preorder traversal (recursive): ");
                    BST_preorderR(BST.root, visitNode);
                    printf("\n");
                }
                break;
            case 5:
                // 前序遍历（非递归）
                if(BST.root==NULL){
                    printf("二叉树为空，请输入数据");
                }
                else {
                printf("Preorder traversal (iterative): ");
                BST_preorderI(BST.root, visitNode);
                printf("\n");
                }
                break;
            case 6:
                // 中序遍历（递归）
                if(BST.root==NULL){
                    printf("二叉树为空，请输入数据");
                }
                else {
                printf("Inorder traversal (recursive): ");
                BST_inorderR(BST.root, visitNode);
                printf("\n");}
                break;
            case 7:
                // 中序遍历（非递归）
                if(BST.root==NULL){
                    printf("二叉树为空，请输入数据");
                }
                else {
                printf("Inorder traversal (iterative): ");
                BST_inorderI(BST.root, visitNode);
                printf("\n");}
                break;
            case 8:
                // 后序遍历（递归）
                if(BST.root==NULL){
                    printf("二叉树为空，请输入数据");
                }
                else {
                printf("postorder traversal (recursive): ");
                BST_postorderR(BST.root, visitNode);
                printf("\n");}
                break;
            case 9:
                // 后序遍历（非递归）
                if(BST.root==NULL){
                    printf("二叉树为空，请输入数据");
                }
                else {
                printf("postorder traversal (recursive): ");
                BST_postorderI(BST.root, visitNode);
                printf("\n");}
                break;
            case 10:
                // 层序遍历
                if(BST.root==NULL){
                    printf("二叉树为空，请输入数据");
                }
                else {
                printf("Level order traversal: ");
                BST_levelOrder(BST.root, visitNode);
                printf("\n");}
                break;
            case 11:
                freeTree(BST.root);
                break;
            case 12:
                return 0;
            default:
                printf("请正确输入选项");
        }
    }

}
