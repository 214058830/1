#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    printf("hello printf");
    fwrite("hello fwrite", 12, 1, stdout);
    write(0, "hello write", 11);

    sleep(10);
    return 0;
}
