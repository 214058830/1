#include<stdio.h>

1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲��������� 
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
2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ�� 
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
3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ����磬����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ���19
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
4. ��дһ������reverse_string(char * string)���ݹ�ʵ�֣�
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
5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen
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

6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
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

7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ 
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