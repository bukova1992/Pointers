#include<iostream>
using namespace std;
#define tab "\t"
void FillRand(int arr[], int n);
void FillRand(char arr[], int n);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int n, int rows=0, int cols=100);
template<typename T>
void Print(T arr[], int n);
template<typename T>
void Print(T** arr, int rows, int cols);
template<typename T> 
T* push_back(T arr[], int& n, T v);
template<typename T>
T* push_front(T arr[], int& n, T v);
template<typename T> 
T* pop_back(T arr[], int& n);
template<typename T>
T* pop_front(T arr[], int& n);

int* insert(int arr[], int& n, int indx, int val);
template<typename T>
T* erase(T arr[], int& n, int indx, T val);

int** allocate(int const rows, int const cols);
void clear(int** arr, int rows);

int** push_row_back(int** arr, int& rows, int cols);
int** push_row_front(int** arr, int& rows, int cols);
int** insert_row(int** arr, int& rows, int cols, int nrow);
template<typename T>
T pop_row_back(int** arr, int& rows);
int** pop_row_back(int** arr, int rows, const int cols);
void pop_row_front(int** arr, int& rows, int cols);
void erase_row(int** arr, int& rows, int cols, int drow);

int** push_col_front(int** arr, int rows, int& cols);
int** insert_col(int** arr, int rows, int& cols, int ncol);

int** pop_col_back(int** arr, int rows, int& cols);
int** pop_col_front(int** arr, int rows, int& cols);
int** erase_col(int** arr, int rows, int& cols, int dcol);
template<typename T>
DataType** arr = Allocate<DataType>(rows, cols);
void push_col_back(int** arr, const int rows, int& cols);

#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2

void main()
{
#ifdef DYNAMIC_MEMORY_1
	setlocale(LC_ALL, "Russia");
	int n;
	cout << "Enter the size of list: "; cin >> n;
	typedef char DataType;
	DataType* arr = new DataType[n];
	FillRand(arr, n);
	Print(arr, n);
	DataType value; cout << "Enter new element: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	arr = push_front(arr, n, value);

	Print(arr, n);
	//arr = pop_back(arr, n);
	Print(arr, n);
	arr = pop_front(arr, n);
	Print(arr, n);
	delete[] arr;
#endif 
#ifdef DYNAMIC_MEMORY_2
	int n;
	cout << "Enter the size of list: "; cin >> n;
	int* arr = new int[n];
	Fillrand(arr, n);
	int v, indx, indx2;
	cout << "Enter the numb of el: "; cin >> indx;
	cout << "Enter the value: "; cin >> v;
	arr = insert(arr, n, indx, v);
	Print(arr, n);
	cout << "Enter the numb of el to delete: "; cin >> indx2;
	arr = erase(arr, n, indx2, v);
	Print(arr, n);
#endif 
	//int rows, cols;
	//cout << "Enter the size of list: "; cin >> rows >> cols;
	//int** arr = allocate(rows, cols);
	//FillRand(arr, rows, cols);
	//Print(arr, rows, cols);

	////dblarr = push_row_back(dblarr, rows,cols);
	//arr = push_row_front(arr, rows, cols);

	//arr = pop_row_back(arr, rows, cols);
	//Print(arr, rows, cols);

	//int nrow, drow, ncol, dcol;
	//cout << "Enter the numb of line to add: "; cin >> nrow;
	//dblarr = insert_row(dblarr, rows,cols, nrow);

	//pop_row_back(dblarr, rows);
	//pop_row_front(dblarr, rows, cols);

	//cout << "Enter the numb of line to delete: "; cin >> drow;
	//erase_row(dblarr, rows, cols,drow);

	//dblarr = push_col_back(dblarr, rows, cols);
	//dblarr = push_col_front(dblarr, rows, cols);

	//cout << "Enter the numb of column add: "; cin >> ncol;
	//dblarr = insert_col(dblarr, rows,cols, ncol);

	//dblarr = pop_col_front(dblarr, rows, cols);

	//cout << "Enter the numb of column to delete: "; cin >> dcol;
	//	dblarr = erase_col(dblarr, rows, cols,dcol);

	/*push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	clear(arr, rows);*/
}
void FillRand(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand();
	}
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand();
	}
}
void FillRand(double arr[],const int n, int minRand,int maxRand)
{
	minRand *= 100;
	maxRand *= 100; 
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand-minRand)+minRand;
		*(arr + i) /= 100; 
	}
}
void FillRand(int** arr, const int n, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)arr[i][j] = rand() % 100;
}
template<typename T>
void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
template<typename T>
void Print(T** arr,const int rows,const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}
template<typename T> 
T* push_back(T arr[], int& n, T v)
{
	//create a reverse array with memory we need
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	//arr1[n] = value;
	delete[] arr;
	//change address of old massive with address of new massive arr1
	arr = buffer;
	//now we got more place, exactly for 1 new element
	arr[n] = v;
	n++;
	return arr;
}
template<typename T> 
T* push_front(T arr[], int& n, T v)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = v;
	n++;
	return buffer;
}
template<typename T>
T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

