#include "binary_sort_tree.h"
char MenuText[13][50]={             //�˵�
        "����������ADT",
        "menu1.��������",
        "menu2.��������",
        "menu3.ɾ������",
        "menu4.�������(�ݹ����)",
        "menu5.�������(�ǵݹ����)",
        "menu6.�������(�ݹ����)",
        "menu7.�������(�ǵݹ����)",
        "menu8.�������(�ݹ����)",
        "menu9.�������(�ǵݹ����)",
        "menu10.�������",
        "menu11.�ͷ��ڴ�",
        "menu12.quit",
};
void show(void)     //�˵���ʾ
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
        printf("\n���������ѡ��");
        scanf("%d",&choose);
        switch (choose) {
            case 1:
                printf("��������Ҫ���ҵ�����");
                scanf("%d",&data);
                // ���ҽڵ�
                if (BST_search(&BST, data) == true) {
                    printf("Node found!\n");
                } else {
                    printf("Node not found!\n");
                }
                break;
            case 2:
                printf("��������Ҫ���������");
                scanf("%d",&data);
                BST_insert(&BST, data);
                printf("����ɹ�");
                break;
            case 3:
                printf("��������Ҫɾ��������");
                scanf("%d",&data);
                if(BST_delete(&BST, data)==true){
                    printf("ɾ���ɹ�");
                }
                else {
                    printf("ɾ��ʧ��");
                }
                break;
            case 4:
                // ǰ��������ݹ飩
                if(BST.root==NULL){
                    printf("������Ϊ�գ�����������");
                }
                else {
                    printf("Preorder traversal (recursive): ");
                    BST_preorderR(BST.root, visitNode);
                    printf("\n");
                }
                break;
            case 5:
                // ǰ��������ǵݹ飩
                if(BST.root==NULL){
                    printf("������Ϊ�գ�����������");
                }
                else {
                printf("Preorder traversal (iterative): ");
                BST_preorderI(BST.root, visitNode);
                printf("\n");
                }
                break;
            case 6:
                // ����������ݹ飩
                if(BST.root==NULL){
                    printf("������Ϊ�գ�����������");
                }
                else {
                printf("Inorder traversal (recursive): ");
                BST_inorderR(BST.root, visitNode);
                printf("\n");}
                break;
            case 7:
                // ����������ǵݹ飩
                if(BST.root==NULL){
                    printf("������Ϊ�գ�����������");
                }
                else {
                printf("Inorder traversal (iterative): ");
                BST_inorderI(BST.root, visitNode);
                printf("\n");}
                break;
            case 8:
                // ����������ݹ飩
                if(BST.root==NULL){
                    printf("������Ϊ�գ�����������");
                }
                else {
                printf("postorder traversal (recursive): ");
                BST_postorderR(BST.root, visitNode);
                printf("\n");}
                break;
            case 9:
                // ����������ǵݹ飩
                if(BST.root==NULL){
                    printf("������Ϊ�գ�����������");
                }
                else {
                printf("postorder traversal (recursive): ");
                BST_postorderI(BST.root, visitNode);
                printf("\n");}
                break;
            case 10:
                // �������
                if(BST.root==NULL){
                    printf("������Ϊ�գ�����������");
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
                printf("����ȷ����ѡ��");
        }
    }

}
