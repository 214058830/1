#include<stdio.h>
#include<stdarg.h>
2.使用可变参数，实现函数，求函数参数的平均值。
int average(int n,...){
	va_list arg;
	int i = 0;
	int sum = 0;
	va_start(arg, n);
	for(i=0; i<n; i++){
		sum += va_arg(arg, int);
	}
	return sum/n;
	va_end(arg);
}
int main(){
	int a = 1, b = 2, c = 3;
	int avg1 = average(2, a, c);
	int avg2 = average(3, a, b, c);
	printf("avg1 = %d\n", avg1);
	printf("avg2 = %d\n", avg2);
	return 0;
}
3.使用可变参数，实现函数，求函数参数的最大值。
int Max(int n,...){
	va_list arg;
	int tmp, i = 0;
	int max;
	va_start(arg, n);
	max = va_arg(arg, int);
	va_start(arg, n);
	for(i=0; i<n;){
		tmp = va_arg(arg, int);
		if(max < tmp){
			max = tmp;
			va_start(arg, n);
			i = 0;
		}
		else
			i++;
	}
	return max;
	va_end(arg);
}
int main(){
	int a = 1, b = 2, c = 3, d = 8, e = 5, f = 10;
	int max1 = Max(4, a, c, d, e);
	int max2 = Max(6, a, b, c, d, e, f);
	printf("max1 = %d\n", max1);
	printf("max2 = %d\n", max2);
	return 0;
}
4.1.模拟实现printf函数，可完成下面的功能 
 
能完成下面函数的调用。 
print("s ccc d.\n","hello",'b','i','t'，100); 
函数原型： 
print(char *format, ...) 
 

void print_num(int num)
{
	if (num > 9)
	{
		print_num(num / 10);
	}
	putchar(num % 10 + '0');
}
void print(char* format,...){
	int i = 0, ret;
	char* tmp;
	va_list arg;
	va_start(arg, format);
	while(format[i] != '\0'){
		switch(format[i]){
			case 's':
				tmp = va_arg(arg, char*);
				while (*tmp)
				  {
					  putchar(*tmp);
					  tmp++;
				  }
				break;
			case 'c':
				putchar(va_arg(arg, char));
				break;
			case 'd':
				ret = va_arg(arg, int);
				print_num(ret);
				break;
			case ' ':
				putchar(' ');
				break;
			case '.':
				putchar('.');
				break;
			case '\n':
				putchar('\n');
				break;
			default:
				break;
		}
		i++;
	}
	va_end(arg);
}
int main(){
	print("s ccc d.\n","hello",'b','i','t',100);
	return 0;
}