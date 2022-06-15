#include "Sort.h"

//+--------------------------------------------------------------+
//(1.) shaker - radix 
//----------------------------------------------------------------
void radixSort(int a[], int n) 
{
    int maxVal = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] > maxVal)
            maxVal = a[i]; // tim phan tu lon nhat

    int maxDigits = 0;
    do {
    	maxDigits++;
        maxVal /= 10;
    } while (maxVal > 0); // tim so luong chu so cua phan tu lon nhat

    int** tmpArr = new int* [10]; // do co toi da 10 chu so 0 - 9
    for (int i = 0; i < 10; i++)
        tmpArr[i] = new int[n];

    int tmpCount[10];

    for (int i = 0; i < maxDigits; i++) {
        int divide = pow(10, i);

        for (int j = 0; j < 10; j++) // reset lai mang luu so luong
            tmpCount[j] = 0;


        for (int j = 0; j < n; j++) {
            int digit = (a[j] / divide) % 10;
            tmpArr[digit][tmpCount[digit]++] = a[j]; //Bo vao mang theo cac chu so 0 - 9
        }

        int index = 0;
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < tmpCount[j]; k++)
                a[index++] = tmpArr[j][k];
    }
}

void shakerSort(int arr[], int n) {
    int left = 1, right = n - 1, k = n - 1;
    do {
        for (int j = right; j >= left; --j) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                k = j;
            }
        }
        left = k + 1;
        for (int j = left; j <= right; ++j) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                k = j;
            }
        }
        right = k - 1;
    } while (left <= right);
}

void radixSortC(int a[], int n, long long& compare) {
    int maxVal = a[0];

    ++compare;
    for (int i = 1; i < n; i++) {
        ++compare;
        if (a[i] > maxVal)
            maxVal = a[i];
    } // tim phan tu lon nhat

    int maxDigits = 0;
    do {
        maxDigits++;
        maxVal /= 10;
    } while (++compare && maxVal > 0); // tim so luong chu so cua phan tu lon nhat

    int** tmpArr = new int* [10]; // do co toi da 10 chu so 0 - 9
    ++compare;
    for (int i = 0; i < 10; i++) {
        tmpArr[i] = new int[n];
        ++compare;
    }

    int tmpCount[10];

    ++compare;
    for (int i = 0; i < maxDigits; i++) {
        ++compare;
        int divide = pow(10, i);

        ++compare;
        for (int j = 0; j < 10; j++) { // reset lai mang luu so luong
            tmpCount[j] = 0;
            ++compare;
        }

        ++compare;
        for (int j = 0; j < n; j++) {
            int digit = (a[j] / divide) % 10;
            tmpArr[digit][tmpCount[digit]++] = a[j]; //Bo vao mang theo cac chu so 0 - 9
            ++compare;
        }

        int index = 0;
        ++compare;
        for (int j = 0; j < 10; j++) {
            compare += 2;
            for (int k = 0; k < tmpCount[j]; k++)
                a[index++] = tmpArr[j][k];
            ++compare;
        }
    }
}

void shakerSortC(int arr[], int n, long long& compare) {
    int left = 1, right = n - 1, k = n - 1;
    do {
        ++compare;
        for (int j = right; j >= left; --j) {
            ++compare;
            if (++compare && arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                k = j;
            }
        }
        left = k + 1;
        ++compare;
        for (int j = left; j <= right; ++j) {
            ++compare;
            if (++compare && arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                k = j;
            }
        }
        right = k - 1;
    } while (++compare && left <= right);
}

//(2.) selection - bubble - insert
//-----------------------------------------------------------------------------
// Selection Sort Run Time
void SelectionSort_T(int a[], int n, double &time)
{
	clock_t start, end;
	start = clock();
	for (int i = 0; i < n - 1; ++i) {
		int minIdx = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] < a[minIdx])
				minIdx = j;
		}
		swap(a[minIdx], a[i]);
	}
	end = clock();
	time = double(end - start) / double(CLOCKS_PER_SEC);
}

