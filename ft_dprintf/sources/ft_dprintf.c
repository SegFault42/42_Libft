/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:44:19 by rabougue          #+#    #+#             */
/*   Updated: 2017/02/23 21:59:20 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

void	count_buff_size(t_printf *print, const char *format, va_list pa)
{
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			while (*format == ' ')
				++format;
			if (*format == 'c')
				percent_c(print, pa);
			else if (*format == 'd' || *format == 'i')
				percent_d(print, pa);
			else if (*format == 's')
				percent_s(print, pa);
			else if (*format == 'p')
				percent_p(print, pa);
			else
				++print->buff_size;
		}
		else
			++print->buff_size;
		++format;
	}
}

void	specifier(const char *format, va_list pa, t_printf *print)
{
	if (*format == 'c')
		percent_c(print, pa);
	else if (*format == 'd' || *format == 'i')
		percent_d(print, pa);
	else if (*format == 's')
		percent_s(print, pa);
	else if (*format == 'p')
		percent_p(print, pa);
	else
	{
		print->buff[print->i] = *format;
		++print->i;
	}
}

void	write_string(t_printf *print, const char *format, va_list pa, int *fd)
{
	if ((print->buff = ft_memalloc(print->buff_size + 1)) == NULL)
		error(MALLOC_ERROR);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			while (*format == ' ')
				++format;
			if (*format == '%')
			{
				ft_strcat(print->buff, "%");
				print->i++;
			}
			else
				specifier(format, pa, print);
		}
		else
		{
			print->buff[print->i] = *format;
			++print->i;
		}
		++format;
	}
	print_buff(print, fd);
}


int		ft_printf(/*int fd, */const char *format, ...)
{
	t_printf	print;
	va_list		pa;

	if (*format == '%' && ft_strlen(format) == 1)
		return (0);
	int	fd = 1;
	ft_memset(&print, 0, sizeof(print));
	va_start(pa, format);
	count_buff_size(&print, format, pa);
	va_end(pa);
	print.is_percent_s = 1;
	print.is_percent_d = 1;
	print.is_percent_c = 1;
	print.is_percent_p = 1;
	va_start(pa, format);
	write_string(&print, format, pa, &fd);
	va_end(pa);
	return (ft_strlen(print.buff)); //variable used after free
}
