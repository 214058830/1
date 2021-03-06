//
//  main.c
//  C_day05
//
//  Created by 宫斌 on 2018/7/25.
//  Copyright © 2018年 宫斌. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int x, y;
    printf("输入被猜数字：");
    scanf("%d", &x);
    printf("猜数字开始：");
    do{
        scanf("%d",&y);
        if(y < x)
            printf("猜小了\n");
        else if(y > x)
            printf("猜大了\n");
    }
    while (y != x);
    printf("猜正确\n");
    return 0;
}
int search(int* arr, int x, int sz){//折半查找法。。。
    int left = 0, right, mid;
    right = sz - 1;
    while(left <= right){
        mid = (right - left) / 2 + left;
        if(arr[mid] < x)
            left = ++mid;
        else if(arr[mid] > x)
            right = --mid;
        else{
            printf("%d\n",mid);
            return 0;
        }
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    int arr[]={1,2,3,4,5,6,7,8,9,10},sz, x;
    scanf("%d", &x);//输入你要查找的数字
    sz = sizeof(arr) / sizeof(arr[0]);
    if(search(arr, x, sz))
        printf("找不到\n");
    return 0;
}
int main(int argc, const char * argv[]) {
    int i;
    char password[10]={0};

    for(i=3; i>0; i--){
        scanf("%s", password);
        if(strcmp(password, "123456") == 0){
            printf("登录成功\n");
            break;
        }
        else
            printf("密码错误，请重新登录。\n");
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    char ch;
    while((ch=getchar()) != EOF){
        if(ch >= 'A' && ch <= 'Z'){
            putchar(ch+32);
            printf("\n");
        }
        else if(ch >= 'a' && ch <= 'z'){
            putchar(ch-32);
            printf("\n");
        }
    }
    return 0;
}
