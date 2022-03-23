/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:40:17 by tmerida-          #+#    #+#             */
/*   Updated: 2022/03/22 19:40:18 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	if (c == '\v' || c == '\n' || c == '\r' || c == '\f'
		|| c == '\t' || c == ' ')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(const char *str)
{
	long long int	num;
	int				sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign *= -1;
		}
		str++;
	}
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str++ - '0');
		if (num < INT_MIN && sign == -1)
			return (0);
		if (num > INT_MAX && sign == 1)
			return (-1);
	}
	return (sign * num);
}

int ft_strlen (const char *str)
{
	int i;
	i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}
char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	dst = malloc(ft_strlen(s1) + 1);
	if (dst == 0)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

