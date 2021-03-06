//
//  main.c
//  C_day13
//
//  Created by 宫斌 on 2018/8/1.
//  Copyright © 2018年 宫斌. All rights reserved.
//

#include <stdio.h>

1.调整数组使奇数全部都位于偶数前面。

void swap(int arr[], int left, int sz){
    int tmp;
    tmp = arr[left];
    for(;left<sz-1;left++){
        arr[left] = arr[left+1];
    }
    arr[left] = tmp;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int count, i, arr[] = {1,2,3,4,5,6,7,8,6,8,9};
    int sz = sizeof(arr)/sizeof(arr[0]);
    for(i=0, count=0; count<sz; count++){
        if(! (arr[i] % 2))
            swap(arr, i, sz);
        else
            i++;
    }
    for(count=0; count<sz; count++){
        printf("%d ", arr[count]);
    }
    return 0;
}

//2.
//杨氏矩阵
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[3][3] = {{1,3,4},{2,4,5},{4,5,6}};
    int col, line, x;
    scanf("%d", &x);
    col = 2;//从左下角元素开始找起
    line = 0;
    while(col >= 0 && line <= 2){
        if(x == arr[col][line]){
            printf("找到了\n");
            break;
        }
        else if (x < arr[col][line]){
            col--;
        }
        else if (x > arr[col][line]){
            line++;
        }
    }
    if(col<0 || line > 2)
        printf("找不到\n");
    return 0;
}
