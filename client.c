/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:58:28 by tmerida-          #+#    #+#             */
/*   Updated: 2022/03/22 16:58:30 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_enviar(int pid, char c)
{
	int i;
	int bit;
	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		--i;
		usleep(150);
	}
}

void message_char(int pid, char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		ft_enviar(pid, str[i]);
		i++;
	}
}

int main (int argc, char **argv){
	int pid;
	if (argc < 3)
		ft_putstr(PIDERROR);
	if (argc > 3)
		ft_putstr(ARGERROR);
	pid = ft_atoi(argv[1]);
	message_char(pid, argv[2]);
	return (0);

}