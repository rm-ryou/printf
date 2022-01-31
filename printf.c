/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 08:06:40 by rmoriya           #+#    #+#             */
/*   Updated: 2022/01/31 20:23:24 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
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

static int ft_base_convert(unsigned long long num, char format)
{
    int  i;
    unsigned long long n;

    i = 0;
    n = num % 16;
    num /= 16;
    if (num > 0)
        ft_base_convert(num, format);
    if (n <= 9)
        i += ft_printf_char(n + '0');
    else
    {
        if (format == 'x')
            i += ft_printf_char(n - 10 + 'a');
        else
            i += ft_printf_char(n - 10 + 'A');
    }
    return (i);
}

static int ft_printf_ptr(unsigned long long ptr)
{
    unsigned long long tmp;
    int     len;

    len = 2;
    ft_printf_string("0x");
    len += ft_base_convert(ptr, 'x');
    return (len);
}

static int ft_printf_int(int i)
{
    int n;
    char *str;

    str = ft_itoa(i);
    n = ft_printf_string(str);
    free(str);
    return (n);
}

static int ft_printf_hexa(unsigned int num, const char format)
{
    int len;

    len = 0;
    len += ft_base_convert(num, format);
    return (len);
}

static int ft_printf_format(va_list args, const char format)
{
    int n;

    n = 0;
    if (format == 'c')
        n = ft_printf_char(va_arg(args, int));
    else if (format == 's')
        n = ft_printf_string(va_arg(args, char *));
    else if (format == 'p')
        n = ft_printf_ptr(va_arg(args, unsigned long long));
    else if (format == 'd' || format == 'i')
        n = ft_printf_int(va_arg(args, int));
    //else if (format == 'u')
    //    n = ft_printf_uint(va_arg(args, unsigned int));
    else if (format == 'x' || format == 'X')
        n = ft_printf_hexa(va_arg(args, unsigned int), format);
    else if (format == '%')
        n = ft_printf_char('%');
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
            len += ft_printf_format(args, format[i]);
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

