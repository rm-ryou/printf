/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:56:03 by rmoriya           #+#    #+#             */
/*   Updated: 2022/02/01 21:00:02 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./Libft/libft.h"

static void ft_count_hexa(unsigned long long num, char format, int *len)
{
    if (num >= 16)
    {
        ft_count_hexa(num / 16, format, len);
        num %= 16;
    }
    if (num <= 9)
        *len += ft_printf_char(num + '0');
    else
    {
        if (format == 'x')
            *len += ft_printf_char(num - 10 + 'a');
        else
            *len += ft_printf_char(num - 10 + 'A');
    }
}

static int ft_base_convert(unsigned long long num, char format)
{
    int  len;

    len = 0;
    ft_count_hexa(num, format, &len);
    return (len);
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