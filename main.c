/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:22:55 by rmoriya           #+#    #+#             */
/*   Updated: 2022/02/01 21:00:38 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./Libft/libft.h"

int main()
{
    size_t  len;
    size_t len1;
    char *s = "hoge";

    len = ft_printf("uint = %p", &s);
    putchar('\n');
    len1 = printf("uint = %p", &s);
    putchar('\n');
    printf("len  = %zu\nlen1 = %zu\n", len, len1);
    return (0);
}
