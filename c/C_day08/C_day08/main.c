//
//  main.c
//  C_day08
//
//  Created by 宫斌 on 2018/7/28.
//  Copyright © 2018年 宫斌. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[5]={0}, i, ret;
    for(arr[0]=1; arr[0]<=5; arr[0]++){
        for(arr[1]=1; arr[1]<=5;arr[1]++){
            for(arr[2]=1; arr[2]<=5;arr[2]++){
                for(arr[3]=1; arr[3]<=5;arr[3]++){
                    for(arr[4]=1; arr[4]<=5;arr[4]++){
                        if(((arr[1] == 2) + (arr[0] == 3) == 1) && ((arr[1] == 2) + (arr[4] == 4) == 1) && ((arr[2] == 1) + (arr[3] == 2) == 1) && ((arr[2] == 5) + (arr[3] == 3) == 1) && ((arr[4] == 4) + (arr[0] == 1) == 1))
                        {
                            for(i=0, ret = 0; i<5; i++){
                                ret |= 1<<(arr[i]-1);
                            }
                            for(i=0; i<5; i++)
                                if(((ret >> i) & 1) == 0){
                                    break;
                                }
                            if(5 == i)
                                printf("A=%d B=%d C=%d D=%d E=%d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int arr[4], i;
    for(i=0; i<4; i++){
        memset(arr, 0, sizeof(arr));
        arr[i] = 1;
        if((arr[0] !=1) + (arr[2] == 1) + (arr[3] == 1) + (arr[3] != 1) == 3)
            printf("凶手是%c\n", 'A'+i);
    }
    return 0;
}

int main()
{
    int i,j,a[10][10];
    for(i=0;i<10;i++)
    {
        a[i][0]=1;
        a[i][i]=1;
    }
    for(i=2;i<10;i++)
        for(j=1;j<i;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];

    for(i=0;i<10;i++)
    {
        for(j=0;j<10-i;j++)
        {
            printf(" ");
        }
        for(j=0;j<=i;j++)
        {
            printf("%2d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
