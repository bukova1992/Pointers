#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define POINTERS_BASCS
void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASCS
	int a = 2;
	int* pa = &a;
	cout << a << endl;// вывод значения переменной 'а' на экран
	cout << &a << endl;// взятие адреса переменной 'а 'прямо при выводе
	cout << pa << endl;//вывод адреса переменной 'а',хранящегося в ра
	cout << *pa << endl;//разыменование указателя 'ра' и вывод значения переменной 'а'  
#endif // POINTERS_BASCS
	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		//cout << arr + i << "\t";
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}