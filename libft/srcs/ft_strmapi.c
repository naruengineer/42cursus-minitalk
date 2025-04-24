/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:25:46 by nando             #+#    #+#             */
/*   Updated: 2025/04/08 17:32:35 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char	alternate_case(unsigned int index, char c)
//{
//	if (index % 2 == 0 && c >= 'A' && c <= 'Z')
//		return (c + 32);
//	else if (index % 2 != 0 && c >= 'a' && c <= 'z')
//		return (c - 32);
//	return (c);
//}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_string;
	size_t	str_len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	str_len = ft_strlen(s);
	new_string = malloc((str_len + 1) * sizeof(char));
	while (i < str_len)
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
