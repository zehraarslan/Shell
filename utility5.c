/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyildiri <tyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:47:43 by tyildiri          #+#    #+#             */
/*   Updated: 2022/11/12 00:48:05 by tyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	string_length(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str++)
		i++;
	return (i);
}

int	check_newline(char *ptr)
{
	if (!ptr)
		return (1);
	while (*ptr)
	{
		if (*ptr == '\n')
			return (0);
		ptr++;
	}
	return (1);
}

char	*append_string(char *str, char *buf)
{
	char	*result;
	int		i;
	int		j;

	if (!buf)
		return (NULL);
	if (!str)
	{	
		str = malloc(1);
		*str = '\0';
	}
	result = malloc(string_length(str) + string_length(buf) + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (str[++i])
		result[i] = str[i];
	j = 0;
	while (buf[j])
		result[i++] = buf[j++];
	result[i] = '\0';
	free(str);
	return (result);
}
