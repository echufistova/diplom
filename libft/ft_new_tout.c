/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_tout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:12:53 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/05 18:39:29 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				checkflags(char c)
{
	if (c == '#' || c == '0' || c == '-' ||
		c == '+' || c == ' ' || c == '.' || c == '*' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

t_flagsntype	ft_new_flntp(void)
{
	t_flagsntype flagstype;

	flagstype.oct = 0;
	flagstype.noll = 0;
	flagstype.noll2 = 0;
	flagstype.sizenoll = 0;
	flagstype.minus = 0;
	flagstype.plus = 0;
	flagstype.space = 0;
	flagstype.dot = 0;
	flagstype.number = 0;
	flagstype.number2 = 0;
	flagstype.hljz.hh = 0;
	flagstype.hljz.h = 0;
	flagstype.hljz.ll = 0;
	flagstype.hljz.l = 0;
	flagstype.hljz.j = 0;
	flagstype.hljz.z = 0;
	flagstype.zirka1 = 0;
	flagstype.zirka2 = 0;
	flagstype.type = '0';
	return (flagstype);
}

t_flagsntype	ft_hljz(t_flagsntype fltp, const char *fl_tp, unsigned int *i)
{
	if (fl_tp[*i] == 'l' && fl_tp[*i + 1] != 'l')
		fltp.hljz.l = 1;
	else if (fl_tp[*i] == 'l' && fl_tp[*i + 1] == 'l')
	{
		fltp.hljz.ll = 1;
		(*i)++;
	}
	else if (fl_tp[*i] == 'h' && fl_tp[*i + 1] != 'h')
		fltp.hljz.h = 1;
	else if (fl_tp[*i] == 'h' && fl_tp[*i + 1] == 'h')
	{
		fltp.hljz.hh = 1;
		(*i)++;
	}
	else if (fl_tp[*i] == 'j')
		fltp.hljz.j = 1;
	else if (fl_tp[*i] == 'z')
		fltp.hljz.z = 1;
	if (fl_tp[*i] == 'h' || fl_tp[*i] == 'l' || fl_tp[*i] == 'j' ||
			fl_tp[*i] == 'z')
		(*i)++;
	fltp.type = fl_tp[(*i)++];
	return (fltp);
}

void			flntp_number(const char *fl_tp, t_flagsntype *fltp,
		unsigned int *i, char **n)
{
	int		j;
	char	*res;

	j = 0;
	if ((fl_tp[*i] >= '0' && fl_tp[*i] <= '9') || fl_tp[*i] == '.')
	{
		while (fl_tp[*i] != '\0' && fl_tp[*i] >= '0' && fl_tp[*i] <= '9')
			*n = ft_add_char(n, fl_tp[(*i)++]);
		if (fl_tp[*i] == '.')
		{
			flntpnoll(fltp);
			j = ++(*i);
			if (fl_tp[(*i)] == '*')
			{
				fltp->zirka2 = 1;
				(*i)++;
			}
			while (fl_tp[*i] >= 48 && fl_tp[*i] <= 57)
				(*i)++;
			res = ft_strsub(fl_tp, j, *i - j);
			fltp->sizenoll = ft_atoi(res);
			ft_strdel(&res);
		}
		(*i)--;
	}
}

t_flagsntype	ft_get_flntp(const char *fl_tp, unsigned int *i,
		const char *format)
{
	t_flagsntype	flagstype;
	char			*n;

	flagstype = ft_new_flntp();
	n = (char*)ft_memalloc(sizeof(char));
	while (format[*i] != '\0' && checkflags(fl_tp[*i]))
	{
		if (fl_tp[*i] == '#')
			flagstype.oct = 1;
		else if (fl_tp[*i] == '0')
			flagstype.noll = 1;
		else if (fl_tp[*i] == '-')
			flagstype.minus = 1;
		else if (fl_tp[*i] == '+')
			flagstype.plus = 1;
		else if (fl_tp[*i] == ' ')
			flagstype.space = 1;
		else if (fl_tp[*i] == '*')
			flagstype.zirka1 = 1;
		else
			flntp_number(fl_tp, &flagstype, i, &n);
		(*i)++;
	}
	flntp_numbers(&flagstype, &n);
	return (ft_hljz(flagstype, fl_tp, i));
}
