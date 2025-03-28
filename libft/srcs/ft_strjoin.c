/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:24:00 by nando             #+#    #+#             */
/*   Updated: 2025/03/11 13:24:09 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *n_str;
	size_t i;
	size_t n_str_len;
	int j;

	i = 0;
	j = 0;
	if(!s1 || !s2)
		return 0;
	n_str_len = (ft_strlen(s1) + (ft_strlen(s2)) + 1);
	n_str = ft_calloc(n_str_len, sizeof(char));
	if(!n_str)
		return (NULL);
	while(i < ft_strlen(s1))
		n_str[i++] = s1[j++];
	j = 0;
	while(i < n_str_len)
		n_str[i++] = s2[j++];
	n_str[i] = '\0';
	return n_str;
}
