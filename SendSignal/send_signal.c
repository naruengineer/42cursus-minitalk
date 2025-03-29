/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:05:15 by nando             #+#    #+#             */
/*   Updated: 2025/03/29 19:18:51 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

void send_char_in_binary_signal(__pid_t server_pid, char c)
{
	int i;

	i = 7;
	while(i >= 0)
	{
		if((c >> i) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

void send_null_signal(__pid_t server_pid)
{
	int i;
	
	i = 7;
	while(i >= 0)
	{
		kill(server_pid, SIGUSR2);
		usleep(500);
		i--;
	}
}
