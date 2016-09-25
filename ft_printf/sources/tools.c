#include "../includes/ft_printf.h"

void	init_struct(t_printf *print)
{
	print->buff = NULL;
	print->buff_size = 0;
	print->ret = 0;
	print->is_percent_c = 0;
	print->is_percent_s = 0;
	print->is_percent_d = 0;
	print->i = 0;
}

void	print_buff(t_printf *print)
{
	print->buff[print->i] = '\0';
	ft_putstr(print->buff);
	free(print->buff);
}

