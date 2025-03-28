/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:35:49 by nando             #+#    #+#             */
/*   Updated: 2025/03/11 13:51:29 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_put_char(char c);
int ft_put_str(char *str);
int	ft_put_deci(int i);
int	ft_put_int(int i);
int ft_put_per(void);
int	ft_put_unsigned(unsigned int i);
int ft_put_ptr(void *ptr);
int ft_put_hexa_lower(int n);
int ft_put_hexa_upper(int n);
size_t ft_strlen(const char *s);
int ft_printf(const char *format, ...);

#endif
