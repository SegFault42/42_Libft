/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:44:19 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/11 03:20:53 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_struct(t_printf *print)
{
	print->buff = NULL;
	print->buff_size = 0;
	print->ret = 0;
	print->is_percent_c = 0;
	print->is_percent_s = 0;
	print->is_percent_d = 0;
}

void	write_format(const char *format, t_printf *print)
{
	ft_putchar(*format);
	++print->ret;
}

void	percent_d(t_printf *print, va_list pa, char *buff, int i)
{
	int		d;
	char	*str;

	d = va_arg(pa, int);
	str = ft_itoa(d);
	if (print->is_percent_d == 1)
	{
		
	}
	else
		print->buff_size += ft_strlen(str);
	free(str);
}

void	percent_c(t_printf *print, va_list pa, char *buff, int i)
{
	char	c;

	c = va_arg(pa, int);
	if (print->is_percent_c == 1)
	{
		if (print->is_percent_d == 1)
		{
			buff[i] = c;
			++i;
		}
		else
			++print->buff_size;
	}
}

void	percent_s(t_printf *print, va_list pa)
{
	char	*s;

	s = va_arg(pa, char *);
	if (s)
	{
		if (print->is_percent_s == 1)
		{
			ft_putstr(s);
			print->buff_size += ft_strlen(s);
		}
	}
	else
	{
		if (print->is_percent_s == 1)
			ft_putstr("(null)");
		else
			print->buff_size += 6;
	}
}

void	count_buff_size(t_printf *print, const char *format, va_list pa, int i)
{
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			while (*format == ' ')
				++format;
			if (*format == 'c')
				percent_c(print, pa, NULL, i);
			else if (*format == 'd')
				percent_d(print, pa, NULL, i);
			else if (*format == 's')
				percent_s(print, pa);
			else
				++print->buff_size;
		}
		else
		{
			/*ft_putchar(*format);*/
			++print->buff_size;
		}
		++format;
	}
}

void	write_string(t_printf *print, const char *format, va_list pa, int i)
{
	char	*buff;

	buff = (char *)malloc(sizeof(char) * print->buff_size + 1);
	print->is_percent_s = 1;
	print->is_percent_d = 1;
	print->is_percent_c = 1;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			while (*format == ' ')
				++format;
			if (*format == 'c')
				percent_c(print, pa, buff, i);
			else if (*format == 'd')
				percent_d(print, pa, buff, i);
			else if (*format == 's')
				percent_s(print, pa);
		}
		else
		{
			buff[i] = *format;
			++i;
		}
		++format;
	}
}

int		ft_printf(const char *format, ...)
{
	t_printf	print;
	va_list		pa;
	int			i;

	i = 0;
	va_start(pa, format);
	init_struct(&print);
	count_buff_size(&print, format, pa, i);
	va_end(pa);
	va_start(pa, format);
	write_string(&print, format, pa, i);
	va_end(pa);
	return (print.buff_size);
}
