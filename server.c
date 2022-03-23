/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:58:44 by tmerida-          #+#    #+#             */
/*   Updated: 2022/03/21 17:58:46 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void binario_decimal(char *bits)
{
	int	base;
	unsigned char num;
	int	i;
	num = 0;
	i = 0;
	base = 128;
	while (bits[i])
	{
		num += base * (bits[i] - '0');
		base /= 2;
		i++;
	}
	write(1, &num, 1);
}

void ft_signal(int signal)
{
	static int contador;
	static char *bits;

	contador++;
	if (bits == NULL)
	{
		bits = ft_strdup("");
		contador = 1;
	}

	if (signal == SIGUSR1)
		bits = ft_strjoin(bits, '0');
	else
		bits = ft_strjoin(bits, '1');
	if (contador == 8)
	{
		binario_decimal(bits);
		free(bits);
		bits = NULL;
	}
}

int main ()
{
	int pid;
	char *pid_str;

	pid = 0;
	pid = getpid();
	ft_putstr("PID: ");
	pid_str = ft_itoa(pid);
	ft_putstr(pid_str);
	write(1, "\n", 1);

	while (1)
	{
		signal(SIGUSR1, ft_signal);
		signal(SIGUSR2, ft_signal);
		pause();
	}
	return (0);
}

