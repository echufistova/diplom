/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:24:21 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/12 13:05:49 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (str && *str)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}

size_t		ft_strlen_w(wchar_t *w_str)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	if (w_str)
	{
		while (w_str[i] != '\0')
		{
			len += char_length(w_str[i]);
			i++;
		}
	}
	return (len);
}

int			char_length(unsigned int c)
{
	if (c <= 127)
		return (1);
	else if (c <= 2047)
		return (2);
	else if (c <= 65535)
		return (3);
	else
		return (4);
}
