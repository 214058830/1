//
//  main.c
//  C_day11
//
//  Created by 宫斌 on 2018/7/31.
//  Copyright © 2018年 宫斌. All rights reserved.
//

#include <stdio.h>


//5.写一个宏可以将一个数字的奇数位和偶数位交换。

#define swap(num)  ((((num)&0x55555555)<<1)|(((num)&0xAAAAAAAA)>>1))

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", swap(n));
}
//6.使用宏实现两个数中求较大值。
#define max(x, y) ((x)>(y)?(x):(y))

int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", max(x, y));
    return 0;
}
