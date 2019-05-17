/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:09:40 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/10 19:10:54 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*what_to_print(char *res, t_flagsntype flntp, va_list ap, int *len)
{
	if (flntp.zirka1 == 1)
		flntp.number = va_arg(ap, int);
	if (flntp.zirka2 == 1)
		flntp.sizenoll = va_arg(ap, int);
	if (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D')
		res = ft_print_int(ap, flntp, res);
	else if (flntp.type == 'u' || flntp.type == 'U')
		res = ft_print_u(ap, flntp, res);
	else if (flntp.type == 'o' || flntp.type == 'O')
		res = ft_print_o(ap, flntp, res);
	else if (flntp.type == 'x' || flntp.type == 'X')
		res = (ft_print_x(ap, flntp, res));
	else if (flntp.type == 'c' || flntp.type == 'C')
		res = ft_print_c(ap, flntp, res, len);
	else if (flntp.type == 'p')
		res = ft_print_p(ap, flntp, res);
	else if (flntp.type == 's' && flntp.hljz.l == 0)
		res = ft_print_s(ap, flntp, res);
	else if (flntp.type == 'S' || flntp.hljz.l == 1)
		res = ft_print_bigs(ap, flntp, res, len);
	return (res);
}

char	*else1(const char *format, t_printf *t)
{
	if (format[t->i] != '\0' && format[t->i] == '%' && format[t->i - 1] == '%')
	{
		t->res1 = ft_strsub(format, t->i, 1);
		t->res = ft_strjoin_free(&t->res, &t->res1);
		t->res = procent(t->ap, format, &t->i, t->res);
	}
	return (t->res);
}

int		cs(char c)
{
	if (c == 's' || c == 'S' || c == 'c' || c == 'C')
		return (1);
	return (0);
}

int		if1printf(const char *format, t_printf *t)
{
	if (format[t->i] != '\0' && format[t->i] != '%' && format[t->i - 1] == '%')
	{
		t->flntp = ft_get_flntp(format, &t->i, format);
		if (is_type(t->flntp.type) == 3)
			return (0);
		if (!is_type(t->flntp.type))
		{
			t->res = no_params(t->res, t->flntp, &t->i);
			return (1);
		}
		t->res = what_to_print(t->res, t->flntp, t->ap, &t->len);
		t->len += (cs(t->flntp.type)) ? ft_strlen(t->res) : 0;
		if (cs(t->flntp.type))
			ft_bzero(t->res, ft_strlen(t->res));
	}
	return (2);
}

int		ft_printf(const char *restrict format, ...)
{
	t_printf	t;
	int			k;

	t.i = 0;
	t.len = 0;
	t.res = ft_strnew(1);
	va_start(t.ap, format);
	while (format[t.i] != '\0')
	{
		nachalo(format, &t);
		t.res1 = ft_strsub(format, t.j, t.i - t.j);
		t.res = ft_strjoin_free(&t.res, &t.res1);
		t.i = (format[t.i] != '\0') ? t.i + 1 : t.i;
		if (format[t.i] != '\0' && format[t.i] != '%' && format[t.i - 1] == '%')
		{
			if ((k = if1printf(format, &t)) == 0)
				return (0);
			else if (k == 1)
				continue;
		}
		t.res = else1(format, &t);
	}
	t.len = (format[t.i] == '\0') ? konec(&t.res, t.len) : 0;
	va_end(t.ap);
	return (t.len);
}
