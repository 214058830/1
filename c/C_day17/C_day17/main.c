//
//  main.c
//  作业
//
//  Created by 宫斌 on 2018/6/20.
//  Copyright © 2018年 宫斌. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[]={1,2,1,3,2,5,9,9};
    int cnt;
    for(int i=0;i<sizeof arr/ sizeof arr[0];i++){
        cnt=0;
        for(int j=0;j<sizeof arr/ sizeof arr[0];j++){
            if(arr[i]==arr[j]) cnt++;
        }
        if(cnt==1) printf("%d\n",arr[i]);
    }
    return 0;
}
//int main(int argc, const char * argv[]) {
//    int arr[]={1,2,0,3,5,2,0,5};
//    int i,j;
//    for(i=0,j=0;i<sizeof arr/sizeof arr[0];i++){
//        if(arr[i]!=0){
//            arr[j]=arr[i];
//            j++;
//        }
//    }
//        for(;j<i;j++){
//            arr[j]=0;
//        }
//    for(i=0;i<sizeof arr/sizeof arr[0];i++){
//        printf("%d  ",arr[i]);
//    }
//
//}
//
//int main(int argc, const char * argv[]) {
//    int student[]={5,10,20,60};
//    int tang[]={4,10,13,15,18,30};
//    int i,j=0,cnt=0;
//    for(i=0;i<sizeof student/ sizeof student[0];i++){
//        for(;j<sizeof tang / sizeof tang[0];j++){
//            if(student[i]<= tang [j]){
//                cnt++;
//                break;
//            }
//        }
//    }
//    printf("%d\n",cnt);
//}
//
//int main(int argc, const char * argv[]){
//    int money[]={100,50,20,10,5,2,1};
//    int quite=628;
//    int count=0;
//    for(int i=0;i< sizeof money / sizeof money [0]; ){
//        if( quite >= money[i]){
//            quite-=money[i];
//            count++;
//        }
//        else i++;
//    }
//    printf("%d %d\n",quite,count);
//}
//
///* 一瓶水一元钱，两个空瓶可换一瓶水，给20元，可以和多少瓶水*/
//int main(int argc, const char * argv[]){
//    int total=20;
//    int dq=20;
//    int kx=dq;
//    int sy=dq%2;
//
//    while(kx>=1){
//        kx+=sy;
//        total+=kx/2;
//        sy=kx%2;
//        kx=kx/2;
//    }
//    printf("total=%d\n",total);
//    return  0;
//}
int main(int argc, const char * argv[]){
    int money=20,water=0,bottle=0;
    assert(money!=0);
    water=bottle=money;
    while (bottle>=2){
        water+=bottle/2;
        bottle-=(bottle/2);
    }
    printf("%d\n",water);
    return  0;
}

char* mystrcpy(char* dest,const char* src)
{
    char* r=dest;
    assert((dest != NULL) && (src != NULL));
    while((*r++ = *src++)!='\0');
    return dest;
}
char *mystrcat(char *dest,const char *src){
    char *p=dest;
    //assert((dest != NULL) && (src != NULL));
    while(*p!='\0')p++;
    while(*src != '\0')*p++=*src++;
    *p='\0';
    return dest;
}
int main(int argc, const char * argv[]){
    char x[]="abc",y[]="de";
    mystrcat(x, y);
    printf("%s\n",x);
    return 0;
}
