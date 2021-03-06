//
//  main.c
//  C_day12
//
//  Created by 宫斌 on 2018/7/31.
//  Copyright © 2018年 宫斌. All rights reserved.
//

#include <stdio.h>

1.编写函数：
unsigned int reverse_bit(unsigned int value);
这个函数的返回 值value的二进制位模式从左到右翻转后的值
unsigned int reverse_bit(unsigned int value){
    int num = 0, i;
    for(i=0; i<32; i++){
        num |= (value>>i) & 1;
        if(i != 31)
            num = num<<1;
    }
    return num;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int x;
    scanf("%d", &x);
    printf("%d\n", reverse_bit(x));
    return 0;
}
2.不使用（a+b）/2这种方式，求两个数的平均值
int main(int argc, const char * argv[]) {
    // insert code here...
    int a,b;
    scanf("%d%d", &a, &b);
    printf("%d和%d的平均数为%d\n", a, b, ((a-b) >> 1) + b);
    printf("%d和%d的平均数为%d\n", a, b, (a ^ b) >> 1 | (a & b));
    return 0;
}
3.
一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
请找出这个数字。（使用位运算）
int main(int argc, const char * argv[]) {
    int i, count, j, arr[10] = {1,2,3,4,5,1,2,4,5,5};
    for(i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        count = -1;
        for(j=0; j<sizeof(arr)/sizeof(arr[0]); j++){
            if(!(arr[i] ^ arr[j]))
                count++;
        }
        if(!count){
            printf("%d\n", arr[i]);
            break;
        }
    }
    return 0;
}
4.
有一个字符数组的内容为:"student a am i",请你将数组的内容改为"i am a student".
要求：
不能使用库函数。只能开辟有限个空间（空间个数和字符串的长度无关）。
int swap(char arr[],char tmp[], int left, int right, int count){
    int _right = right-1;
    //将数组整体循环移动count+1个字符
    for(; _right>=left; _right--){
        arr[_right+count+1] = arr[_right];
    }
    //左边重新赋值
    for(; count>0; count--,left++){
        arr[left] = tmp[count-1];
    }
    return left;
}

int my_sum(char arr[], int sz){
    int j, count;
    for(count=0, j=0; j<sz-1; j++){
        if(arr[j] == ' ')
            count++;
    }
    return count;
}
int main(int argc, const char * argv[]) {
    char  arr[] = "student a am i";
    char tmp[sizeof(arr)/sizeof(arr[0])];
    int right, count, left, j, sz = sizeof(arr)/sizeof(arr[0]);
    //计算数组arr中' '的个数
    count = my_sum(arr, sz);
    //将数组中每一段的字符保存到tmp数组中
    for(right=sz-2, left=0, j=0; right>left; right--, j++){
        if(arr[right] == ' '){
            left = swap(arr, tmp, left, right, j);
            right = sz-1;
            j = -1;
            if(count--)
                arr[left++] = ' ';
        }
        else tmp[j] = arr[right];
    }
    printf("%s\n", arr);
    return 0;
}
