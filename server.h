/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:25:14 by nando             #+#    #+#             */
/*   Updated: 2025/03/28 17:37:58 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

typedef struct s_state 
{
	volatile sig_atomic_t bit_count;
	volatile sig_atomic_t char_accum;
	volatile sig_atomic_t client_pid;
} t_state;

#endif