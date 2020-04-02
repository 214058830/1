//1.使用main函数的参数，实现一个整数计算器，程序可以接受三个参数，第一个参数“-a”选项执行加法，“-s”选项执行减法，“-m”选项执行乘法，“-d”选项执行除法，后面两个参数为操作数。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
	int sum = 0;
	int num1 = atoi(argv[2]);
	int num2 = atoi(argv[3]);
	if (argc != 4){
		printf( "参数输入错误" );
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

//2.写冒泡排序可以排序多个字符串。 
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
