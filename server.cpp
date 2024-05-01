#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <string>

char* number_to_words(int num) {
    char* units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char* teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char* tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    static char words[100];

    if (num == 0)
        return strcpy(words, "zero");

    strcpy(words, "");

    if (num >= 100) {
        strcat(words, units[num / 100]);
        strcat(words, " hundred ");
        num %= 100;
    }

    if (num >= 20) {
        strcat(words, tens[num / 10]);
        if (num % 10 != 0) {
            strcat(words, " ");
            strcat(words, units[num % 10]);
        }
    } else if (num >= 11) {
        strcat(words, teens[num - 10]);
    } else if (num > 0) {
        strcat(words, units[num]);
    }

    return words;
}


#define FIFO_NAME "./mailbox"

int main() {
    int fd;
    char buf[256];

    mkfifo(FIFO_NAME, 0666);

    std::cout << "Server started. Waiting for messages...\n";

    while (1) {
        fd = open(FIFO_NAME, O_RDONLY);
        read(fd, buf, sizeof(buf));
        close(fd);

        int number = atoi(buf);

        std::cout << "Received: " << number_to_words(number) << std::endl;
    }

    return 0;
}
