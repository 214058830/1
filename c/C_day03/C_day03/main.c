//
//  main.c
//  C_day03
//
//  Created by 宫斌 on 2018/7/23.
//  Copyright © 2018年 宫斌. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
     //insert code here...
    int a[] = {1,2,3,4,5}, b[] = {6,7,8,9,10}, i, temp;
    for(i=0; i<sizeof(a)/sizeof(a[0]); i++){
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
    for(i=0; i<sizeof(a)/sizeof(a[0]); i++)
        printf("%d ",a[i]);
    for(i=0; i<sizeof(a)/sizeof(a[0]); i++)
        printf("%d ",b[i]);
    return 0;
}
int main(int argc, const char * argv[]) {
    float sum = 0.0, i;
    for(i=1; i<100; i+=2){
        sum+=1/i;
    }
    for(i=2; i<100; i+=2){
        sum-=1/i;
    }
    printf("%f \n",sum);
    return 0;
}
int main(int argc, const char * argv[]) {
    int i, count = 0;
    for(i=1; i<100; i++){
        if(i / 10 == 9) count++;//十位数计算9出现的次数
        if(i % 10 == 9) count++;//个位数计算9出现的次数
    }
    printf("%d \n",count);
    return 0;
}
