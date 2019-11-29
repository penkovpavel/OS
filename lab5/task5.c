#include "helper.h"
#include <sys/stat.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1000
#endif

int checkEof(char *arr)
{
    for (size_t i = 0;; i++)
    {
        if (arr[i] == '\n')
            return false;
        if (arr[i] == EOF)
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    if (!argc)
        return EXIT_FAILURE;

    FILE *file_read_from = m_fopen(argv[1], "r");
    FILE *file_write_to = m_fopen(argv[2], "w");
    struct stat stats;
    stat(argv[1], &stats);

    char *buffer = malloc(BUFFER_SIZE * sizeof(char));

    while (!checkEof(buffer))
    {
        m_gets(buffer, BUFFER_SIZE, file_read_from);
        if (!checkEof(buffer))
            m_fputs(buffer, file_write_to);
    }
    m_fclose(file_read_from);
    m_fclose(file_write_to);
    chmod(argv[2], stats.st_mode);
    free(buffer);
    /* code */
    return EXIT_SUCCESS;
}