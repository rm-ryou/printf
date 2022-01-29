/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 08:06:40 by rmoriya           #+#    #+#             */
/*   Updated: 2022/01/29 20:27:21 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

static int ft_printf_char(char c)
{
    ft_putchar_fd(c, 1);
    return (1);
}

static int ft_printf_string(char *s)
{
    if (!s)
        s = "(null)";;
    ft_putstr_fd(s, 1);
    return (ft_strlen(s));
}

static int ft_printf_format(int c, va_list args)
{
    int n;

    n = 0;
    if (c == 'c')
        n = ft_printf_char(va_arg(args, int));
    else if (c == 's')
        n = ft_printf_string(va_arg(args, char *));
    /*else if (c == 'p')
        n = ft_printf_string(va_arg(args, char*));
    else if (c == 'd')
        n = ft_printf_string(va_arg(args, char*));
    else if (c == 'i')
        n = ft_printf_string(va_arg(args, char*));
    else if (c == 'u')
        n = ft_printf_string(va_args, char*);
    else if (c == 'x')
        n = ft_printf_string(va_args, char*);
    else if (c == 'X')
        n = ft_printf_string(va_args, char*);
    else if (c == '%')
        n = ft_printf_string(va_args, char*);*/

    return (n);
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
            len += ft_printf_format(format[i], args);
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

    len = ft_printf("Hello World!%s", "hello world!");
    putchar('\n');
    printf("len = %zu\n", len);
    return (0);
}