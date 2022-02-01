/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:56:03 by rmoriya           #+#    #+#             */
/*   Updated: 2022/02/01 17:24:12 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./Libft/libft.h"

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

int ft_printf_ptr(unsigned long long ptr)
{
    int     len;

    len = 2;
    ft_printf_string("0x");
    len += ft_base_convert(ptr, 'x');
    return (len);
}

int ft_printf_hexa(unsigned int num, const char format)
{
    int len;

    len = 0;
    len += ft_base_convert(num, format);
    return (len);
}