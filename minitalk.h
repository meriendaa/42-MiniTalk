/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:18:00 by tmerida-          #+#    #+#             */
/*   Updated: 2022/03/21 18:18:02 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINITALK_H
# define MINITALK_H
# define PIDERROR "Numero pid no valido"
# define ARGERROR "Numero de argumentos erroneo"

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
#include <limits.h>

char			*ft_itoa(int n);
void ft_putstr (char *str);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int ft_strlen (const char *str);
char	*ft_strjoin(char *s1, char const s2);
char	*ft_strdup(const char *s1);
#endif