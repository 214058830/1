#include<stdio.h>

1.递归和非递归分别实现求第n个斐波那契数。 
int fib1(int num){
	if(num < 3)
		return 1;
	return fib1(num-1) + fib1(num-2);
}
int fib2(int num){
	int b = 1, a = 1, c = 1;
	for(;num>2;num--){
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", fib1(n));
	printf("%d\n", fib2(n));
	return 0;
}
2.编写一个函数实现n^k，使用递归实现 
int Sub_square(const int n, int k){
	if(k == 1)
		return n;
	return n*Sub_square(n, k-1);
}
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	printf("%d\n", Sub_square(n, k));
	return 0;
}
3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19
int DigitSum(n){
	if(n < 10)
		return n;
	else
		return n%10+DigitSum(n/10);
}
int main(){
	unsigned int n;
	scanf("%d", &n);
	printf("%d\n", DigitSum(n));
	return 0;
}
4. 编写一个函数reverse_string(char * string)（递归实现）
#include<stdio.h>
#include<assert.h>
void reverse_string(char * string){
	assert(string != NULL);
	if(*(string++) != '\0')
		reverse_string(string);
	printf("%c", *(string-1));
}
int main(){
	char arr[] = "abcdefg";
	reverse_string(arr);
	printf("\n");
	return 0;
}
5.递归和非递归分别实现strlen
#include<stdio.h>
#include<assert.h>

int my_strlen1(const char arr[]){
	assert(arr != NULL);
	int count = 0;
	while(*(arr++) != '\0'){
		count++;
	}
	return count;
}
int my_strlen2(const char arr[]){
	assert(arr != NULL);
	if(*arr == '\0')
		return 0;
	else
		return 1+my_strlen2(arr+1);
}
int my_strlen3(const char arr[]){
	assert(arr != NULL);
	const char* p = arr;
	while(*p != '\0')
		p++;
	return p-arr;
}
int main(){
	char arr[] = "abcde";
	printf("%d\n", my_strlen1(arr));
	printf("%d\n", my_strlen2(arr));
	printf("%d\n", my_strlen3(arr));
	return 0;
}

6.递归和非递归分别实现求n的阶乘
#include<stdio.h>

int factorial1(int n){
	int sum = 1;
	while(n > 0){
		sum *= n;
		n--;
	}
	return sum;
}
int factorial2(int n){
	if(n == 1){
		return 1;
	}
	return n*factorial2(n-1);
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", factorial1(n));
	printf("%d\n", factorial2(n));
	return 0;
}

7.递归方式实现打印一个整数的每一位 
#include<stdio.h>

void my_print(int num){
	if(num > 9)
		my_print(num/10);
	printf("%d    ", num%10);
}
int main(){
	int num;
	scanf("%d", &num);
	my_print(num);
	printf("\n");
	return 0;
}