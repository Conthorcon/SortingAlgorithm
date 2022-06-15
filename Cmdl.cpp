#include "DataGenerator.h"
#include "Sort.h"
#include "Cmdl.h"

//(1.) CmdL12
//--------------------------------------------------------------------
bool isDigit(char* s) {
	int i = 1;
	while (s[i] != '\0') {
		if (s[i] < '0' || s[i] > '9')
			return 0;
		i++;
	}
	return 1;
}
void copyArray(int a[], int*& b, int n) {
	b = new int[n];
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
void writeToFile(string fileName, int a[], int n) {
	ofstream fileOut(fileName);
	fileOut << n << endl;

	for (int i = 0; i < n; i++)
		fileOut << a[i] << " ";

	fileOut.close();
}

void readFile(string fileName, int*& a, int& n) {
	ifstream fileIn(fileName);

	fileIn >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		fileIn >> a[i];

	fileIn.close();
}
void checkAlgorithmNameC(string algorithmName, int a[], int n, long long& compare) {
	if (algorithmName == "selection-sort")
		SelectionSort_C(a, n, compare);
	else if (algorithmName == "insertion-sort")
		InsertionSort_C(a, n, compare);
	else if (algorithmName == "bubble-sort")
		BubbleSort_C(a, n, compare);
	else if (algorithmName == "shaker-sort")
		shakerSortC(a, n, compare);
	else if (algorithmName == "shell sort")
		quickSort(a,0, n, compare);
	else if (algorithmName == "heap-sort")
		heapSort(a, n, compare);
	else if (algorithmName == "merge-sort")
		mergeSort(a,0, n, compare);
	else if (algorithmName == "quick-sort")
		ShellSortC(a, n, compare);
	else if (algorithmName == "counting-sort")
		CountingSortC(a, n, compare);
	else if (algorithmName == "radix-sort")
		radixSortC(a, n, compare);
	else if (algorithmName == "flash-sort")
		FlashSortC(a, n, compare);
	else
		cout << "Unknown sorting algorithm!";
}

void checkAlgorithmNameT(string algorithmName, int a[], int n, double& time) {
	clock_t start, end;
	start = clock();

	if (algorithmName == "selection-sort")
	{
		SelectionSort_T(a, n,time);
		return;
	}
	else if (algorithmName == "insertion-sort")
	{
		InsertionSort_T(a, n,time);
		return;
	}
	else if (algorithmName == "bubble-sort")
	{
		SelectionSort_T(a, n,time);
		return;
	}
	else if (algorithmName == "shaker-sort")
		shakerSort(a, n);
	else if (algorithmName == "shell sort")
		ShellSort(a, n);
	else if (algorithmName == "heap-sort")
		heapSort(a,n);
	else if (algorithmName == "merge-sort")
		mergeSort(a,0,n);
	else if (algorithmName == "quick-sort")
		quickSort(a,0,n);
	else if (algorithmName == "counting-sort")
		CountingSort(a, n);
	else if (algorithmName == "radix-sort")
		radixSort(a, n);
	else if (algorithmName == "flash-sort")
		FlashSort(a, n);
	else
		cout << "Unknown sorting algorithm!";

	end = clock();

	time = (double)(end - start);
}

void changeName(string& name) {
	for (int i = 0; i < name.size(); i++)
		if (name[i] == '-') {
			name[i] = ' ';
			break;
		}
	name[0] = toupper(name[0]);
}

void checkOutput(string output, long long compare, double time) {
	if (output == "-time")
		cout << "Running time: " << time << "\n\n";
	else if (output == "-comp")
		cout << "Comparisions: " << compare << "\n\n";
	else if (output == "-both") {
		cout << "Running time: " << setprecision(20) << time << endl;
		cout << "Comparisions: " << compare << "\n\n";
	}
}

void checkOrder(string order, int a[], int n, string& orderName) {
	int type;
	if (order == "-rand") {
		orderName = "Randomize";
		type = 0;
	}
	else if (order == "-sorted") {
		orderName = "Sorted";
		type = 1;
	}
	else if (order == "-rev") {
		orderName = "Reversed";
		type = 2;
	}
	else if (order == "-nsorted") {
		orderName = "Nearly sorted";
		type = 3;
	}
	else
		type = 4;

	GenerateData(a, n, type);
}

void cmd1(string algorithmName, string fileName, string output) {
	long long compare = 0;
	double time = 0;
	int n;

	int* a;
	readFile(fileName, a, n);

	if (output == "-comp")
		checkAlgorithmNameC(algorithmName, a, n, compare);
	else if (output == "-time")
		checkAlgorithmNameT(algorithmName, a, n, time);
	else if (output == "-both") {
		int* b;

		copyArray(a, b, n);
		checkAlgorithmNameC(algorithmName, a, n, compare);
		checkAlgorithmNameT(algorithmName, b, n, time);

		delete[]b;
	}
	changeName(algorithmName);

	cout << "Algorithm: " << algorithmName << endl;
	cout << "Input file: " << fileName << endl;
	cout << "Input size: " << n << endl;
	cout << "-------------------------\n";

	checkOutput(output, compare, time);

	string fileOut = "output.txt";
	writeToFile(fileOut, a, n);


	delete[]a;

}

void cmd2(string algorithmName, string order, string output, int n) {
	long long compare = 0;
	double time = 0;
	string orderName = "";


	int* a = new int[n];
	checkOrder(order, a, n, orderName);

	string fileOut = "input.txt";
	writeToFile(fileOut, a, n);

	if (output == "-comp")
		checkAlgorithmNameC(algorithmName, a, n, compare);
	else if (output == "-time")
		checkAlgorithmNameT(algorithmName, a, n, time);
	else if (output == "-both") {
		int* b;
		copyArray(a, b, n);
		checkAlgorithmNameC(algorithmName, a, n, compare);
		checkAlgorithmNameT(algorithmName, b, n, time);

		delete[]b;
	}

	changeName(algorithmName);

	cout << "Algorithm: " << algorithmName << endl;
	cout << "Input order: " << orderName << endl;
	cout << "Input size: " << n << endl;
	cout << "-------------------------\n";

	checkOutput(output, compare, time);

	fileOut = "output.txt";
	writeToFile(fileOut, a, n);

	delete[]a;
}

//(2.) CmdL3 
//--------------------------------------------------------------------------
void ChangeName(string a)
{
    a[0] = toupper(a[0]);
    
    int i = a.find("-");
    
    cout << a.substr(0,i) << " ";
    a[i + 1] = toupper(a[i + 1]);
    cout << a.substr(i + 1,a.size() - 1);
}
void WriteFile(string filename,int arr[],int size_arr)
{
    ofstream ofs;
    ofs.open(filename);

    ofs << size_arr << endl;

    if(!ofs.is_open())
    {
        cout << "Can't open file.";
        return;
    }

    for(int i = 0; i < size_arr; i++)
    {
        ofs << arr[i] << " ";
    }

    ofs.close();
}
bool Sort(string algorithmName,int arr[],int n,double &rtime,long long &compare)
{
    clock_t start,end;

	start = clock();

    if (algorithmName == "selection-sort")
		SelectionSort_C(arr, n, compare);
	else if (algorithmName == "insertion-sort")
		InsertionSort_C(arr, n, compare);
	else if (algorithmName == "bubble-sort")
		BubbleSort_C(arr, n, compare);
	else if (algorithmName == "shaker-sort")
		shakerSortC(arr, n, compare);
	else if (algorithmName == "shell sort")
		quickSort(arr,0, n, compare);
	else if (algorithmName == "heap-sort")
		heapSort(arr, n, compare);
	else if (algorithmName == "merge-sort")
		mergeSort(arr,0, n, compare);
	else if (algorithmName == "quick-sort")
		ShellSortC(arr, n, compare);
	else if (algorithmName == "counting-sort")
		CountingSortC(arr, n, compare);
	else if (algorithmName == "radix-sort")
		radixSortC(arr, n, compare);
	else if (algorithmName == "flash-sort")
		FlashSortC(arr, n, compare);
	else
	{
		cout << "Unknown sorting algorithm!";
		return false;
	}

	end = clock();

    rtime = (double)(end - start);
    return true;
}
void OutputParameter(string op,double rtime,long long ccmp)
{
    if(op == "-time")
        cout << "Running time: " << rtime << " ms"<< "\n\n";
    else if(op == "-comp")
        cout << "Comparisons: " << ccmp << "\n\n";
    else if(op == "-both")
    {
        cout << "Running time: " << rtime << " ms"<< endl;
        cout << "Comparisons: " << ccmp << "\n\n";
    }
    else
        cout << "Invalid output parameter!\n\n";
}
void PrintArray(int arr[],int size_arr)
{
    for(int i = 0; i < size_arr; i++)
    {
        cout << arr[i] << " ";
    }
}
void CommandLine3(string algorithm,int input_size,string output_parameter)
{   
    int is = input_size;
    double rtime = 0;
    long long ccmp = 0;
    bool checksorted = false;

    int *arr_rand = new int[is];
    int *arr_nsort = new int[is];
    int *arr_sort = new int[is];
    int *arr_rev = new int[is];

    GenerateRandomData(arr_rand,is); 
    GenerateSortedData(arr_sort,is);
    GenerateReverseData(arr_rev,is);
    GenerateNearlySortedData(arr_nsort,is);

    cout << "Algorithm: ";
    string al;
    al = algorithm;
    ChangeName(al);
    cout << endl;
    cout << "Input size: "<< is << "\n\n";

    char i1[] = "input_1.txt";
    char i2[] = "input_2.txt";
    char i3[] = "input_3.txt";
    char i4[] = "input_4.txt";

    WriteFile(i1,arr_rand,is);
    WriteFile(i2,arr_nsort,is);
    WriteFile(i3,arr_sort,is);
    WriteFile(i4,arr_rev,is);

    cout << "Input order: Randomize" << endl;
    cout << "----------------------" << endl;
    checksorted = Sort(algorithm,arr_rand,is,rtime,ccmp);
    if(checksorted)
        OutputParameter(output_parameter,rtime,ccmp);

    cout << "Input order: Nearly Sorted" << endl;
    cout << "----------------------" << endl;
    checksorted = Sort(algorithm,arr_nsort,is,rtime,ccmp);
    if(checksorted)
        OutputParameter(output_parameter,rtime,ccmp);

    cout << "Input order: Sorted" << endl;
    cout << "----------------------" << endl;
    checksorted = Sort(algorithm,arr_sort,is,rtime,ccmp);
    if(checksorted)
        OutputParameter(output_parameter,rtime,ccmp);

    cout << "Input order: Reversed" << endl;
    cout << "----------------------" << endl;
    checksorted = Sort(algorithm,arr_rev,is,rtime,ccmp);
    if(checksorted)
        OutputParameter(output_parameter,rtime,ccmp);

    char o1[] = "output_1.txt";
    char o2[] = "output_2.txt";
    char o3[] = "output_3.txt";
    char o4[] = "output_4.txt";

    WriteFile(o1,arr_rand,is);
    WriteFile(o2,arr_nsort,is);
    WriteFile(o3,arr_sort,is);
    WriteFile(o4,arr_rev,is);

    delete[] arr_rand;
    delete[] arr_nsort;
    delete[] arr_sort;
    delete[] arr_rev;
}

//(4.)  CmdL5
//---------------------------------------------------------------
// Command line 5: Run two sorting algorithms on the data generated automatically.
// [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
void GenerateData(int a[], int n, int dataType);

int CheckOrder(string &input_order)
{
	if (input_order == "-rand")
	{
		input_order = "Randomize";
		return 0;
	}
	else if (input_order == "-sorted")
	{
		input_order = "Sorted";
		return 1;
	}
	else if (input_order == "-rev")
	{
		input_order = "Reversed";
		return 2;
	}
	else if (input_order == "-nsorted")
	{
		input_order = "Nearly Sorted";
		return 3;
	}
	else return -1;
}

string Sort(string algo, int a1[], int a2[], int size, double& time, long long& comp)
{
	clock_t start, end;
	if (algo == "selection-sort")
	{
		SelectionSort_T(a1, size, time);
		SelectionSort_C(a2, size, comp);
		return "Selection Sort";
	}
	else if (algo == "insertion-sort")
	{
		InsertionSort_T(a1, size, time);
		InsertionSort_C(a2, size, comp);
		return "Insertion Sort";
	}
	else if (algo == "bubble-sort")
	{
		BubbleSort_T(a1, size, time);
		BubbleSort_C(a2, size, comp);
		return "Bubble Sort";
	}
	else if (algo == "heap-sort")
	{
		start = clock();
		
		heapSort(a1,size,comp);
		
		end = clock();
		time = (double)(end - start);
		heapSort(a2,size,comp);
		return "Heap Sort";
	}
	else if (algo == "merge-sort")
	{
		start = clock();
		
		mergeSort(a1,0, size,comp);
		
		end = clock();
		time = (double)(end - start);
		mergeSort(a2,0, size,comp);
		return "Merge Sort";
	}
	else if (algo == "quick-sort")
	{
		start = clock();
		
		quickSort(a1,0, size,comp);
		
		end = clock();
		time = (double)(end - start);
		quickSort(a2,0, size,comp);
		return "Quick Sort";
	}
	else if (algo == "radix-sort")
	{
		start = clock();
		
		radixSortC(a1, size,comp);
		
		end = clock();
		time = (double)(end - start);
		radixSortC(a2, size,comp);
		return "Radix Sort";
	}
	else if (algo == "shaker-sort")
	{
		start = clock();
		
		shakerSortC(a1, size,comp);
		
		end = clock();
		time = (double)(end - start);
		shakerSortC(a2, size,comp);
		return "Shaker Sort";
	}
	else if (algo == "shell-sort")
	{
		start = clock();
		
		ShellSortC(a1, size,comp);
		
		end = clock();
		time = (double)(end - start);
		ShellSortC(a2, size,comp);
		return "Shell Sort";
	}
	else if (algo == "counting-sort")
	{
		start = clock();
		
		CountingSortC(a1, size,comp);
		
		end = clock();
		time = (double)(end - start);
		CountingSortC(a2, size,comp);
		return "Counting Sort";
	}
	else if (algo == "flash-sort")
	{
		start = clock();
		
		FlashSortC(a1, size,comp);
		
		end = clock();
		time = (double)(end - start);
		FlashSortC(a2, size,comp);
		return "Flash Sort";
	}
	else return "X";

}
int* CopyArray(int* a, int size)
{
	int* copy = new int[size];
	for (int i = 0; i < size; i++)
		*(copy + i) = *(a + i);
	return copy;
}

void WriteFile(fstream& input, int a[], int size)
{
	input << size << endl;
	for (int i = 0; i < size; i++)
		input << a[i] << " ";
}

void CommandLine5(char *algo_1, char *algo_2, int input_size, char *input_order)
{
	string a1, a2, order;
	int size;
	a1 = algo_1;
	a2 = algo_2;
	order = input_order;
	size = input_size;

	int check_order = CheckOrder(order);
	int* arr1 = new int[size];
	
	GenerateData(arr1, size, check_order);

	int* arr2 = new int[size];
	int* arr3 = new int[size];
	int* arr4 = new int[size];
	arr2 = CopyArray(arr1, size);
	arr3 = CopyArray(arr1, size);
	arr4 = CopyArray(arr1, size);

	fstream input_file("input.txt");

	WriteFile(input_file, arr1, size);

	input_file.close();


	long long comp_1 = 0, comp_2 = 0;
	double time_1 = 0, time_2 = 0;
	string sort_1, sort_2;

	sort_1 = Sort(a1, arr1, arr2, size, time_1, comp_1);
	sort_2 = Sort(a2, arr3, arr4, size, time_2, comp_2);

	if (sort_1 == "X" || sort_2 == "X" || size <= 0 || check_order == -1) cout << "Invalid input!" << endl;
	else
	{
		cout << "Algorithm: " << sort_1 << " | " << sort_2 << endl;
		cout << "Input size: " << size << endl;
		cout << "Input order: " << order << endl;
		cout << "-----------------------" << endl;
		cout << "Running time: " << fixed << time_1 << setprecision(5) << " | " << fixed << time_2 << setprecision(5) << endl;
		cout << "Comparisons: " << comp_1 << " | " << comp_2 << endl;
	}
	
	delete[] arr1;
	delete[] arr2;
}
