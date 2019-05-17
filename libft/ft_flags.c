/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:58:48 by ychufist          #+#    #+#             */
/*   Updated: 2018/09/27 17:05:25 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*if1fl(char **res, t_flagsntype *flntp, intmax_t n, int j)
{
	int		i;

	i = 0;
	if (flntp->noll == 1 && flntp->minus == 0)
	{
		*res = plminsp(*res, *flntp, n);
		if (flntp->space == 1 && flntp->plus == 0 && id(*flntp))
			flntp->number--;
		if (flntp->number > 0)
		{
			while (i++ < flntp->number - j)
				*res = ft_add_char(res, '0');
		}
	}
	else if (flntp->noll == 0 && flntp->minus == 0)
	{
		if ((flntp->plus || flntp->space) && id(*flntp) && !flntp->minus
				&& !flntp->oct && !flntp->noll)
			flntp->number--;
		while (i++ < flntp->number - (n == 0 ? 1 : j))
			*res = ft_add_char(res, ' ');
		*res = plminsp(*res, *flntp, n);
	}
	return (*res);
}

char	*flag_space(char *res, t_flagsntype flntp, intmax_t n)
{
	int			j;
	uintmax_t	nb;

	nb = (uintmax_t)(n < 0 ? -n : n);
	j = ((flntp.type == 'x' || flntp.type == 'X' || flntp.type == 'o' ||
			flntp.type == 'O' || flntp.type == 'p') ? n : ft_intlength(nb));
	if (n < 0 || (flntp.plus == 1 && id(flntp)))
		flntp.number--;
	if (flntp.oct == 1)
		return (ft_octflag(res, flntp, n));
	if (flntp.dot == 1)
		return (ft_presflags(res, flntp, n));
	if (flntp.minus == 0)
		res = if1fl(&res, &flntp, n, j);
	else
	{
		if (flntp.plus == 1 && n >= 0 && id(flntp))
			res = ft_add_char(&res, '+');
		else if (flntp.space == 1 && flntp.plus == 0 && flntp.noll == 0
	&& n >= 0 && id(flntp))
			res = ft_add_char(&res, ' ');
	}
	return (res);
}

char	*unsflag_space(char *res, t_flagsntype flntp, uintmax_t n)
{
	int		i;
	int		j;

	i = 0;
	j = ((flntp.type == 'x' || flntp.type == 'X' || flntp.type == 'o'
			|| flntp.type == 'O') ? n : ft_intlength(n));
	if (flntp.plus == 1 && id(flntp))
		flntp.number--;
	if (flntp.oct == 1)
		return (ft_octflag(res, flntp, n));
	if (flntp.dot == 1)
		return (ft_presflags(res, flntp, n));
	if (flntp.noll == 1 && flntp.minus == 0)
	{
		while (i++ < flntp.number - j)
			res = ft_add_char(&res, '0');
	}
	else if (flntp.noll == 0 && flntp.number != 0 && flntp.minus == 0)
	{
		while (i++ < flntp.number - ((n == 0) ? 1 : j))
			res = ft_add_char(&res, ' ');
	}
	return (res);
}
