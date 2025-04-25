/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_signal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:04:10 by nando             #+#    #+#             */
/*   Updated: 2025/04/25 21:40:22 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEND_SIGNAL_H
# define SEND_SIGNAL_H

# include <signal.h>
# include <unistd.h>

void	send_null_signal(__pid_t server_pid);

#endif