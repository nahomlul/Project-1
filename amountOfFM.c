#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Parses the /proc/meminfo file on a Linux system to retrieve and print 
 * information about the system's free memory and buffers.
 */
void parse_meminfo() {
    FILE *file = fopen("/proc/meminfo", "r");
    if (!file) {
        perror("Failed to open /proc/meminfo");
        return;
    }
    char line[256];// Buffer to store each line read from the file
    while (fgets(line, sizeof(line), file)) {
        // If the line starts with "Free Memory:", print it
        if (strncmp(line, "Free Memory:", 8) == 0) {
            printf("%s", line);
        }
        // If the line starts with "Buffers:", print it
        if (strncmp(line, "Buffers:", 8) == 0) {
            printf("%s", line);
        }
    }
    fclose(file);
}


int main() {
    parse_meminfo();
    return 0;
}