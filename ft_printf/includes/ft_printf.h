/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 09:05:53 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/10 18:49:18 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "../../includes/libft.h"

# define F format

typedef struct	s_printf
{
	int			ret;
	int			buff_size;
	char		*buff;
	int			is_percent_d;
	int			is_percent_s;
	int			is_percent_c;
}				t_printf;

int		ft_printf(const char *format, ...);

#endif
