/*  这个代码是我们自己来实现一个建议的迷你shell，能够执行一些其它的
 *  命令；初步看起来的效果跟我们的shell有一定的相似性
 *      
 *  1. 写一个shell的入口，用于提示要输入信息
 *  2. scanf接收一个输入信息
 *     对命令进行解析，看看有没有进行重定向
 *  3. 创建子进程
 *  4. 程序替换
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    while(1) {
        printf("minishell: ");
        fflush(stdout);
        char cmd[1024] = {0};
        //^\n：scanf本身是遇到空格就要获取一次，这样的话就无法获取
        //      到一个完整的命令，因此‘%[^\n]’表示的是获取数据直到
        //      遇到\n为止
        //%*c：将缓冲区中的字符都取出来，但是不要它，直接丢掉
        //      目的是为了将最后的\n从缓冲区取出来，防止陷入死循环
        if (scanf("%[^\n]%*c", cmd) != 1) {
            getchar();
        }
        //将获取到的命令解析一下，判断是否有输出重定向
        //  >  >>
        char *ptr = cmd;
        char *redirect_file = NULL;
        int is_rederect = 0;
        while(*ptr != '\0') {
            if (*ptr == '>') {
                is_rederect++;
                *ptr++ = '\0';
                if (*ptr == '>') {
                    *ptr++ = '\0';
                    is_rederect++;
                }
                while(isspace(*ptr) && *ptr != '\0') {
                    ptr++;
                }
                redirect_file = ptr;
            }
            ptr++;
        }
        int fd;
        if (is_rederect == 1) {
            fd = open(redirect_file, O_WRONLY | O_CREAT | O_TRUNC,
                    0777);
            if (fd < 0) {
                return -1;
            }
        }else if (is_rederect == 2) {
            fd = open(redirect_file, O_WRONLY | O_CREAT | O_APPEND,
                    0777);
            if (fd < 0) {
                return -1;
            }
        }
        printf("file:[%s]\n", redirect_file);
        printf("cmd:[%s]\n", cmd);

        //将获取到的命令解析一下，然后创建子进程进行程序替换
        ptr = cmd;
        char *argv[32] = {NULL};
        int argc = 0;
        argv[argc++] = ptr;
        while(*ptr != '\0') {
            //ls       -l -a
            //argv[0] = "ls"
            //argv[1] = "-l"
            //argv[2] = "-a"
            //int isspace(int c);
            //用于判断一个字符是否是:\t \n \r 空格 
            //解析一个字符串时候这里就是对空格的判断
            //ls    
            if (isspace(*ptr)) {
                while(isspace(*ptr) && *ptr != '\0') {
                    *ptr++ = '\0';
                }
                if (*ptr == '\0')
                    break;
                argv[argc++] = ptr;
            }
            ptr++;
        }
        if  (fork() == 0) {
            if (is_rederect) {
                dup2(fd, 1);
            }
            execvp(argv[0], argv);
        }
        //需要等待的原因：
        //1. 避免产生僵尸子进程
        //2. 是为了等待子进程运行完毕，让程序逻辑更加完善
        wait(NULL);
        
    }
    return 0;
}
