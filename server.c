/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:31:43 by albmarqu          #+#    #+#             */
/*   Updated: 2024/08/04 22:35:05 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bin2str(int sig)
{
	static char	c;
	static int	i;
	int			bin;

	if (sig == SIGUSR1)
		bin = 0x00;
	else
		bin = 0x01;
	c = c | (bin << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, bin2str);
		signal(SIGUSR2, bin2str);
	}
	return (0);
}
