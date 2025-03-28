/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:25:43 by nando             #+#    #+#             */
/*   Updated: 2024/12/09 20:54:57 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t i;
	unsigned char *cast_dest;
	unsigned char *cast_src;

	i = 0;
	cast_dest = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	if(count == 0)
		return NULL;
	while (i < count)
	{
		cast_dest[i] = cast_src[i];
		i++;
	}
	return (void *)cast_dest;
}
