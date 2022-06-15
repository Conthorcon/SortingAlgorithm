#include <math.h>
#include <vector>
#include <time.h>
#include <iostream>
#include<iomanip>
using namespace std;

//+---------------------------------------------------------+
//(1.) flash - shell - count
//count compare (1)
void ShellSortC(int a[],int n,long long &ccmp);
void FlashSortC(int a[],int n,long long &ccmp);
void CountingSortC(int a[],int n,long long &ccmp);

//original (1)
void ShellSort(int a[],int n);
void FlashSort(int a[],int n);
void CountingSort(int a[],int n);

//----------------------------------------------------------
//(2.) shaker - radix
//count compare (2)
void shakerSortC(int a[], int n, long long& compare);
void radixSortC(int a[], int n, long long& compare);

//original (2)
void shakerSort(int arr[], int n);
void radixSort(int a[], int n);

//----------------------------------------------------------
//(3.) select - bubble - insert
//measure time (3)
void SelectionSort_T(int a[], int n, double &time);
void BubbleSort_T(int a[], int n, double& time);
void InsertionSort_T(int a[], int n, double& time);

//count compare (3)
void SelectionSort_C(int a[], int n, long long& comp);
void InsertionSort_C(int a[], int n, long long& comp);
void BubbleSort_C(int a[], int n, long long& comp);

//----------------------------------------------------------
//(4.) merge - heap - quick
//compare (4)
void mergeSort(int *, int first, int last, long long& comparisons);
void heapSort(int *, int numberOfElements, long long& comparisons);
void quickSort(int *, int first, int last, long long& comparison);

//original (4)
void quickSort(int a[], int first, int last);
void heapSort(int a[], int n);
void mergeSort(int a[], int first, int last);

//+---------------------------------------------------------+