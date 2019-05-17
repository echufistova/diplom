/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:19:36 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/05 18:44:47 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*elseoctif(char **res, t_flagsntype *flntp, int i, int j)
{
	if (flntp->sizenoll > flntp->number)
	{
		while (i++ < (flntp->sizenoll > flntp->number ? flntp->sizenoll :
			flntp->number) - j)
			*res = ft_add_char(res, '0');
	}
	else if (flntp->number != 0 && flntp->noll == 1 && flntp->minus == 0 &&
		flntp->dot == 0)
	{
		flntp->number = (flntp->noll == 1) ? flntp->number + 1 : flntp->number;
		while (i++ < flntp->number)
			*res = ft_add_char(res, '0');
	}
	return (*res);
}

char	*elseifif(char *res, t_flagsntype flntp, intmax_t n, int j)
{
	char *res1;

	if (flntp.dot == 1 && flntp.sizenoll != 0)
	{
		res1 = ft_presflags(res, flntp, 1);
		res = ft_add_char(&res1, '0');
		if (flntp.sizenoll != 0 && flntp.number2 > flntp.sizenoll &&
	(flntp.sizenoll < ft_intlength(n) || n == 0) && flntp.noll2 == 0)
		{
			while (j++ < flntp.number2 - (flntp.sizenoll > ft_intlength(n) ?
						flntp.sizenoll : ft_intlength(n)))
				res1 = ft_add_char(&res, ' ');
			return (res1);
		}
		return (res);
	}
	return (res);
}

char	*elseoct(char *res, t_flagsntype *flntp, intmax_t n, int j)
{
	int		i;

	i = 0;
	flntp->number--;
	if (flntp->number > flntp->sizenoll && flntp->noll == 0 &&
			flntp->minus == 0)
	{
		while (i++ < flntp->number)
			res = ft_add_char(&res, ' ');
	}
	if (flntp->plus == 1 && n >= 0 && id(*flntp))
		res = ft_add_char(&res, '+');
	else if (flntp->space == 1 && id(*flntp))
	{
		res = ft_add_char(&res, ' ');
		flntp->number--;
	}
	if ((flntp->sizenoll > flntp->number) || (flntp->number != 0 &&
		flntp->noll == 1 && flntp->minus == 0 && flntp->dot == 0))
		res = elseoctif(&res, flntp, i, j);
	else
		res = elseifif(res, *flntp, n, j);
	return (res);
}

char	*ft_octflag(char *res, t_flagsntype flntp, intmax_t n)
{
	uintmax_t	nb;
	int			i;
	intmax_t	j;

	i = 0;
	nb = (uintmax_t)(n < 0 ? -n : n);
	j = ((flntp.type == 'x' || flntp.type == 'X' || flntp.type == 'o' ||
			flntp.type == 'O' || flntp.type == 'p') ? n : ft_intlength(nb));
	if (flntp.oct == 1 && n != 0)
	{
		if ((flntp.noll == 0 && flntp.sizenoll == 0 && flntp.minus == 0
	&& flntp.noll2 == 0) || ((flntp.sizenoll > flntp.number || flntp.noll == 1)
					&& flntp.minus == 0))
			res = ifoct1(&res, flntp, n, j);
		else if (flntp.sizenoll < flntp.number && flntp.minus == 0)
			res = ifoct2(&res, flntp, n, j);
		else
			res = ifoct3(&res, flntp, n, j);
	}
	else
		return (elseoct(res, &flntp, n, j));
	return (res);
}
