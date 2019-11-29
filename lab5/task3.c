#include "helper.h"

int main(int argc, char const *argv[])
{

    if (!argc)
        return EXIT_FAILURE;

    FILE *file = m_fopen(argv[1], "w");
    /* 128 - is max size of string in terminal ?? */
    char *buffer = malloc(128 * sizeof(char));

    while (true)
    {
        gets(buffer);
        if ((int)buffer[0] == 6)
            break;
        fputs(buffer, file);
        fputs("\n", file);
    }
    m_fclose(file);
    free(buffer);
    /* code */
    return EXIT_SUCCESS;
}