/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:33:22 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/10 19:41:43 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*elseif1(char *res, t_flagsntype *flntp, intmax_t n, int j)
{
	int		i;

	i = 0;
	if (flntp->plus == 0 && n >= 0 && flntp->space == 1 && id(*flntp))
	{
		res = ft_add_char(&res, ' ');
		flntp->number--;
	}
	if (flntp->plus && n == 1)
		flntp->number--;
	while (i++ < flntp->number - (flntp->sizenoll > j ? flntp->sizenoll : j))
		res = ft_add_char(&res, ' ');
	if (n < 0 && id(*flntp))
		res = ft_add_char(&res, '-');
	else if (flntp->plus == 1 && n >= 0 && id(*flntp))
		res = ft_add_char(&res, '+');
	while (i++ <= flntp->number - j)
		res = ft_add_char(&res, '0');
	return (res);
}

char	*ifnottype(char *res, t_flagsntype flntp, int i)
{
	if (flntp.noll2 == 3 && flntp.number > flntp.sizenoll)
	{
		while (i++ < flntp.number - 1)
			res = ft_add_char(&res, '0');
	}
	else
	{
		while (i++ < flntp.number - 1)
			res = ft_add_char(&res, ' ');
	}
	return (res);
}

char	*else2(char *res, t_flagsntype *flntp, intmax_t n, int *i)
{
	int p;

	if (flntp->number > 0 && flntp->sizenoll == 0 && flntp->minus == 0
			&& flntp->oct == 0 && flntp->noll2 == 0)
	{
		if ((flntp->plus || flntp->space || n < 0) && id(*flntp))
			flntp->number--;
		while ((*i)++ < flntp->number - ft_intlength(n))
			res = ft_add_char(&res, ' ');
		res = plminsp(res, *flntp, n);
		return (res);
	}
	else if (flntp->number > 0 && flntp->noll2 == 3 && flntp->minus == 0
			&& flntp->oct == 0 && is_type(flntp->type))
	{
		p = (flntp->sizenoll > 0) ? '0' : ' ';
		while ((*i)++ < flntp->number - ft_intlength(n))
			res = ft_add_char(&res, p);
		return (res);
	}
	res = plminsp(res, *flntp, n);
	if (!is_type(flntp->type))
		res = ifnottype(res, *flntp, *i);
	return (res);
}

char	*ifsizebnum(char *res, t_flagsntype flntp, intmax_t n, int j)
{
	int i;

	i = 0;
	res = plminsp(res, flntp, n);
	while (i++ < flntp.sizenoll - j)
		res = ft_add_char(&res, '0');
	return (res);
}

char	*ft_presflags(char *res, t_flagsntype flntp, intmax_t n)
{
	int			i;
	intmax_t	j;

	i = 0;
	j = (flntp.type == 'x' || flntp.type == 'X' || flntp.type == 'o' ||
		flntp.type == 'O' || flntp.type == 'p' || n == 0) ? n : ft_intlength(n);
	if (flntp.sizenoll > flntp.number)
		res = ifsizebnum(res, flntp, n, j);
	else if (flntp.minus == 0 && n != 0 && is_type(flntp.type))
		res = elseif1(res, &flntp, n, j);
	else
	{
		res = else2(res, &flntp, n, &i);
		while (i++ < (flntp.sizenoll > j ? flntp.sizenoll : j) - j)
			res = ft_add_char(&res, '0');
		if ((flntp.sizenoll != 0 && flntp.number2 > flntp.sizenoll &&
	(flntp.sizenoll < ft_intlength(n) || n == 0)
	&& flntp.noll2 == 0 && (flntp.type == 'o' || flntp.type == 'O')))
		{
			j = 0;
			while (j++ < flntp.number - flntp.sizenoll)
				res = ft_add_char(&res, ' ');
		}
	}
	return (res);
}
