/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:24:22 by nando             #+#    #+#             */
/*   Updated: 2025/04/08 17:32:40 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	char	*trimed_s1;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s1_len = ft_strlen(s1);
	while (s1_len > 0 && ft_strchr(set, s1[s1_len - 1]))
		s1_len--;
	trimed_s1 = ft_calloc(s1_len + 1, sizeof(char));
	if (!trimed_s1)
		return (NULL);
	ft_strlcpy(trimed_s1, s1, s1_len + 1);
	return (trimed_s1);
}
