/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:16:26 by tmerida-          #+#    #+#             */
/*   Updated: 2022/03/21 18:16:27 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static size_t	ft_len(long nb)
{
	size_t	size;

	size = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		size = 1;
	}
	if (nb / 10 == 0)
		return (size + 1);
	else
		nb = nb / 10;
	return (size + ft_len(nb) + 1);
}

char			*ft_itoa(int n)
{
	char			*res;
	unsigned int	i;
	size_t			len;
	long			nb;

	nb = n;
	len = ft_len(nb);
	if (!(res = (char *)malloc(sizeof(*res) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	if (nb < 0)
	{
		nb = nb * -1;
		res[0] = '-';
	}
	if (nb == 0)
		res[len] = '0';
	i = 0;
	while (i <= len && nb > 0)
	{
		res[len - i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	return (res);
}	


void ft_putstr (char *str)
{
	int i;
	i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}


char	*ft_strjoin(char *s1, char const s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 2));
	if (!s3)
		return (NULL);
	while (s1[i] != 0)
	{
		s3[j++] = s1[i];
		i++;
	}

	s3[j++] = s2;
	
	s3[j] = 0;
	return (s3);
}