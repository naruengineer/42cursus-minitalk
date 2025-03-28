/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:21:24 by nando             #+#    #+#             */
/*   Updated: 2025/03/11 14:51:36 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	subs_len;
	char	*str_cpy;

	i = 0;
	if(!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return ((char *)ft_calloc(1, sizeof(char)));
	subs_len = s_len - start;
	if (subs_len > len)
		subs_len = len;
	str_cpy = (char *)ft_calloc(subs_len + 1, sizeof(char));
	if (!str_cpy)
		return (NULL);
	while (i < subs_len)
	{
		str_cpy[i] = s[start];
		start++;
		i++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}
