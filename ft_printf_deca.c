/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_deca.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:00:53 by rmoriya           #+#    #+#             */
/*   Updated: 2022/02/01 17:22:58 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./Libft/libft.h"

int ft_printf_char(char c)
{
    ft_putchar_fd(c, 1);
    return (1);
}

int ft_printf_string(char *s)
{
    if (!s)
        s = "(null)";;
    ft_putstr_fd(s, 1);
    return (ft_strlen(s));
}

int ft_printf_int(int i)
{
    int n;
    char *str;

    str = ft_itoa(i);
    n = ft_printf_string(str);
    free(str);
    return (n);
}