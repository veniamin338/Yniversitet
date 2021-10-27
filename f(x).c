#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

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
		for (i = 0; i < N; i++)
	{
		double a = dr_chislo_diap(niz, verx);
		mas[i] = a;
		printf("mas[%d] = %lf\n", i, mas[i]);
		}

	for (j = 0; j < N; j++)
	{
		ch = mas[j];
				dr_ch_c = dr_chast(ch);
			if (dr_ch_c < N) 
		{
			summa -= mas[dr_ch_c];
			mas[dr_ch_c] = 0.0;
			
	}
	}
	for (k = 0; k < N; k++)
	{	
		if (mas[k] != 0.0)
			summa += mas[k];
		
	}
	printf("\n\n\nСумма = %lf\n\n\n", summa);
	free(mas);
	return 0;
}


