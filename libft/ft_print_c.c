/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:40:40 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/10 19:19:22 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnull(char *res, t_flagsntype flntp, unsigned int c, wchar_t w)
{
	if (flntp.minus == 0)
		ft_putstr(res);
	if (flntp.type == 'c' && flntp.hljz.l == 0)
		ft_putchar(c);
	else if (flntp.type == 'C' || flntp.hljz.l == 1)
		ft_putchar_w(w);
}

char	*elseif(char *res, t_flagsntype flntp, int *len, t_char l)
{
	int		i;

	i = 0;
	if (flntp.minus == 1)
	{
		if (flntp.type == 'c')
			res = ft_add_char(&res, (char)l.c);
		else
		{
			ft_putstr(res);
			(*len) += ft_strlen(res);
			ft_bzero(res, ft_strlen(res));
			ft_printnull(res, flntp, l.c, l.w);
			(*len) += char_length(l.w);
		}
		while (++i < flntp.number)
			res = ft_add_char(&res, ' ');
		ft_putstr(res);
	}
	else
	{
		while (i++ < flntp.number - 1)
			res = ft_add_char(&res, l.p);
	}
	return (res);
}

char	*ft_print_c(va_list ap, t_flagsntype flntp, char *res, int *len)
{
	t_char	l;

	l.c = 0;
	l.w = 0;
	if (flntp.type == 'c' && flntp.hljz.l == 0)
		l.c = (unsigned int)(va_arg(ap, int));
	else if (flntp.type == 'C' || flntp.hljz.l == 1)
		l.w = va_arg(ap, wchar_t);
	if (flntp.noll == 1 || flntp.number != 0 || flntp.minus)
	{
		if (flntp.noll2 == 3 || flntp.noll == 1)
			l.p = '0';
		else if (flntp.noll == 0)
			l.p = ' ';
		res = elseif(res, flntp, len, l);
	}
	if (!flntp.minus)
		ft_printnull(res, flntp, l.c, l.w);
	if (flntp.minus == 0)
		*len = (flntp.type == 'c' && flntp.hljz.l == 0)
	? (*len) + 1 : (*len) + char_length(l.w);
	return (res);
}

void	nachalo(const char *format, t_printf *t)
{
	t->j = t->i;
	while (format[t->i] != '\0' && format[t->i] != '%')
		t->i++;
}

int		konec(char **res, int len)
{
	len = (int)(ft_strlen(*res) + len);
	ft_putstr(*res);
	ft_strdel(res);
	return (len);
}
