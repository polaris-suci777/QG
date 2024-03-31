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
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void InsertSort(int arr[], int n) {         //插入排序
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
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void Merge(int arr[], int begin, int mid, int end) {  //先二分
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
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int arr[], int begin, int end) {         //后归并排序
    if (begin < end) {  
        int mid = begin + (end - begin) / 2;  
        MergeSort(arr, begin, mid);  
        MergeSort(arr, mid + 1, end);  
        Merge(arr, begin, mid, end);  
    } 
} 


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort(int arr[], int low, int high) {  //快速排序
    if (low < high) {  
        int pi = Partition(arr, low, high);  
        QuickSort(arr, low, pi - 1);  
        QuickSort(arr, pi + 1, high);  
    }  
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */



/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int arr[], int low, int high) {       //找士兵
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
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int* arr, int n)     //计数排序
{
   //找到最大值
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	int range = max + 1;//开辟空间的数量
	int* countArr = (int*)malloc(sizeof(int)*range);//开辟空间
	//初始化数组全部为0
	memset(countArr, 0, sizeof(int)*range);
	//开始计数
	for (int i = 0; i < n; i++)
	{
		countArr[arr[i]]++;
	}
	//开始排序
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
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
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
void RadixCountSort(int arr[], int n) {             //基数计数排序
    int max_val = getMax(arr, n);  
    for (int exp = 1; max_val / exp > 0; exp *= 10) {  
        countSort(arr, n, exp);  
    }  
}   
/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size);


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */

int *testSortingPerformance(int n) {  

    int *arr = (int *)malloc(n * sizeof(int));   
    for (int i = 0; i < n; i++) {  
        arr[i] = rand() ; //随机生成数字 
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
//菜单
char MenuText[9][40]={
"[A]Menu1:实现插入",	
"[B]Menu2:实现归并",	
"[C]Menu3:实现快排",	
"[D]Menu4:实现计数排序",	
"[E]Menu5:实现基数计数排序",	
"[F]Menu6:保存数据到文件",
"[G]Menu7:清除文件里的数据",
"[H]Menu8:生成数据",
"[Q]Menu9::Exit "
};
//显示菜单
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