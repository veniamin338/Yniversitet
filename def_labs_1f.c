#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header_labs_1f.h"
#include <locale.h>

void rand_in_f(FILE *f)
{
	int N = 0, min = 0, max = 0;
	int i = 0;
	fopen_s(&f, "..\\text1_fr.txt", "w");
	printf("Введите количество чисел: ");
	scanf_s("%d", &N);
	printf("min = ");
	scanf_s("%d", &min);
	printf("max = ");
	scanf_s("%d", &max);

	for (i = 0; i < N; i++)
	{
		int a = 0;
		a = (int)(((double)rand() / RAND_MAX) * (max - min) + min);
		fprintf(f, "%d\n", a);
	}
	fclose(f);
}
void polzovat_in_f(FILE* f)
{
	int n = 0;
	int i = 0;
	fopen_s(&f, "..\\text1_fr.txt", "w");
	printf("Количество чисел :");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		int a = 0;
		scanf_s("%d", &a);
		fprintf(f, "%d\n", a);
	}
	fclose(f);
}
void f_in_f(FILE* f)
{
	FILE* frc = 0;
	printf("Введите путь к файлу для чтения: ");
	scanf_s("\n");
	char* pkfr;
	int i = 1;
	pkfr = (char*)malloc(256);
	fgets(pkfr, 255, stdin);
	pkfr[strlen(pkfr) - 1] = 0;
	fopen_s(&frc, pkfr, "r");
	fopen_s(&f, "..\\text1_fr.txt", "w");
	while (!feof(frc))
	{
		int a = 0;
		fscanf_s(frc, "%d\n", &a);
		fprintf(f, "%d\n", a);
	}
	fclose(f);
	fclose(frc);
	free(pkfr);
}