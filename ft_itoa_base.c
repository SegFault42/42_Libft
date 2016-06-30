/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 19:55:50 by rabougue          #+#    #+#             */
/*   Updated: 2016/06/30 19:56:03 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_itoa_base(unsigned long long n, char *base)
{
	char				*str;
	unsigned long long	i;
	char				*j;
	char				*k;

	i = ft_strlen(base);
	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n >= i)
	{
		j = ft_itoa_base(n / i, base);
		k = ft_itoa_base(n % i, base);
		str = ft_strjoin(j, k);
		free(j);
		free(k);
	}
	else if (n < i)
	{
		str[0] = base[n];
		str[1] = '\0';
	}
	return (str);
}
