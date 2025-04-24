/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:26:15 by nando             #+#    #+#             */
/*   Updated: 2025/04/08 17:32:28 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void	alternate_case_in_place(unsigned int index, char *c)
//{
//	if (c != NULL)
//	{
//		if (index % 2 == 0 && *c >= 'A' && *c <= 'Z')
//			*c += 32;
//		else if (index % 2 != 0 && *c >= 'a' && *c <= 'z')
//			*c -= 32;
//	}
//}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	str_len;
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	str_len = ft_strlen(s);
	while (i < str_len)
	{
		f(i, &s[i]);
		i++;
	}
}
