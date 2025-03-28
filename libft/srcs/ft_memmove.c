/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:45:48 by nando             #+#    #+#             */
/*   Updated: 2024/12/09 20:55:08 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t count)
{
	size_t i;
	unsigned char *cast_dest;
	unsigned char *cast_src;

	i = 0;
	cast_dest = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	if(count == 0)
		return dest;
	if(cast_dest < cast_src)
	{
		while(i < count)
		{
			cast_dest[i] = cast_src[i];
			i++;
		}
	}
	else
	{
		while (0 < count)
		{
			cast_dest[count - 1] = cast_src[count - 1];
			count--;
		}
	}
	return (void *)cast_dest;
}
