/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:10:18 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/09 16:50:19 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*print_positive_numbers(char *res, intmax_t n, int i)
{
	n = (n > 0 ? n : -n);
	if (!(res = (char*)ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i > 0)
	{
		res[i - 1] = (uintmax_t)n % 10 + 48;
		n = (uintmax_t)n / 10;
		i--;
	}
	return (res);
}

static char		*print_positive_numbers_uns(char *res, uintmax_t n, int i)
{
	if (!(res = (char*)ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i > 0)
	{
		res[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (res);
}

char			*ft_itoa_signed(intmax_t n)
{
	char				*res;
	int					i;

	res = NULL;
	i = ft_intlength((uintmax_t)n);
	if (n != 0)
		return (print_positive_numbers(res, n, i));
	res = ft_memalloc(2);
	res[0] = '0';
	return (res);
}

char			*ft_itoa_unsigned(uintmax_t n)
{
	char				*res;
	int					i;

	res = NULL;
	i = ft_intlength_uns(n);
	if (n != 0)
		return (print_positive_numbers_uns(res, n, i));
	res = ft_memalloc(2);
	res[0] = '0';
	return (res);
}

char			*ft_itoa_base_uns(uintmax_t value, int base,
		t_flagsntype flntp)
{
	char		*s;
	char		c;
	uintmax_t	i;
	uintmax_t	n;
	int			sign;

	c = (char)((flntp.type == 'X') ? 'A' : 'a');
	n = value;
	sign = (value > 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base - 10 + c;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}
