/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bigs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:08:32 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/05 17:34:58 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		flntpminusdot(char **res, t_flagsntype flntp, wchar_t *w_str, int *len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_putstr(*res);
	*len += ft_strlen(*res);
	ft_bzero(*res, ft_strlen(*res));
	while (i < flntp.sizenoll)
		ft_putchar_w(w_str[i++]);
	*len += i;
	if (ft_strlen_w(w_str) == 0)
		flntp.sizenoll = 0;
	if (flntp.dot == 0)
	{
		ft_putstr(*res);
		ft_putstr_w(w_str);
	}
	i = 0;
	j = (flntp.dot == 1 ? flntp.sizenoll : ft_strlen_w(w_str));
	while ((i)++ < flntp.number - j)
		*res = ft_add_char(res, ' ');
	return (i);
}

char	*elselast(char *res, t_flagsntype flntp, wchar_t *w_str, int *len)
{
	if (ft_strcmp_w(w_str, "(null)") == 0)
	{
		res = ft_strjoin(res, "(null)");
		ft_putstr(res);
	}
	else
	{
		if (flntp.dot == 0 && flntp.noll == 0 && flntp.minus == 0)
		{
			ft_putstr(res);
			*len += ft_strlen(res);
			ft_bzero(res, ft_strlen(res));
			ft_putstr_w(w_str);
		}
	}
	return (res);
}

char	*nollnull(char *res, t_flagsntype flntp, wchar_t *w_str)
{
	int i;

	i = 0;
	while (i++ < (int)(flntp.number - ft_strlen_w(w_str)))
		res = ft_add_char(&res, '0');
	ft_putstr(res);
	ft_putstr_w(w_str);
	return (res);
}

char	*dotnoll(char *res, t_flagsntype flntp, wchar_t *w_str, int *len)
{
	int i;

	i = 0;
	if (ft_strlen_w(w_str) == 0)
		flntp.sizenoll = 0;
	while (i++ < flntp.number - flntp.sizenoll)
		res = ft_add_char(&res, ' ');
	i = 0;
	if (flntp.minus == 0)
	{
		ft_putstr(res);
		*len += ft_strlen(res);
		ft_bzero(res, ft_strlen(res));
		while (i < flntp.sizenoll)
			ft_putchar_w(w_str[i++]);
	}
	return (res);
}

char	*ft_print_bigs(va_list ap, t_flagsntype flntp, char *res, int *len)
{
	wchar_t		*w_str;
	int			i;
	int			j;

	i = 0;
	j = 0;
	w_str = va_arg(ap, wchar_t*);
	if (!w_str)
		w_str = L"(null)";
	if (flntp.minus == 1 && flntp.dot == 0)
		i = flntpminusdot(&res, flntp, w_str, len);
	if (flntp.noll == 1 && ft_strcmp_w(w_str, "(null)") != 0)
		res = nollnull(res, flntp, w_str);
	else if (flntp.number != 0 && flntp.dot == 0 && flntp.noll == 0)
	{
		while (i++ < (int)(flntp.number - ft_strlen_w(w_str)))
			res = ft_add_char(&res, ' ');
	}
	else if (flntp.dot == 1)
		res = dotnoll(res, flntp, w_str, len);
	res = elselast(res, flntp, w_str, len);
	*len += ft_strlen_w(w_str);
	ft_putstr(res);
	return (res);
}
