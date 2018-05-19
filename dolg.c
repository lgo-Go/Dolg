/*Вставляет элемент в любое место в массиве*/

#include <stdlib.h>
#include <stdio.h>

void dobavka(int *p_mass, int mass_size, int place, int new_element);

int main(void)
{
	int N = 5;                                                        //Изначальное кол-во элементов в массиве
	int * pointer_mass = (int *)malloc(sizeof(int) * (N + 1));        //Выделяем память под массив + под будующий элемент

	printf("before dobavka:\n");
	/*Инициализация и вывод неизменённого массива*/
	for (int i = 1; i <= N ; ++i, ++pointer_mass)
	{
		*pointer_mass = i;
		printf("%i ", *pointer_mass);
	}
	printf("\n");

	dobavka(pointer_mass, N, 3, 9);
	pointer_mass -= N;                                                //Вновь указывает на первый элемент (уже нового массива)

	/*Вывод нового массива*/
	printf("after dobavka:\n");
	for (int i = 1; i <= (N + 1) ; ++i, ++pointer_mass)
	{
		printf("%i ", *pointer_mass);
	}
	printf("\n");
}

void dobavka(int *p_mass, int mass_size, int place, int new_element)
{
	/*Часть массива с place и всем, что справа от него, смещаем вправо на 1 элемент*/
	for (int i = mass_size + 1; i >= (place + 1); --i, --p_mass)
	{
		*p_mass = *(p_mass - 1);
	}

	*p_mass = new_element;                                            //Ставим новый элемент на нужное место 
}