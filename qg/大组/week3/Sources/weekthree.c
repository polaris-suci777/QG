#include "sort.h"

int main() {
    const int dataSize = 100;
    const int testCount = 100000;
    int n=0,key=1;
    int *arr = (int *)malloc(n * sizeof(int));
    struct node *datasourse=(struct node *)malloc(testCount * sizeof(struct node));
    while(1){
        int choose=0;
        system("color 3F");
        char filename[30]="data1.txt";
        displaymenu();
        printf("\n���������ѡ��");
        scanf("%d",&choose);
        switch (choose){
            case 1:
                if(key==1){
                    if(n==0){
                        printf("��δ��������\n");
                        system("pause");
                        break;
                    }
                    InsertSort(arr,n);
                }
                else if (key==2){
                    for(int i=0;i<testCount;i++){
                        InsertSort(datasourse[i].a,dataSize);
                    }
                }
                printf("���������");
                break;
            case 2:
                if(key==1){
                    if(n==0){
                        printf("��δ��������\n");
                        system("pause");
                        break;
                    }
                    MergeSort(arr,0,n-1);
                }
                else if(key==2){
                    for(int i=0;i<testCount;i++){
                        MergeSort(datasourse[i].a,0,dataSize-1);
                    }
                }
                printf("���������");
                break;
            case 3:
                if(key==1){
                    if(n==0){
                        printf("��δ��������\n");
                        system("pause");
                        break;
                    }
                    QuickSort(arr,0,n-1);
                }
                else if(key==2){
                    for(int i=0;i<testCount;i++){
                        QuickSort(datasourse[i].a,0,dataSize-1);
                    }
                }
                printf("���������");
                break;
            case 4:
                if(key==1){
                    if(n==0){
                        printf("��δ��������\n");
                        system("pause");
                        break;
                    }
                    CountSort(arr,n);
                }
                else if(key==2){
                    for(int i=0;i<testCount;i++){
                        CountSort(datasourse[i].a,dataSize);
                    }
                }
                printf("���������");
                break;
            case 5:
                if(key==1){
                    if(n==0){
                        printf("��δ��������\n");
                        system("pause");
                        break;
                    }
                    RadixCountSort(arr,n);
                }
                else if(key==2){
                    for(int i=0;i<testCount;i++){
                        RadixCountSort(datasourse[i].a,dataSize);
                    }
                }
                printf("���������");
                break;
            case 6:
                if(key==1){
                    if(n==0){
                        printf("��δ��������\n");
                        system("pause");
                        break;
                    }
                    savetofile(arr,filename,n);
                }
                else if(key==2){
                    for(int i=0;i<testCount;i++){
                        savetofile(datasourse[i].a,filename,dataSize);
                    }
                }
                break;
            case 7:
                clean(filename);
                break;
            case 8:
                printf("��ѡ����Ҫ���ɵ����ݷ�ʽ\n");
                printf("1.��ͬ�Ĵ�������\n");
                printf("2.����С��������(��100������*100k������)\n");
                scanf("%d",&key);
                if(key==1){
                    int data=0;
                    printf("��ѡ������������\n");
                    printf("1.10000������\n");
                    printf("2.50000������\n");
                    printf("3.200000������\n");
                    scanf("%d",&data);
                    if(data==1){
                        n=10000;
                    }
                    if(data==2){
                        n=50000;
                    }
                    if(data==3){
                        n=200000;
                    }
                    arr=testSortingPerformance(n);
                    printf("���ɳɹ�");
                }
                if(key==2){
                    for (int i = 0; i < testCount; i++) {
                        for (int j = 0; j < dataSize; j++) {
                            datasourse[i].a[j] = rand() % 1000; // �������ݷ�Χ��0��999֮��
                        }
                    }
                    printf("���ɳɹ�");}
                break;
            case 9:
                return (0);
            default:
                printf("����ȷ����ѡ��");
        }
    }
}
