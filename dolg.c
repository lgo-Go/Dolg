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
	for (int i = 0; i < N ; ++i)
	{
		*(pointer_mass + i) = i + 1;
		printf("%i ", *(pointer_mass + i));
	}
	printf("\n");

	dobavka(pointer_mass, N, 3, 9);

	/*Вывод нового массива*/
	printf("after dobavka:\n");
	for (int i = 0; i < (N + 1) ; ++i)
	{
		printf("%i ", *(pointer_mass + i));
	}
	printf("\n");
}

void dobavka(int *p_mass, int mass_size, int place, int new_element)
{
	/*Часть массива с place и всем, что справа от него, смещаем вправо на 1 элемент*/
	for (int i = mass_size; i >= place; --i)
	{
		*(p_mass + i) = *(p_mass + i - 1);
	}

	*(p_mass + place - 1) = new_element;                                            //Ставим новый элемент на нужное место 
}