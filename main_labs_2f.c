#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header_labs_2f.h"
#include <locale.h>
#include < time.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	int* mas;
	int ks = 0;
	int ks_n = 0;
	int i = 0;
	clock_t t1, t2;
	FILE* fr = 0;
	f_in_mas(fr, &ks, &mas);
	ks_n = ks;
	while(1)
	{
		int tmp = 0;
		printf("Выберите действие:\n1-печать\n2-сортировка\n3-сброс\n4-выход\n");
		scanf_s("%d", &tmp);
		if (tmp == 1)
		{
			printf("\n");
			for (i = 0; i < ks; i++)
			{
				printf("%d\n", mas[i]);
			}
			printf("\n");
		}
		else if (tmp == 2)
		{
			int tmp_2 = 0;
			printf("Выберите сортировку:\n1 - Пузырьком\n2 - Вставкой\n3 - Быстрая\n");
			scanf_s("%d", &tmp_2);
			if (tmp_2 == 1)
			{
				t1 = clock();
				Puzirek(mas, ks);
				t2 = clock();
			}
			if (tmp_2 == 2)
			{
				t1 = clock();
				Vstavka(mas, ks);
				t2 = clock();
			}
			if (tmp_2 == 3)
			{
				t1 = clock();
				qike_sort(mas, 0, ks-1);
				t2 = clock();
			}
			//printf("\nВремя работы сортировки:%lf\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
		}
		else if (tmp == 3)
		{
			f_in_mas(fr, &ks_n, &mas);
			ks_n = ks;
		}
		else if (tmp == 4)
		{
			int i = 0;
			fopen_s(&fr, "..\\text1_fr.txt", "w");
			for (i = 0; i < ks; i++)
			{
				fprintf(fr, "%d\n", mas[i]);
			}
			fclose(fr);
			free(mas);
			break;
		}
	}
	return 0;
} 