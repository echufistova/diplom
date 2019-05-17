/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:47:50 by ychufist          #+#    #+#             */
/*   Updated: 2018/09/27 17:53:45 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*if1o(char *res, t_flagsntype flntp, uintmax_t n)
{
	int		j;
	char	*res1;

	j = 0;
	if ((flntp.oct == 0 && flntp.dot != 0) || flntp.sizenoll != 0)
		return (flag_space(res, flntp, n));
	else
	{
		flntp.number = (flntp.minus || flntp.noll) ? flntp.number - 1 :
			flntp.number;
		if (flntp.minus == 1)
		{
			res = ft_add_char(&res, '0');
			while (j++ < flntp.number - (flntp.sizenoll > ft_intlength(n) ?
						flntp.sizenoll : ft_intlength(n)))
				res = ft_add_char(&res, ' ');
			return (flag_space(res, flntp, n));
		}
		else
		{
			res1 = flag_space(res, flntp, n);
			return (ft_add_char(&res1, '0'));
		}
	}
}

char	*if2o(char *res, t_flagsntype flntp, uintmax_t n)
{
	int		s;
	int		j;
	char	*res1;

	j = 0;
	res1 = ft_itoa_base_uns((intmax_t)n, 8, flntp);
	s = ft_strlen(res1);
	if (flntp.oct == 1)
	{
		flntp.number--;
		flntp.sizenoll = (flntp.sizenoll > 0) ? flntp.sizenoll - 1 :
			flntp.sizenoll;
	}
	res = (flntp.oct == 1) ? ft_octflag(res, flntp, s) :
		flag_space(res, flntp, s);
	res = ft_strjoin_free(&res, &res1);
	if (flntp.minus == 1)
	{
		while (j++ < flntp.number - (flntp.sizenoll > s ? flntp.sizenoll : s))
			res = ft_add_char(&res, ' ');
	}
	return (res);
}

char	*ft_print_o(va_list ap, t_flagsntype flntp, char *res)
{
	uintmax_t	n;
	int			j;

	j = 0;
	if (flntp.type == 'O' || flntp.hljz.ll != 0 || flntp.hljz.l != 0)
		n = (flntp.hljz.ll == 1 ? va_arg(ap, unsigned long long int) :
				va_arg(ap, unsigned long int));
	else if (flntp.hljz.h == 1)
		n = (unsigned short)va_arg(ap, int);
	else if (flntp.hljz.hh == 1)
		n = (unsigned char)va_arg(ap, int);
	else if (flntp.hljz.j == 1)
		n = va_arg(ap, uintmax_t);
	else if (flntp.hljz.z == 1)
		n = va_arg(ap, size_t);
	else
		n = va_arg(ap, unsigned int);
	if (n == 0)
		return (if1o(res, flntp, n));
	return (if2o(res, flntp, n));
}
