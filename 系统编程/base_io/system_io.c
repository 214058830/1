/*  这是一个io系统调用接口的demo
 *      open    close   read    write   lseek
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int main()
{
    //int open(const char *pathname, int flags, mode_t mode);
    //  pathname:   要打开的文件名
    //  flags：选项标志
    //      O_RDONLY    只读 
    //      O_WRONLY    只写
    //      O_RDWR      读写
    //
    //      O_CREAT     文件不存在则创建，存在则打开
    //      O_EXCL      与O_CREAT同用，若文件存在则报错
    //      O_TRUNC     打开文件的同时，清空文件原有内容
    //      O_APPEND    追加
    //  mode:文件权限，用于创建文件的时候
    //  返回值：正确：非负值（文件描述符） 错误：-1
    int fd = -1;
    fd = open("./tmp.txt", O_RDWR | O_CREAT, 0777);
    if (fd < 0) {
        perror("open error");
        return -1;
    }
    //ssize_t write(int fd, const void *buf, size_t count);
    //  fd: 文件描述符
    //  buf：要写入的数据
    //  count：要写入的数据长度
    //  返回值：实际的写入数据长度
    char *ptr = "apple!!\n";
    ssize_t wlen = write(fd, ptr, strlen(ptr));
    if (wlen < 0) {
        perror("write error");
        return -1;
    }
    //off_t lseek(int fd, off_t offset, int whence);
    //  fd: 文件描述符
    //  offset：偏移值
    //  whence：偏移起始位置
    //      SEEK_SET    文件起始位置
    //      SEEK_CUR    当前读写位置
    //      SEEK_END    文件末尾位置
    lseek(fd, 0, SEEK_SET);

    //read：返回实际读取到的数据长度
    char buff[1024] = {0};
    ssize_t rlen = read(fd, buff, 1024 - 1);
    if (rlen < 0) {
        perror("read error");
        return -1;
    }
    printf("buf:[%s]\n", buff);

    close(fd);
    
    return 0;
}
