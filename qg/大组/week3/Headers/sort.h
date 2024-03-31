#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
int Partition(int arr[], int low, int high);
struct node{
    int a[100];
}addnode;

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void InsertSort(int arr[], int n) {         //��������
    for (int i = 1; i < n; i++) {  
        int key = arr[i];  
        int j = i - 1;  
        while (j >= 0 && arr[j] > key) {  
            arr[j + 1] = arr[j];  
            j--;  
        }  
        arr[j + 1] = key;  
    }  
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void Merge(int arr[], int begin, int mid, int end) {  //�ȶ���
    int i, j, k;  
    int n1 = mid - begin + 1;  
    int n2 = end - mid;  
    int L[n1], R[n2];  
    for (i = 0; i < n1; i++)  
        L[i] = arr[begin + i];  
    for (j = 0; j < n2; j++)  
        R[j] = arr[mid + 1 + j];  
    i = 0;  
    j = 0;  
    k = begin;  
    while (i < n1 && j < n2) {  
        if (L[i] <= R[j]) {  
            arr[k] = L[i];  
            i++;  
        } else {  
            arr[k] = R[j];  
            j++;  
        }  
        k++;  
    }  
    while (i < n1) {  
        arr[k] = L[i];  
        i++;  
        k++;  
    }  
    while (j < n2) {  
        arr[k] = R[j];  
        j++;  
        k++;  
    }  
}   


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int arr[], int begin, int end) {         //��鲢����
    if (begin < end) {  
        int mid = begin + (end - begin) / 2;  
        MergeSort(arr, begin, mid);  
        MergeSort(arr, mid + 1, end);  
        Merge(arr, begin, mid, end);  
    } 
} 


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort(int arr[], int low, int high) {  //��������
    if (low < high) {  
        int pi = Partition(arr, low, high);  
        QuickSort(arr, low, pi - 1);  
        QuickSort(arr, pi + 1, high);  
    }  
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */



/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int arr[], int low, int high) {       //��ʿ��
    int pivot = arr[high];  
    int i = (low - 1);  
    for (int j = low; j <= high - 1; j++) {  
        if (arr[j] < pivot) {  
            i++;  
            int temp = arr[i];  
            arr[i] = arr[j];  
            arr[j] = temp;  
        }  
    }  
    int temp = arr[i + 1];  
    arr[i + 1] = arr[high];  
    arr[high] = temp;  
    return (i + 1);  
}    


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int* arr, int n)     //��������
{
   //�ҵ����ֵ
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	int range = max + 1;//���ٿռ������
	int* countArr = (int*)malloc(sizeof(int)*range);//���ٿռ�
	//��ʼ������ȫ��Ϊ0
	memset(countArr, 0, sizeof(int)*range);
	//��ʼ����
	for (int i = 0; i < n; i++)
	{
		countArr[arr[i]]++;
	}
	//��ʼ����
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (countArr[i]--)
		{
			arr[j] = i ;
			j++;
		}
	}
	free(countArr);
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
int getMax(int arr[], int n) {  
    int mx = arr[0];  
    for (int i = 1; i < n; i++)  
        if (arr[i] > mx)  
            mx = arr[i];  
    return mx;  
}
void countSort(int arr[], int n, int exp) {  
    int output[n];  
    int count[10] = {0};  
    for (int i = 0; i < n; i++)  
        count[(arr[i] / exp) % 10]++;  
    for (int i = 1; i < 10; i++)  
        count[i] += count[i - 1];  
    for (int i = n - 1; i >= 0; i--) {  
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];  
        count[(arr[i] / exp) % 10]--;  
    }  
    for (int i = 0; i < n; i++)  
        arr[i] = output[i];  
} 
void RadixCountSort(int arr[], int n) {             //������������
    int max_val = getMax(arr, n);  
    for (int exp = 1; max_val / exp > 0; exp *= 10) {  
        countSort(arr, n, exp);  
    }  
}   
/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size);


/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */

int *testSortingPerformance(int n) {  

    int *arr = (int *)malloc(n * sizeof(int));   
    for (int i = 0; i < n; i++) {  
        arr[i] = rand() ; //����������� 
    }
    return arr;     
}
void clean(char *filename){
    FILE *fp;
    fp=fopen(filename,"w");
    if (fp==NULL){
        printf("error to write !");
        return;
    }
        fprintf(fp,"");
        fclose(fp);
}
//�˵�
char MenuText[9][40]={
"[A]Menu1:ʵ�ֲ���",	
"[B]Menu2:ʵ�ֹ鲢",	
"[C]Menu3:ʵ�ֿ���",	
"[D]Menu4:ʵ�ּ�������",	
"[E]Menu5:ʵ�ֻ�����������",	
"[F]Menu6:�������ݵ��ļ�",
"[G]Menu7:����ļ��������",
"[H]Menu8:��������",
"[Q]Menu9::Exit "
};
//��ʾ�˵�
void displaymenu()
{
int i;
printf("\n=================================================================\n");	
for (i=0;i<9;i++){
        printf("<<%s>>\n",MenuText[i]);
}
printf("\n=================================================================\n");
}
void savetofile(int *arr, char *filename,int n)
{
    // if (arr[0]=='\0'){
    //     printf("print nothing,data is NULL\n");
    //     return;
    // }
    FILE *fp;
    fp=fopen(filename,"a+");
    if (fp==NULL){
        printf("error to write !");
        return;
    }
    for(int i=0;i<n;i++){
        fprintf(fp,"%d ",arr[i]);
    }
    fprintf(fp,"\n");
    fclose(fp);
}