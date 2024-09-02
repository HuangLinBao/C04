/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsabri <tsabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:40:52 by HuangLinBao       #+#    #+#             */
/*   Updated: 2024/09/02 10:02:37 by tsabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_erreur(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i])
	{
		j = i;
		while (base[j] != '\0')
		{
			j++;
			if (base[i] == base[j])
				return (1);
		}
		if (base[i] == '+' || base[i] == '-' || base[i] == '%'
			|| base[i] == '/' || base[i] == '*' || base[i] == '='
			|| base[i] == ',' || base[i] == '.'
			|| base[i] < 33 || base[i] > 126)
			return (1);
		else
			i++;
	}
	return (0);
}

int	ft_value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_is_valid(char c, int base)
{
	char	*d1;
	char	*d2;

	d1 = "0123456789abcdef";
	d2 = "0123456789ABCDEF";
	while (base--)
	{
		if (d1[base] == c || d2[base] == c)
			return (1);
	}
	return (0);
}

int	ft_get_base(char *base)
{
	int		base_count;

	base_count = 1;
	while (*base)
	{
		base_count++;
		base++;
	}
	return (base_count);
}

int	ft_atoi_base(char *str, char *base)
{
	int		lbase;
	int		sign;
	int		res;

	sign = 1;
	res = 0;
	if (ft_erreur(base))
		return (0);
	lbase = ft_get_base(base);
	while (*str <= ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (ft_is_valid(*str, lbase))
	{
		res = res * lbase + ft_value_of(*str);
		str++;
	}
	return (res * sign);
}
