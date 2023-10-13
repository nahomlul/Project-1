#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Parses the /proc/cpuinfo file on a Linux system to retrieve 
 * and print information about each processor and its cache size.
 */
void parse_cpuinfo() {
    FILE *file = fopen("/proc/cpuinfo", "r");
    if (!file) {
        perror("Failed to open /proc/cpuinfo");
        return;
    }

    char line[256];// Buffer to hold each line read from the file
    int cpu_count = 0; // Counter for the number of processors

    while (fgets(line, sizeof(line), file)) {
        // If the line starts with "processor", increment the cpu_count
        if (strncmp(line, "processor", 9) == 0) {
            cpu_count++;
        }
        // // If the line starts with "cache size", print the CPU number and cache size
        if (strncmp(line, "cache size", 10) == 0) {
            printf("Processor %d with a cache size of %s", cpu_count, line);
        }
    }

    fclose(file);
}

int main() {
    parse_cpuinfo();
    return 0;
}