//
//  main.c
//  4_15
//
//  Created by 宫斌 on 2018/6/24.
//  Copyright © 2018年 宫斌. All rights reserved.
//

#include <stdio.h>

int main() {
	// insert code here...
	int x, num;
	for (num = 100; num >= 100 && num <= 200; num++){
		for (x = 2; x<num; x++){
			if (num%x == 0) break;
		}
		if (x == num) printf("%d,", num);
	}
    //printf("Hello, World!\n");
    return 0;
}
//int main(int argc, const char * argv[]) {
//    int row,line;
//    for(row=1;row<10;row++){
//        for(line=1;line<=row;line++){
//            printf ("%d*%d=%d  ",row,line,row*line);
//            if(row==line) printf("\n");
//        }
//    }
//}
//int main(int argc, const char * argv[]) {
//    for(int year=1000;year>=1000&&year<=2000;year++){
//        if(year%4==0&&year%100!=0||year%400==0)
//            printf("%d ",year);
//    }
//}
