#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header_labs_2f.h"
#include <locale.h>


void Puzirek(int* a, int len_a)
{
	int i = 0, g = 0, tmp = 0;
	for (i = 0; i < len_a; i++)
	{
		for (g = 0; g < (len_a - i) - 1; g++)
		{
			if (a[g] > a[g + 1])
			{
				tmp = a[g];
				a[g] = a[g + 1];
				a[g + 1] = tmp;
			}
		}
	}
}

void Vstavka(int* a, int len_a)
{
	int i = 0, g = 1, tmp = 0;
	for (i = 0; i < len_a; i++)
	{
		g = i;
		while (g > 0 && (a[g] < a[g - 1]))
		{
			tmp = a[g - 1];
			a[g - 1] = a[g];
			a[g] = tmp;
			g--;
		}
		
	}
	
}

void qike_sort(int* a, int ot_e, int do_e)
{
	int l = ot_e;
	int r = do_e;
	int sr = a[(int)((l + r) / 2)];

	do
	{
		while (a[l] < sr)
			l++;
		while (a[r] > sr)
			r--;
		if (l <= r)
		{
			int tmp = 0;
			tmp = a[r];
			a[r] = a[l];
			a[l] = tmp;
			l++;
			r--;
		}
	} while (l < r);
	if (ot_e<r)
		qike_sort(a, ot_e, r);
	if (l<do_e)
		qike_sort(a, l, do_e);	
}
	


void f_in_mas(FILE * f, int *d, int** a)
{
	int i = 0;
	fopen_s(&f, "..\\text1_fr.txt", "r");
	while (!feof(f))
	{
		int v = 0;
		fscanf_s(f, "%d\n", &v);
		(*d)++;
	}
	freopen_s(&f , "..\\text1_fr.txt", "r", f);
	*a = (int*)malloc(*d * sizeof(int));
	for (i = 0; i < *d; i++)
	{
		int c = 0;
		fscanf_s(f, "%d\n", &c);
		(*a)[i] = c;
	}
	fclose(f);
}
