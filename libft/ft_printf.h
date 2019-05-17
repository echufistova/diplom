/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:59:21 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/10 19:15:58 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdarg.h>
# include <stdint.h>
# include <locale.h>
# include <wchar.h>

typedef struct		s_hljz
{
	int				hh;
	int				h;
	int				ll;
	int				l;
	int				j;
	int				z;
}					t_hljz;

typedef struct		s_flagsntype
{
	int				oct;
	int				noll;
	int				noll2;
	int				sizenoll;
	int				minus;
	int				plus;
	int				space;
	int				dot;
	int				number;
	int				number2;
	int				zirka1;
	int				zirka2;
	char			type;
	t_hljz			hljz;
}					t_flagsntype;

t_flagsntype		ft_new_flntp();
t_flagsntype		ft_get_flntp(const char *fl_tp, unsigned int *i,
		const char *format);
char				*what_to_print(char *res, t_flagsntype flntp, va_list ap,
		int *len);
char				*no_params(char *res, t_flagsntype flntp, unsigned int *i);
char				*ft_add_char(char **str, char c);
char				*ft_itoa_unsigned(uintmax_t n);
char				*ft_itoa_signed(intmax_t n);
int					is_type(char c);
int					id(t_flagsntype flntp);
int					checkflags(char c);
char				*plminsp(char *res, t_flagsntype flntp, intmax_t n);
char				*ft_itoa_base(intmax_t value, int base, t_flagsntype flntp);
char				*ft_itoa_base_uns(uintmax_t value, int base,
		t_flagsntype flntp);
char				*ft_print_int(va_list ap, t_flagsntype flntp, char *res);
char				*ft_print_u(va_list ap, t_flagsntype flntp, char *res);
char				*ft_print_o(va_list ap, t_flagsntype flntp, char *res);
char				*ft_print_x(va_list ap, t_flagsntype flntp, char *res);
char				*ft_print_s(va_list ap, t_flagsntype flntp, char *res);
char				*ft_print_bigs(va_list ap, t_flagsntype flntp, char *res,
		int *len);
char				*ft_print_c(va_list ap, t_flagsntype flntp, char *res,
		int *len);
char				*ft_print_p(va_list ap, t_flagsntype flntp, char *res);
char				*ft_presflags(char *res, t_flagsntype flntp, intmax_t n);
char				*ft_octflag(char *res, t_flagsntype flntp, intmax_t n);
char				*ft_minusflags(char *res, t_flagsntype flntp, intmax_t n);
char				*procent(va_list ap, const char *format, unsigned int *i,
		char *res);
char				*plminsp(char *res, t_flagsntype flntp, intmax_t n);
char				*insertoct(char *res, t_flagsntype flntp, intmax_t n);
char				*flag_space(char *res, t_flagsntype flntp, intmax_t n);
char				*unsflag_space(char *res, t_flagsntype flntp, uintmax_t n);
void				flntp_numbers(t_flagsntype *flagstype, char **n);
void				flntpnoll(t_flagsntype *flntp);
char				*plminsp(char *res, t_flagsntype flntp, intmax_t n);
char				*dotsizenoll(char *res, t_flagsntype flntp, intmax_t n);
char				*insertoct(char *res, t_flagsntype flntp, intmax_t n);
char				*ifoct3(char **res, t_flagsntype flntp, intmax_t n, int j);
char				*ifoct2(char **res, t_flagsntype flntp, intmax_t n, int j);
char				*ifoct1(char **res, t_flagsntype flntp, intmax_t n, int j);
typedef struct		s_char
{
	unsigned int	c;
	wchar_t			w;
	char			p;
}					t_char;
typedef struct		s_printf
{
	unsigned int	i;
	unsigned int	j;
	t_flagsntype	flntp;
	char			*res;
	char			*res1;
	int				len;
	va_list			ap;
}					t_printf;
int					konec(char **res, int len);
void				nachalo(const char *format, t_printf *t);
int					ft_printf(const char *format, ...);

#endif
