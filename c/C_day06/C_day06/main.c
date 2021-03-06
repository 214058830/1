//
//  main.c
//  C_day06
//
//  Created by 宫斌 on 2018/7/26.
//  Copyright © 2018年 宫斌. All rights reserved.
//

#include <stdio.h>
#include"math.h"

int count_one_bits1(unsigned int value)
{
    int i, count = 0;
    for(i=0; i<32; i++) {
        if((value>>i) & 1){
            count++;
        }
    }
    // 返回 1的位数
    return count;
}

int count_one_bits2(unsigned int value)
{
    int count = 0;
    while (value) {
        if(value%2)
            count++;
        value = value/2;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int x;
    scanf("%d", &x);
    printf("%d的二进制中1的个数为%d\n", x, count_one_bits1(x));
    printf("%d的二进制中1的个数为%d\n", x, count_one_bits2(x));
    return 0;
}
int main(int argc, const char * argv[]) {
    int x, i;
    scanf("%d", &x);
    printf("%d的奇数位为:", x);
    for(i=30; i>=0; i-=2){
        printf("%d", x>>i & 1);
    }
    printf("\n%d的偶数位为:", x);
    for(i=31; i>0; i-=2){
        printf("%d", x>>i & 1);
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    int x, i;
    scanf("%d", &x);
    printf("%d的二进制为:", x);
    for(i=31; i>=0; i--){
        printf("%d", x>>i & 1);
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    int m, n, temp, count = 0;
    scanf("%d%d", &m, &n);
    temp = m ^ n;
    while(temp){
        temp = temp & (temp - 1);
        count++;
    }
    printf("%d", count);
    return 0;
}
