#include "helper.h"

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

    FILE *file = m_fopen(argv[1], "r");
    const size_t GROUPING = atoi(argv[2]);
    char *buffer = malloc(BUFFER_SIZE * sizeof(char));

    while (getc(stdin) && !checkEof(buffer))
    {
        if (GROUPING == 0)
        {
            m_gets(buffer, BUFFER_SIZE, file);
            if (!checkEof(buffer))
                m_puts(buffer);
        }
        for (size_t i = 0; i < GROUPING; i++)
        {
            m_gets(buffer, BUFFER_SIZE, file);
            if (!checkEof(buffer))
                m_puts(buffer);
        }
    }
    m_fclose(file);
    free(buffer);

    return EXIT_SUCCESS;
}