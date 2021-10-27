#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

/*
int main()
{	
	double a = 0.0;
	double b = 0.0;

	int i = 0;
	
	for (i = 0; i < 20; i++)
	{
		double c = 0.0;
		int m = 0, b1 =0;

		a = rand();
		b = (a / RAND_MAX);

		
		printf("b = %lf   ", b*1000);

		c = (b*1000)*10000;
		printf("c = %lf   ", c);
		m = (int)c;
		b1 = (int)(b*1000);
		printf("b1 = %d   ", b1);
		m = m - (b1 * 10000);
		printf("m = %d\n   ", m);

	}
	
}
*/
//Программа генерирует множество случайных чисел, их количество(N), нижнюю(niz) и верхнюю(verx) границу
//пользователь вводит с клавиатуры. После этого программа подсчитывает и выводит сумму, 
//формируемую следующим образом: числа, порядковые номера которых совпадают с дробной частью
//хотя бы одного из вводимых чисел – вычитаются, все остальные – прибавляются.

double dr_chislo_diap(double niz, double verx)
{
	double a;
	double b = 0.0;
	a = rand();
	b = (a / RAND_MAX) * (verx-niz)+niz;
	return b;
}

int dr_chast(double aa)
{
	int m1 = 0, a1 = 0;
	double a = 0.0;
	a = aa;
	a1 = (int)a;
	a = a - a1;
	a = a * 1000000;
	m1 = (int)a;
	return m1;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int i = 0, j = 0, k = 0 ;
	int dr_ch_c = 0;
	int N = 0;
	double niz = 0.0, verx = 0.0;
	double summa = 0.0;
	double ch = 0.0;
	double* mas;
	double* mas2;
	

	printf("Количество чисел, N =");
	scanf_s("%d", &N);
	
	printf("Нижняя граница чисел, niz = ");
	scanf_s("%lf", &niz);
	printf("Верхняя граница чисел, verx = ");
	scanf_s("%lf", &verx);
	
	if (N > 250000000)
	{
		printf("\n\nНе хватает памяти для такого количества чисел\nПопробуйте снова\n\n");
		return 1;
	}
	 if(((verx > niz) && (niz >= 0) && (N >= 1))== 0)
	{
		printf("\n\n\nВведены не коректные данные\nПроверьте правильность вводимых значений и повторите попытку\n\n\n");
		return 0;
	}
	
	mas = (double*)malloc(N * sizeof(double));
	mas2 = (double*)malloc(N * sizeof(double));
	for (i = 0; i < N; i++)
	{
		double a = dr_chislo_diap(niz, verx);
		mas[i] = a;
		mas2[i] = a;
	}

	for (j = 0; j < N; j++)
	{
		ch = mas[j];
		dr_ch_c = dr_chast(ch);
		if (dr_ch_c < N) 
		{
			summa -= mas[dr_ch_c];
			mas2[dr_ch_c] = 0.0;
		}
	}
	for (k = 0; k < N; k++)
	{
		if (mas2[k] != 0.0)
			summa += mas2[k];
	}
	printf("\n\n\nСумма = %lf\n\n\n", summa);

	free(mas);
	free(mas2);
	return 0;
}


