#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);

	//1)Вычисляем количество чётных и нечётных элементов
	int even_count = 0;
	int odd_count = 0;
	for (int i = 0; i < n; i++)
	{
		//if (arr[i] % 2 == 0)even_const++;
		//else odd_const++;
		arr[i] % 2 == 0 ? even_count++ : odd_count++; 
	}
	cout << "Количество четных элементов:" << even_count << endl;
	cout << "Количество нечетных элементов:" << odd_count << endl;
	//2)Выделяем память для массивов
	int* even_arr = new int[even_count];
	int* odd_arr = new int[odd_count];
	//Скопируем чётные и нечётные элементы в соответствующие массивы:
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		//if (arr[i] % 2 == 0)even_arr[j++] = arr[i];
		//else (odd_arr[k++] = arr[i]);
		//(arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++]) = arr[i];
		(arr[i] % 2 ? odd_arr[k++] : even_arr[j++]) = arr[i];
	}
	//4)Вывод результатов.
	Print(even_arr, even_count);
	Print(odd_arr, odd_count);
	//Удаление массивов
	delete[] odd_arr;
	delete[] even_arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
