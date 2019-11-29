#include "helper.h"

int main(int argc, char const *argv[])
{
    if (argc < 1)
        m_puts("Wrong amount of arguments");

    DIR *current = m_opendir("./");
    DIR *remote = m_opendir(argv[1]);

    struct dirent *dpd;
    while ((dpd = m_readdir(current)) != NULL)
    {
        m_puts((*dpd).d_name);
        putc('\n', stdout);
    }
    while ((dpd = m_readdir(remote)) != NULL)
    {
        m_puts((*dpd).d_name);
        putc('\n', stdout);
    }
    m_closedir(current);
    m_closedir(remote);
    return EXIT_SUCCESS;
}