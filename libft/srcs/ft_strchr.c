/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:56:05 by nando             #+#    #+#             */
/*   Updated: 2025/03/11 15:05:44 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char    *ft_strchr(const char *s, int c)
{
	int i;
	i = 0;
	while(s[i] != '\0'){
		if(s[i] == c)
			return (char *)&s[i];
	i++;
	}
	if(c == '\0')
		return (char *)&s[i];
	return NULL;
}
