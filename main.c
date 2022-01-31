/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:22:55 by rmoriya           #+#    #+#             */
/*   Updated: 2022/01/31 20:35:31 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    size_t  len;
    char *s = "hoge";

    len = ft_printf("Hello World!%x tmp %p", -15, (void *)0);
    printf("\n printf_p = %x tmp %p\n", 15, (void *)0);
    putchar('\n');
    printf("len = %zu\n", len);
    return (0);
}