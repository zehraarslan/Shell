/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyildiri <tyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:39:55 by tyildiri          #+#    #+#             */
/*   Updated: 2022/11/12 00:41:55 by tyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	before_firstbox(char *argv, t_lexout *tolex)
{
	int	a;
	int	i;

	a = 0;
	i = firstbox(argv, tolex, a);
	return (i);
}

int	firstbox(char *argv, t_lexout *tolex, int i)
{
	while (((argv[i] <= 13 && argv[i] >= 9)
			|| argv[i] == 32) && argv[i] != '\0')
		i++;
	while (!((argv[i] <= 13 && argv[i] >= 9)
			|| argv[i] == 32) && argv[i] != '\0' && argv[i] != '|')
	{
		if (argv[i] == '"')
			i += box1indoublequote(argv + i, tolex);
		else if (argv[i] == 39)
			i += box1insinglequote(argv + i, tolex);
		else if (argv[i] != '"' && argv[i] != 39)
			tolex->box1[tolex->box1index++] = argv[i++];
	}
	if (tolex->box1index == 0)
	{
		if (tolex->boxwasin == 1)
			tolex->illegalcommand = 1;
		free(tolex->box1);
		tolex->box1 = NULL;
	}
	else
		tolex->box1[tolex->box1index++] = '\0';
	return (i);
}

int	box1indoublequote(char *argv, t_lexout *tolex)
{
	int	i;

	i = 1;
	while (argv[i] != '"')
	{
		tolex->box1[tolex->box1index++] = argv[i++];
	}
	i++;
	tolex->boxwasin = 1;
	return (i);
}

int	box1insinglequote(char *argv, t_lexout *tolex)
{
	int	i;

	i = 1;
	while (argv[i] != 39)
	{
		tolex->box1[tolex->box1index++] = argv[i++];
	}
	i++;
	tolex->boxwasin = 1;
	return (i);
}
