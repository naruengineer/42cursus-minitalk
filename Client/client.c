/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:06:10 by nando             #+#    #+#             */
/*   Updated: 2025/04/25 22:38:38 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

volatile sig_atomic_t	g_ack_received = 0;

static void	ack_bit_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

static void	ack_message_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
	ft_printf("Acknowledgment received message from server.\n");
}

void	send_char_in_binary_signal(__pid_t server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_ack_received = 0;
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (!g_ack_received)
			usleep(500);
		i--;
	}
}

static void	send_message(char *message, __pid_t server_pid)
{
	unsigned char	c;
	int				i;

	i = 0;
	while (message[i] != '\0')
	{
		c = message[i];
		send_char_in_binary_signal(server_pid, c);
		i++;
	}
}

int	main(int argc, char **argv)
{
	__pid_t	server_pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("invalid number of argument\n");
		ft_printf("Usage: ./client <server_pid> <message>");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR2, ack_bit_handler);
	signal(SIGUSR1, ack_message_handler);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	send_message(message, server_pid);
	send_null_signal(server_pid);
	while (!g_ack_received)
		usleep(500);
	return (0);
}