template<typename T>
T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

int* insert(int arr[], int& n, int indx, int val)
{
	int* buffer = new int[++n];
	for (int i = 0; i < n; i++)
	{
		if (i >= indx)buffer[i + 1] = arr[i];
		else buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[indx] = val;
	return buffer;
}
template<typename T>
T* erase(T arr[], int& n, int indx, int val)
{
	T* buffer = new [--n];
	for (int i = 0; i < n; i++)
	{
		if (i >= indx)buffer[i] = arr[i + 1];
		else buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}
template<typename T>
T** allocate(T const rows, int const cols)
{
	T** dblarr = new T* [rows];
	for (int i = 0; i < rows; i++)dblarr[i] = new int[cols];
	return dblarr;
}
void clear(int** arr, int rows)
{
	for (int i = 0; i < rows; i++)delete[] arr[i];
	delete[] arr;
}

int** push_row_back(int** arr, int& rows, int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}
int** push_row_front(int** arr, int& rows, int cols)
{
	int** buff = new int* [rows + 1];
	for (int i = 0; i < rows; i++)buff[i + 1] = arr[i];
	delete[] arr;
	buff[0] = new int[cols] {};
	rows++;
	return buff;
}
//int** insert_row(int** arr, int& rows, int cols, int nrow)
//{
//	/*int** buff = allocate(++rows, cols);
//	for (int i = 0; i < rows - 1; i++)
//		for (int j = 0; j < cols; j++)
//			if (i >= nrow - 1)buff[i + 1][j] = arr[i][j];
//			else buff[i][j] = arr[i][j];
//	for (int j = 0; j < cols; j++)buff[nrow - 1][j] = 0;
//	clear(arr, rows - 1);
//	return buff;*/
//}
template<typename T>

T pop_row_back(T** arr, int& rows)
{
	delete[] arr[rows - 1];
	rows--;
}
template<typename T>
T pop_row_front(T** arr, int& rows, int cols)
{
	/*for (int i = 0; i < rows - 1; i++)
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = arr[i + 1][j];
		}*/
	pop_row_back(arr, rows);
}
void erase_row(int** arr, int& rows, int cols, int drow)
{
	for (int i = 0; i < rows - 1; i++)
		for (int j = 0; j < cols; j++)
			if (i >= drow - 1)arr[i][j] = arr[i + 1][j];
	pop_row_back(arr, rows);
}

//int** push_col_back(int** arr, int rows, int& cols)
//{
//	/*int** buff = allocate(rows, ++cols);
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols - 1; j++)buff[i][j] = arr[i][j];
//		buff[i][cols - 1] = rand() % 100;
//	}
//	clear(arr, rows);
//	return buff;*/
//}
//int** push_col_front(int** arr, int rows, int& cols)
//{
//	/*int** buff = allocate(rows, ++cols);
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols - 1; j++)buff[i][j + 1] = arr[i][j];
//		buff[i][0] = rand() % 100;
//	}
//	clear(arr, rows);
//	return buff;*/
//}
//int** insert_col(int** arr, int rows, int& cols, int ncol)
//{
//	/*int** buff = allocate(rows, ++cols);
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			if (j >= ncol - 1)buff[i][j + 1] = arr[i][j];
//			else buff[i][j] = arr[i][j];
//			if (j == ncol - 1)buff[i][j] = 0;
//		}
//	}
//	clear(arr, rows);
//	return buff;*/
//}

//int** pop_col_back(int** arr, int rows, int& cols)
//{
//	/*int** buff = allocate(rows, --cols);
//	for (int i = 0; i < rows; i++)
//		for (int j = 0; j < cols; j++)buff[i][j] = arr[i][j];
//	clear(arr, rows);
//	return buff;*/
//}
//int** pop_col_front(int** arr, int rows, int& cols)
//{
//	/*int** buff = allocate(rows, --cols);
//	for (int i = 0; i < rows; i++)
//		for (int j = 0; j < cols; j++)buff[i][j] = arr[i][j + 1];
//	clear(arr, rows);
//	return buff;*/
//}
//int** erase_col(int** arr, int rows, int& cols, int dcol)
//{
//	/*int** buff = allocate(rows, --cols);
//	for (int i = 0; i < rows; i++)
//		for (int j = 0; j < cols; j++)
//		{
//			if (j >= dcol - 1)buff[i][j] = arr[i][j + 1];
//			else buff[i][j] = arr[i][j];
//		}
//	clear(arr, rows);
//	return buff;*/
//}
template<typename T>
T** pop_row_back(T** arr, int rows, const int cols)
{
	//
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr[rows];//Удаляем удаляемую строку из памяти
	delete[] arr;
	return buffer;
}
template<typename T>

void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < cols; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

