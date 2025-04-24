/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:25:14 by nando             #+#    #+#             */
/*   Updated: 2025/04/24 14:02:27 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_state
{
	volatile sig_atomic_t	bit_count;
	volatile sig_atomic_t	char_accum;
	volatile sig_atomic_t	client_pid;
	int						flag;
}							t_state;

#endif