/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:06:10 by nando             #+#    #+#             */
/*   Updated: 2025/03/28 18:13:56 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "client.h"

volatile sig_atomic_t g_ack_received;

void ack_handler(int sig)
{
	(void)sig;
	
	g_ack_received = 1;
	ft_printf("Acknowledgment received from server.\n");
}

int main(int argc, char **argv)
{
	__pid_t server_pid;
	char *message;
	int i;
	int j;
	unsigned char c;
	
	if(argc != 3)
	{
		ft_printf("invalid number of argument\n");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, ack_handler);
	server_pid = ft_atoi(argv[1]);
	ft_printf("client PID : %d\n", getpid());
	ft_printf("messeage --> [%s]\n", argv[2]);
	message = argv[2];
	i = 0;
	while(message[i] != '\0')
	{
		j = 7;
		c = message[i];
		while(j >= 0)
		{
			if((c >> j) & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(100);
			j--;
		}
		i++;
	}
	j = 7;
	while(j >= 0)
	{
		kill(server_pid, SIGUSR2);
		usleep(100);
		j--;
	}
	while(!g_ack_received)
		usleep(100);
	return(0);
}
