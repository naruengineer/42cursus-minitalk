/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:25:14 by nando             #+#    #+#             */
/*   Updated: 2025/03/28 18:17:05 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

typedef struct s_state 
{
	volatile sig_atomic_t bit_count;
	volatile sig_atomic_t char_accum;
	volatile sig_atomic_t client_pid;
	int flag;
} t_state;

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"

#endif