// Insertion Sort Run Time
void InsertionSort_T(int a[], int n, double& time)
{
	clock_t start, end;
	start = clock();
	for (int i = 1; i < n; ++i) {
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
	end = clock();
	time = double(end - start) / double(CLOCKS_PER_SEC);
}

// Bubble Sort Run Time
void BubbleSort_T(int a[], int n, double& time)
{
	clock_t start, end;
	start = clock();
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n - i; j++) {
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	end = clock();
	time = double(end - start) / double(CLOCKS_PER_SEC);
}

// Selection Sort Comparisons
void SelectionSort_C(int a[], int n, long long& comp)
{
	for (int i = 0; ++comp && i < n - 1; ++i) {
		int minIdx = i;
		for (int j = i + 1; ++comp && j < n; ++j)
		{
			if (++comp && a[j] < a[minIdx])
				minIdx = j;
		}
		swap(a[minIdx], a[i]);
	}
}

// Insertion Sort Comparisons
void InsertionSort_C(int a[], int n, long long& comp)
{
	for (int i = 1; ++comp && i < n; ++i) {
		int key = a[i];
		int j = i - 1;
		while (++comp && j >= 0 && ++comp && a[j] > key) {

			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

// Bubble Sort Comparisons
void BubbleSort_C(int a[], int n, long long& comp)
{
	for (int i = 1; ++comp && i < n; i++)
		for (int j = 0; ++comp && j < n - i; j++) {
			if (++comp && a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
}


//(3.) flash - shell - counting
//-----------------------------------------------------------------------------
void Swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void InsertionSort(int a[],int n,long long &ccmp)
{
    for (int i = 1; i < n & ++ccmp ; i++)
	{
		int k = i - 1;
		int key = a[i];
		while (a[k] > key && k >= 0 && ++ccmp)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}
void ShellSortC(int a[],int n,long long &ccmp)
{
    for (int interval = n / 2; interval > 0 & ++ccmp; interval /= 2)
	{
		for (int i = interval; i < n & ++ccmp; i++)
		{
			int temp = a[i];
			int j = i;
			for (j = i; j >= interval & a[j - interval] > temp & ++ccmp & ++ccmp; j -= interval)
			{
				a[j] = a[j - interval];
			}	
			a[j] = temp;
		}
	}
}
void CountingSortC(int a[],int n,long long &ccmp)
{
    int max = a[0];
	for (int i = 1; i < n & ++ccmp; i++)
	{
		if (a[i] > max & ++ccmp)
		{
			max = a[i];
		}
	}

	int *count = new int[max + 1];
	for (int i = 0; i <= max & ++ccmp; i++)
	{
		count[i] = 0;
	}

	for (int i = 0; i < n & ++ccmp; i++)
	{
		count[a[i]]++;
	}

	for (int i = 1; i <= max & ++ccmp; i++)
	{
		count[i] += count[i - 1];
	}

	int *temp = new int[n];
	for (int i = 0; i < n & ++ccmp; i++)
	{
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	for (int i = 0; i < n & ++ccmp; i++)
	{
		a[i] = temp[i];
	}
	
	delete[] count;
	delete[] temp;
}
void FlashSortC(int a[],int n,long long &ccmp)
{
    int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m & ++ccmp; i++)
	{
		l[i] = 0;
	}

	for (int i = 1; i < n & ++ccmp; i++)
	{
		if (a[i] < minVal & ++ccmp)
		{
			minVal = a[i];
		}
		if (a[i] > a[max] & ++ccmp)
		{
			max = i;
		}
	}
	if (a[max] == minVal & ++ccmp)
	{
		return;
	}
	
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n & ++ccmp; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}

	for (int i = 1; i < m & ++ccmp; i++)
	{
		l[i] += l[i - 1];
	}

	Swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	
	while (nmove < n - 1 & ++ccmp)
	{
		while (j > l[k] - 1 & ++ccmp)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}

		flash = a[j];
		if (k < 0 & ++ccmp) 
		{
			break;
		}

		while (j != l[k] & ++ccmp)
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}

	delete[] l;
	InsertionSort(a, n,ccmp);
}

void InsertionSort(int a[],int n)
{
    for (int i = 1; i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while (a[k] > key && k >= 0)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}
void ShellSort(int a[],int n)
{
    for (int interval = n / 2; interval > 0; interval /= 2)
	{
		for (int i = interval; i < n; i++)
		{
			int temp = a[i];
			int j = i;
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
				a[j] = a[j - interval];
			a[j] = temp;
		}
	}
}
void CountingSort(int a[],int n)
{
    int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];

	int *count = new int[max + 1];
	for (int i = 0; i <= max; i++)
		count[i] = 0;

	for (int i = 0; i < n; i++)
		count[a[i]]++;

	for (int i = 1; i <= max; i++)
		count[i] += count[i - 1];

	int *temp = new int[n];
	for (int i = 0; i < n; i++)
	{
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	for (int i = 0; i < n; i++)
		a[i] = temp[i];
	delete[] count;
	delete[] temp;
}
void FlashSort(int a[],int n)
{
    int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	Swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	InsertionSort(a, n);
}

// (4.) merge - heap - quick
//-----------------------------------------------------------------------------
// Compare (4)
// Heap Sort
void heapSort(int*, int, int&);
void heapify(int*, int, int, long long&);

void heapSort(int [], int&);
void buildHeap(int [], int, int, long long&);

void heapSort(int arr[], int numberOfElements, long long& comparison)
{
    for (int index = numberOfElements / 2 - 1; index >= 0; --index)
    {
        buildHeap(arr, numberOfElements, index, comparison);
        ++comparison;
    }
    ++comparison;


    for (int index = numberOfElements - 1; index > 0; --index)
    {
        std::swap(arr[0], arr[index]);
        buildHeap(arr, index, 0, comparison);
        ++comparison;
    }
    ++comparison;
}

void buildHeap(int arr[], int numberOfElements, int currentIndex, long long& comparison)
{
    int leftChild = 2*currentIndex + 1;
    ++comparison;
    if(leftChild >= numberOfElements)
        return;

    int rightChild = 2*currentIndex + 2;
    int largerChild = leftChild;

    ++comparison;
    if (rightChild < numberOfElements)
    {
        ++comparison;
        if (arr[rightChild] > arr[largerChild])
            largerChild = rightChild;
    }

    ++comparison;
    if (arr[largerChild] > arr[currentIndex])
    {
        std::swap(arr[currentIndex], arr[largerChild]);
        buildHeap(arr, numberOfElements, largerChild, comparison);
    }
}
// Quick Sort
void quickSort(int arr[], int first, int last, long long& comparison)
{
    int pivot = arr[(first + last) / 2];
    int i = first, j = last;
    do
    {
        while (arr[i] < pivot)
        {
            ++i;
            ++comparison;
        }
        ++comparison;

        while (arr[j] > pivot)
        {
            j--;
            ++comparison;
        }
        ++comparison;

        ++comparison;
        if (i <= j)
        {
            std::swap(arr[i], arr[j]);
            ++i;
            --j;
        }

        ++comparison;
    } while (i < j);

    ++comparison;
    if (first < j) quickSort(arr, first, j, comparison);

    ++comparison;
    if (i < last)  quickSort(arr, i, last, comparison);
}
// Merge Sort
void mergeSubArray(int arr[], int first, int mid, int last, long long& comparison)
{
    int first1 = first, last1 = mid;
    int first2 = mid + 1, last2 = last;

    int* tempArr { new int [last + 1] };
    int index = first1;

    while (first1 <= last1 && first2 <= last2)
    {
        comparison += 3;
        if (arr[first1] <= arr[first2])
            tempArr[index++] = arr[first1++];
        else
            tempArr[index++] = arr[first2++];
    }
    (first1 <= last1) ? (comparison += 2) : (++comparison);

    while (first1 <= last1)
    {
        tempArr[index++] = arr[first1++];
        ++comparison;
    }
    ++comparison;

    while (first2 <= last2)
    {
        tempArr[index++] = arr[first2++];
        ++comparison;
    }
    ++comparison;

    for (int index = first; index <= last; ++index)
    {
        arr[index] = tempArr[index];
        ++comparison;
    }
    ++comparison;

    delete[] tempArr;
}

void mergeSort(int arr[], int first, int last, long long& comparison)
{
    ++comparison;
    if (first >= last)
        return;

    int mid = first + (last - first) / 2;
    mergeSort(arr, first, mid, comparison);
    mergeSort(arr, mid + 1, last, comparison);
    mergeSubArray(arr, first, mid, last, comparison);
}

// Original (4)
int partition(int a[], int first, int last)
{
	int pivot = a[(first + last) / 2];
	int i = first;
	int j = last;
	int tmp;
	while (i <= j)
	{
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	return i;
}
void quickSort(int a[], int first, int last)
{
	int index = partition(a, first, last);
	if (first < index - 1)
		quickSort(a, first, index - 1);
	if (index < last)
		quickSort(a, index, last);
}

void heapRebuild(int a[], int pos, int n)
{

	while (2 * pos + 1 < n)
	{
		int j = 2 * pos + 1;
		if (j < n - 1)
			if (a[j] < a[j + 1])
				j = j + 1;
		if (a[pos] >= a[j])
			return;
		Swap(a[pos], a[j]);
		pos = j;
	}
}
void heapConstruct(int a[], int n)
{
	for (int i = (n - 1) / 2; i >= 0; i--)
		heapRebuild(a, i, n);
}
void heapSort(int a[], int n)
{
	heapConstruct(a, n);
	int r = n - 1;
	while (r > 0)
	{
		Swap(a[0], a[r]);
		heapRebuild(a, 0, r);
		r--;
	}
}

void merge(int a[], int first, int mid, int last)
{
	int n1 = mid - first + 1;
	int n2 = last - mid;
	int *L = new int[n1];
	int *R = new int[n2];
	for (int i = 0; i < n1; i++)
		L[i] = a[first + i];
	for (int j = 0; j < n2; j++)
		R[j] = a[mid + j + 1];
	int i = 0;
	int j = 0;
	int k = first;
	while (i < n1 && j < n2)
		a[k++] = (L[i] < R[j]) ? L[i++] : R[j++];

	while (j < n2)
		a[k++] = R[j++];
	while (i < n1)
		a[k++] = L[i++];
	delete[] L;
	delete[] R;
}
void mergeSort(int a[], int first, int last)
{
	if (first < last)
	{
		int mid = first + (last - first) / 2;
		mergeSort(a, first, mid);
		mergeSort(a, mid + 1, last);
		merge(a, first, mid, last);
	}
}
//+--------------------------------------------------------------+

