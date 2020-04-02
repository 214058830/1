/*  这是一个回顾标准c库中 文件I/O的demo
 *      fopen   fclose  fseek   fwrite  fread   fprintf
 */

#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fp = NULL;

    fp = fopen("./test.txt", "a");
    if  (fp == NULL) {
        printf("fopen error!!\n");
        return -1;
    }
    char *ptr = "apple!!";
    fwrite(ptr, strlen(ptr), 1, fp);
    fseek(fp, 10, SEEK_END);
    fwrite(ptr, strlen(ptr), 1, fp);
    
    fseek(fp, 0, SEEK_SET);
    char buff[1024] = {0};
    fread(buff, 1024, 1, fp);
    printf("buff:[%s]\n", buff);

    fprintf(fp, "\n%s-%d-%s\n", "apple", 3, "i love to eat!!");

    fclose(fp);
    return 0;
}
