/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:06:10 by nando             #+#    #+#             */
/*   Updated: 2025/04/24 20:32:17 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

volatile sig_atomic_t	g_ack_received = 0;

static void	ack_char_handler(int sig)
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

static void	send_message(char *message, __pid_t server_pid)
{
	unsigned char	c;
	int				i;

	i = 0;
	while (message[i] != '\0')
	{
		c = message[i];
		send_char_in_binary_signal(server_pid, c);
		while (!g_ack_received)
			usleep(700);
		g_ack_received = 0;
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
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR2, ack_char_handler);
	signal(SIGUSR1, ack_message_handler);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	send_message(message, server_pid);
	send_null_signal(server_pid);
	while (!g_ack_received)
		usleep(700);
	return (0);
}
