/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:16:53 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/04 09:14:13 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_putstr(char const *s)
{
	int		i;
	char	buff[ft_strlen(s) + 1];

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			buff[i] = s[i];
			i++;
		}
		buff[i] = '\0';
	}
	write(1, &buff, i);;
}
