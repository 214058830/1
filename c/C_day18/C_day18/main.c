//1.ʹ��main�����Ĳ�����ʵ��һ��������������������Խ���������������һ��������-a��ѡ��ִ�мӷ�����-s��ѡ��ִ�м�������-m��ѡ��ִ�г˷�����-d��ѡ��ִ�г�����������������Ϊ��������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
	int sum = 0;
	int num1 = atoi(argv[2]);
	int num2 = atoi(argv[3]);
	if (argc != 4){
		printf( "�����������" );
		return 1;
	} 
	if (strcmp(argv[1], "-a") == 0)
	{
		sum = num1 + num2;
	}
	else if (strcmp(argv[1], "-s") == 0)
	{
		sum = num1 - num2;
	}
	else if (strcmp(argv[1], "-m") == 0)
	{
		sum = num1 * num2;
	}
	else if (strcmp(argv[1], "-d") == 0)
	{
		sum = num1 / num2;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}

//2.дð����������������ַ����� 
#include<stdio.h>
#include<string.h>

char* arr_bubble_sort(char(*p)[10], int row)
{
     int i = 0;
     int j = 0;
	 char tmp[10] = {0};
     char* t = tmp;
     for (i=0; i<row-1; i++)
     {
		for(j=i+1; j<row; j++){
			if (strcmp(p[i], p[j])>0){
				strcpy(t, p[j]);
				strcpy(p[j], p[i]);
				strcpy(p[i], t);
			}
		}
     }
	 return p;
}
int main()
{
     char a[][10] = { "abcd", "abdd", "aacd" };
     int row, i = 0;
	 row = sizeof(a)/sizeof(a[0]);
     arr_bubble_sort(a, row);
     for (i = 0; i < row; i++)
     {
        printf("%s\n", a[i]);
     }
     return 0;
}
