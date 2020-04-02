//
//  main.c
//  C_day07
//
//  Created by 宫斌 on 2018/7/27.
//  Copyright © 2018年 宫斌. All rights reserved.
//

#include <stdio.h>
#include <math.h>
1
void fun(x){
    int row,line;
    for(row=1;row<=x;row++){
        for(line=1;line<=row;line++){
            printf ("%d*%d=%d  ",row,line,row*line);
            if(row==line) printf("\n");
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int x;
    scanf("%d",&x);
    fun(x);
    return 0;
}
2
void swap(int* pa, int* pb){
    int tmp;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

int main(int argc, const char * argv[]) {
    int a, b;
    scanf("%d%d",&a, &b);
    swap(&a, &b);
    printf("%d,%d\n",a, b);
    return 0;
}
3
void fun(int year){
    if(year%4==0&&year%100!=0||year%400==0)
        printf("%d是闰年\n",year);
    else
        printf("%d不是闰年\n",year);
}

int main(int argc, const char * argv[]) {
    int a;
    scanf("%d", &a);
    fun(a);
    return 0;
}
4
void print(int* p){
    int x;
    for(x=0; x<10; x++){
        printf("%d ", p[x]);
    }
    printf("\n");
}
void init (int *p){
    int i;
    for(i=0; i<10; i++){
        p[i] = i;
    }
}
void empty(int* p, int sz){
    memset(p, 0, sz*sizeof(p[0]));
}
void reverse(int *p, int sz){
    int tmp, i;
    for(i=0; i<sz-1-i; i++){
        tmp = p[sz-1-i];
        p[sz-i] = p[i];
        p[i] = tmp;
    }
}
int main(int argc, const char * argv[]) {
    int sz, arr[10]={0};
    sz = sizeof(arr) / sizeof(arr[0]);
    init(arr);
    print(arr);
    reverse(arr, sz);
    print(arr);
    empty(arr, sz);
    print(arr);
    return 0;
}
5
int fun(num){
    int x;
    for(x=2; x<=sqrt(num); x++){
        if(num%x==0){
            printf("%d不是素数\n",num);
            return 0;
        }
    }
    printf("%d是素数\n",num);
    return 0;
}
int main(int argc, const char * argv[]) {
    int x;
    scanf("%d", &x);
    fun(x);
    return 0;
}
