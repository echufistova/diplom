/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dopfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 21:35:19 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/10 17:44:14 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flntpnoll(t_flagsntype *flntp)
{
	flntp->dot = 1;
	flntp->noll2 = (flntp->noll == 1) ? 3 : 0;
	flntp->noll = 0;
}

void	flntp_numbers(t_flagsntype *flagstype, char **n)
{
	flagstype->number = ft_atoi(*n);
	flagstype->number2 = flagstype->number;
	ft_strdel(n);
}

char	*plminsp(char *res, t_flagsntype flntp, intmax_t n)
{
	if (n < 0 && id(flntp))
		res = ft_add_char(&res, '-');
	else if (flntp.plus == 1 && n >= 0 && id(flntp))
		res = ft_add_char(&res, '+');
	else if (flntp.space == 1 && id(flntp))
		res = ft_add_char(&res, ' ');
	return (res);
}

char	*dotsizenoll(char *res, t_flagsntype flntp, intmax_t n)
{
	char	*res1;
	int		j;

	j = 0;
	res1 = ft_presflags(res, flntp, 1);
	res = ft_add_char(&res1, '0');
	if (flntp.plus == 1 && flntp.number2 == flntp.number)
		flntp.number--;
	if ((flntp.number2 > flntp.sizenoll || flntp.number2 > ft_intlength(n))
			&& flntp.noll2 == 0 && flntp.space == 0)
	{
		res1 = res;
		while (j++ < flntp.number - (flntp.sizenoll > ft_intlength(n) ?
					flntp.sizenoll : ft_intlength(n)))
		{
			res = res1;
			res1 = ft_add_char(&res, ' ');
		}
		return (res1);
	}
	return (res);
}

char	*insertoct(char *res, t_flagsntype flntp, intmax_t n)
{
	if (n != 0 && (flntp.type == 'x' || flntp.type == 'p'))
	{
		res = ft_add_char(&res, '0');
		res = ft_add_char(&res, 'x');
	}
	else if (flntp.type == 'X' && n != 0)
	{
		res = ft_add_char(&res, '0');
		res = ft_add_char(&res, 'X');
	}
	else if ((flntp.type == 'o' || flntp.type == 'O') && n != 0)
		res = ft_add_char(&res, '0');
	return (res);
}
