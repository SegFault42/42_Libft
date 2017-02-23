/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 09:05:53 by rabougue          #+#    #+#             */
/*   Updated: 2017/02/23 18:19:34 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <stdarg.h>
# include "../../includes/libft.h"
#include <stdio.h>

# define MALLOC_ERROR 1

typedef struct	s_printf
{
	int			ret;
	int			buff_size;
	char		*buff;
	uint8_t		is_percent_d;
	uint8_t		is_percent_s;
	uint8_t		is_percent_c;
	uint8_t		is_percent_p;
	int			i;
}				t_printf;

int				ft_dprintf(/*int fd, */const char *format, ...);
void			percent_d(t_printf *print, va_list pa);
void			percent_s(t_printf *print, va_list pa);
void			percent_c(t_printf *print, va_list pa);
void			percent_l(t_printf *print, va_list pa);
void			percent_p(t_printf *print, va_list pa);
/*
** tools.c
*/
void			print_buff(t_printf *print, int *fd);
void			error(int error);

#endif
