/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:39:47 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/09 16:55:14 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*if1(char *res, t_flagsntype flntp, intmax_t n)
{
	int		i;
	char	*res1;
	char	*res2;

	i = 0;
	if (n < 0)
	{
		if (flntp.dot == 0)
			res = ft_add_char(&res, '-');
		flntp.number--;
	}
	if (flntp.plus == 1 && flntp.space == 0 && n >= 0)
		flntp.number--;
	res1 = flag_space(res, flntp, n);
	res2 = ft_itoa_signed(n);
	res = ft_strjoin_free(&res1, &res2);
	if (flntp.space == 1)
		flntp.number--;
	if (flntp.space == 1 && n < 0 && flntp.minus == 1)
		flntp.number++;
	while (i++ < flntp.number - (flntp.sizenoll > ft_intlength(n) ?
				flntp.sizenoll : ft_intlength(n)))
		res = ft_add_char(&res, ' ');
	return (res);
}

char	*if2if1(char **res, t_flagsntype *flntp, intmax_t n, int i)
{
	char	*res1;
	char	*res2;

	flntp->number = (flntp->space == 1 || flntp->plus == 1 || (flntp->noll == 1
				&& flntp->minus == 0)) ? flntp->number - 1 : flntp->number;
	if (flntp->space == 1 && flntp->noll == 1 && flntp->plus == 0)
	{
		*res = ft_add_char(res, ' ');
		flntp->space = 0;
	}
	res1 = flag_space(*res, *flntp, n);
	res2 = ft_itoa_signed(n);
	*res = ft_strjoin_free(&res1, &res2);
	while (i++ < flntp->number - (flntp->sizenoll > ft_intlength(n)
				? flntp->sizenoll : ft_intlength(n)))
		*res = ft_add_char(res, ' ');
	return (*res);
}

char	*if2(char *res, t_flagsntype flntp, intmax_t n, int i)
{
	char	*res1;
	int		j;

	j = 0;
	if (flntp.dot == 1 && flntp.sizenoll != 0)
		return (dotsizenoll(res, flntp, n));
	else if (flntp.dot)
		return (ft_presflags(res, flntp, n));
	else if (flntp.minus == 1)
		res = if2if1(&res, &flntp, n, i);
	else
	{
		flntp.number = ((flntp.space || flntp.plus) && !flntp.noll &&
				!flntp.oct) ? flntp.number + 1 : flntp.number;
		flntp.number = (flntp.noll == 1 || flntp.minus || (flntp.space &&
					!flntp.plus)) ? flntp.number - 1 : flntp.number;
		res1 = flag_space(res, flntp, n);
		return (ft_add_char(&res1, '0'));
	}
	return (res);
}

char	*elsei(char *res, t_flagsntype flntp, intmax_t n)
{
	char	*res1;

	res1 = ft_itoa_signed(n);
	res = flag_space(res, flntp, n);
	res = ft_strjoin_free(&res, &res1);
	return (res);
}

char	*ft_print_int(va_list ap, t_flagsntype flntp, char *res)
{
	intmax_t n;

	if (flntp.hljz.l == 1 || flntp.type == 'D')
		n = va_arg(ap, long int);
	else if (flntp.hljz.ll == 1)
		n = va_arg(ap, long long int);
	else if (flntp.hljz.h == 1)
		n = (short)va_arg(ap, int);
	else if (flntp.hljz.hh == 1)
		n = (signed char)va_arg(ap, int);
	else if (flntp.hljz.j == 1)
		n = va_arg(ap, intmax_t);
	else if (flntp.hljz.z == 1)
		n = va_arg(ap, size_t);
	else
		n = va_arg(ap, int);
	if (flntp.minus == 1 && n != 0)
		res = if1(res, flntp, n);
	else if (n == 0)
		res = if2(res, flntp, n, 1);
	else
		res = elsei(res, flntp, n);
	return (res);
}
