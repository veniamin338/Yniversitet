#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Header_labs_1f.h"
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "Russian");
	FILE* fr = 0;
	int tmp = 0;
	printf("�������� �������� ������:\n1 - ��������� �����\n2 - � ����������\n3 - �� �����\n");
	scanf_s("%d", &tmp);
	if (tmp == 1)
	{
		rand_in_f(fr);
	}
	else if (tmp == 2)
	{
		polzovat_in_f(fr);
	}
	else if (tmp == 3)
	{
		f_in_f(fr);
	}
	return 0;
}
