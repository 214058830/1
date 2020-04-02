#include<stdio.h>

//1.实现一个函数，可以左旋字符串中的k个字符。
char* my_char(char arr[], int count, int sz){
	int i, j;
	char tmp;
	count %= sz;
	for(i=0; i<count; i++){
		tmp = arr[0];
		for(j=0; j+1<sz; j++){
			arr[j] = arr[j+1];
		}
		arr[j] = tmp;
	}
	return arr;
}
int main(){
	int sz, count;
	char arr[] = "ABCD";
	sz = sizeof(arr)/sizeof(arr[0]);
	printf("请输入左旋转的个数:");
	scanf("%d",&count);
	printf("%s\n", my_char(arr, count, sz-1));
	return 0;
}
//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
char* my_char(char arr[], int sz){
	int j;
	char tmp;
	tmp = arr[0];
	for(j=0; j+1<sz; j++){
		arr[j] = arr[j+1];
	}
	arr[j] = tmp;
	return arr;
}
int my_strcmp(char arr1[], char arr2[], int sz1,int sz2){
	if(sz1 != sz2){
		return 0;
	}
	for(sz2=0; sz2<sz1-1; sz2++){
		if(strcmp(my_char(arr1, sz1-1),arr2) == 0)
			return 1;
	}
	return 0;
}
int main(){
	char arr1[] = "ABACD";
	char arr2[] = "BCDAA";
	int sz1, sz2;
	sz1 = sizeof(arr1)/sizeof(arr1[0]);
	sz2 = sizeof(arr2)/sizeof(arr2[0]);
	if(my_strcmp(arr1, arr2, sz1, sz2)){
		printf("是旋转得到的\n");
	}
	else
		printf("不是旋转得到的\n");
	return 0;
}