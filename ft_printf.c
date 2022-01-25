#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

/*nt ft_printf_format(int c, va_list args)
{
    int n;

    n = 0;
    if (c == 'c')
    {
        printf("\nprintf_char\n");
        n = ft_printf_char(va_args, int);
    }
    //else if (c == 's')
    //    n = ft_printf_char(va_args, char*);
    return (n);
}
*/
void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

int ft_printf(const char *format, ...)
{
    size_t  i;
    size_t  len;
    va_list args;

    i = 0;
    len = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            //len += ft_printf_format(format[i], args);
            continue;
        }
        else
        {
            ft_putchar_fd(format[i], 1);
            len++;
        }
        i++;
    }
    va_end(args);
    return (len);
}

int main()
{
    size_t  len;

    len = ft_printf("Hello World!%c");
    putchar('\n');
    printf("len = %zu\n", len);
    return (0);
}