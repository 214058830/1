//
//  main.c
//  C_day02
//
//  Created by 宫斌 on 2018/7/16.
//  Copyright © 2018年 宫斌. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int x=1,y=0;
    x=x^y;//异或运算 二进制中不同为1相同为0
    y=x^y;
    x=x^y;
    printf("x=%d,y=%d\n",x,y);
    return 0;
}
int main(int argc, const char * argv[]) {
    int x=1,y=0;
    x=x+y;
    y=x-y;
    x=x-y;
    printf("x=%d,y=%d\n",x,y);
    return 0;
}
int main(int argc, const char * argv[]) {
    int arg[10]={4,5,3,10,2,8,7,6,9,1},i,MAX;
    for(i=1, MAX=arg[0]; i<sizeof(arg)/sizeof(arg[0]); i++){
        if(MAX < arg[i]) MAX = arg[i];
    }
    printf("MAX=%d\n",MAX);
    return 0;
}
int main(int argc, const char * argv[]) {
    int i, j, x, a[3] = {0,1,2};
    for(i=0; i<2; i++){
        for(j=i+1; j<3; j++){
            if(a[i] < a[j]){
                x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
    }
    for(i=0;i<3;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    int num1, num2, temp;
    scanf("%d%d",&num1,&num2);

    while(temp=num1%num2){
        num1 = num2;
        num2 = temp;
    }
    printf("最大公约数为：%d\n",num2);//m*n/最大公约数=最小公倍数
    return 0;
}





