/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:24:58 by nando             #+#    #+#             */
/*   Updated: 2025/03/12 15:44:09 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int count_string(char const *s, char c)
{
	int i;
	int count;
	int is_inside_word;
	
	i = 0;
	count = 0;
	is_inside_word = 1;
	if (!s)
        return 0;
	while (s[i] != '\0')
	{
		if(s[i] != c && is_inside_word == 1)
		{
			count++;
			is_inside_word = 0;
		}
		else if(s[i] == c)
			is_inside_word = 1;
		i++;
	} 
	return count;
}


static char *create_new_string(char const *s, char c)
{
	char *new_string;
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != c)
		i++;
	new_string = malloc((i + 1) * sizeof(char));
	if (!new_string)
		return NULL;
	while (j < i)
	{
		new_string[j] = s[j];
		j++;
	}
	new_string[j] = '\0';
	return new_string;
}

static void free_split(char **result)
{
    int i = 0;
    if (!result)
        return;
    while (result[i])
    {
        free(result[i]);
        i++;
    }
    free(result);
}

char **ft_split(char const *s, char c)
{
	char **result;
	int i;
	int j;
	
	i = 0;
	j = 0;
	if(!s)
		return NULL;
	result = malloc((count_string(s, c) + 1) * sizeof(char *));
	if (!result)
	{
		free_split(result);
		return NULL;
	}
	while(s[i] != '\0')
	{
		if(s[i] != c)
		{
			result[j] = create_new_string(&s[i], c);
			j++;
			while(s[i] && s[i] !=c)
				i++;
		}
		else
			i++;
	}
	result[j] = NULL;
	return result;
}
