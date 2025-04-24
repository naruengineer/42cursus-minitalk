/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:56:47 by nando             #+#    #+#             */
/*   Updated: 2025/04/24 21:14:46 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include "server.h"

t_state	g_state = {0, 0, 0, 0};

static void	write_one_char_and_send_signal(void)
{
	if (g_state.char_accum == '\0')
	{
		write(1, "\n", 1);
		g_state.flag = 0;
		if (g_state.client_pid != 0)
			kill(g_state.client_pid, SIGUSR1);
	}
	else
	{
		write(1, (void *)&g_state.char_accum, 1);
		kill(g_state.client_pid, SIGUSR2);
	}
	g_state.bit_count = 0;
	g_state.char_accum = 0;
	g_state.client_pid = 0;
}

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	g_state.client_pid = info->si_pid;
	if (g_state.flag == 0)
	{
		ft_printf("client PID : %d", g_state.client_pid);
		g_state.flag = 1;
	}
	if (sig == SIGUSR1)
		g_state.char_accum = (g_state.char_accum << 1) | 1;
	else if (sig == SIGUSR2)
		g_state.char_accum = g_state.char_accum << 1;
	g_state.bit_count++;
	if (g_state.bit_count == 8)
		write_one_char_and_send_signal();
}

int	main(void)
{
	__pid_t				pid;
	struct sigaction	sig_act;

	pid = getpid();
	ft_printf("Server PID : %d\n", pid);
	sig_act.sa_sigaction = signal_handler;
	sig_act.sa_flags = SA_SIGINFO;
	sigemptyset(&sig_act.sa_mask);
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
	while (1)
		pause();
	return (0);
}
