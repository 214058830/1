//
//  main.c
//  C_day04
//
//  Created by 宫斌 on 2018/7/24.
//  Copyright © 2018年 宫斌. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int i, j, count=13;
    for(i=0; i<count; i++){
        if(i < count/2+1){
            for(j=0; j<1+i*2; j++)
            printf("*");
        }
        else for(j=1+(count-i-1)*2; j>0; j--)
            printf("*");
        printf("\n");
    }
int main(int argc, const char * argv[]) {
    int i=0, tmp = 0;
    for(i=1; i<=999; i++){
        int count = 1, sum = 0;
        tmp = i;
        while(tmp >= 10){
            count++;
            tmp /= 10;
        }
        tmp = i;
        while(tmp){
            sum += pow(tmp%10, count);
            tmp /= 10;
        }
        if(sum == i)
            printf("%d ",i);
    }
    printf("\n");
int main(int argc, const char * argv[]) {
    int i, sum=0, count=5, num=2;
    for(i=count; i>0; i--,num*=10){
        sum+=num*i;
    }
    printf("%d ",sum);
int main(int argc, const char * argv[]) {
    int count = 0;
    char ch;
    while(ch = getchar() != '\n'){
        if(ch == '{')
            count++;
        else if(ch == '}' && count ==0){
            printf("不成对出现\n");
            return 0;
        }
        else if(ch == '}')
            count--;
    }
    if(count)
        printf("不成对出现\n");
    else
        printf("成对出现\n");
    return 0;
}
