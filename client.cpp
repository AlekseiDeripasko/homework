#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_NAME "./mailbox"

int main() {
    int fd;
    char buf[256];

    printf("Enter a number: ");
    fgets(buf, sizeof(buf), stdin);

    fd = open(FIFO_NAME, O_WRONLY);
    write(fd, buf, strlen(buf)+1);
    close(fd);

    printf("Number sent to server.\n");

    return 0;
}
