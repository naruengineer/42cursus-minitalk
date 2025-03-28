/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:19:51 by nando             #+#    #+#             */
/*   Updated: 2024/12/09 20:54:38 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	size_t i;
	unsigned char *cast_buf1;
	unsigned char *cast_buf2;

	i = 0;
	cast_buf1 = (unsigned char *)buf1;
	cast_buf2 = (unsigned char *)buf2;
	while(i < count)
	{
		if(cast_buf1[i] != cast_buf2[i])
			return (int)(cast_buf1[i] - cast_buf2[i]);
		i++;
	}
	return 0;
}
