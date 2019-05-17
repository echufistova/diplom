/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dopfile1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:32:15 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/10 17:50:18 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		xu(char c)
{
	if (c == 'x' || c == 'X' || c == 'U' || c == 'u' || c == 'd' || c == 'D'
		|| c == 'i')
		return (1);
	return (0);
}

char	*ifoct3(char **res, t_flagsntype flntp, intmax_t n, int j)
{
	int		i;

	i = 0;
	*res = plminsp(*res, flntp, n);
	if ((flntp.plus == 1 || flntp.space == 1 || n < 0) && id(flntp))
		flntp.number--;
	*res = insertoct(*res, flntp, n);
	if ((flntp.number >= flntp.sizenoll && flntp.sizenoll != 0) ||
			(flntp.sizenoll >= flntp.number))
	{
		while (i++ < flntp.sizenoll - j)
			*res = ft_add_char(res, '0');
	}
	return (*res);
}

char	*ifoct2(char **res, t_flagsntype flntp, intmax_t n, int j)
{
	int		i;
	int		g;

	i = 0;
	if (is_type(flntp.type))
	{
		g = (flntp.sizenoll > j) ? flntp.sizenoll : j;
		while (i++ < flntp.number - g)
			*res = ft_add_char(res, ' ');
		flntp.space = (flntp.number < g && flntp.space == 1) ? 1 : 0;
	}
	if (n < 0 && id(flntp))
		*res = ft_add_char(res, '-');
	else if (flntp.plus == 1 && n >= 0 && id(flntp))
		*res = ft_add_char(res, '+');
	else if (flntp.space == 1 && id(flntp))
	{
		*res = ft_add_char(res, ' ');
		flntp.number--;
	}
	*res = insertoct(*res, flntp, n);
	while (i++ < flntp.number - j + (xu(flntp.type) ? 1 : 0))
		*res = ft_add_char(res, '0');
	return (*res);
}

char	*ifoct1(char **res, t_flagsntype flntp, intmax_t n, int j)
{
	int		i;

	i = 0;
	if ((flntp.noll == 1 || flntp.sizenoll > flntp.number) &&
				flntp.minus == 0)
	{
		*res = plminsp(*res, flntp, n);
		*res = insertoct(*res, flntp, n);
		while (i++ < (flntp.sizenoll > flntp.number ? flntp.sizenoll
					: flntp.number) - j)
			*res = ft_add_char(res, '0');
	}
	else if (flntp.noll == 0 && flntp.sizenoll == 0 && flntp.minus == 0
				&& flntp.noll2 == 0)
	{
		while (i++ < flntp.number - j)
			*res = ft_add_char(res, ' ');
		if (n < 0 && id(flntp))
			*res = ft_add_char(res, '-');
		else if (flntp.plus == 1 && id(flntp))
			*res = ft_add_char(res, '+');
		*res = insertoct(*res, flntp, n);
	}
	return (*res);
}
