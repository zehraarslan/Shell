/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyildiri <tyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:40:06 by tyildiri          #+#    #+#             */
/*   Updated: 2022/11/12 00:40:11 by tyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fourthbox(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	while (argv[i] != '\0' && argv[i] != '|')
	{
		if (argv[i] == '"')
			i += box4passquote(argv + i);
		else if (argv[i] == 39)
			i += box4passsinglequote(argv + i);
		else if (argv[i] == '<')
			i += fourthbox_direction_less(argv + i, tolex);
		else if (argv[i] == '>')
		{
			if (argv[i + 1] == '>')
				i += box4greatgreat(argv + i, tolex);
			else
				i += box4great(argv + i, tolex);
		}
		else
			i++;
		if (tolex->box4index > 0)
				tolex->box4space = 1;
	}
}

int	fourthbox_direction_less(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	if (argv[i + 1] == '<')
		i += box4lessless(argv, tolex);
	else if (argv[i + 1] == '>')
		i += box4wtf(argv, tolex);
	else
		i += box4less(argv, tolex);
	return (i);
}

void	is_fourthbox_null(t_lexout *tolex)
{
	if (tolex->box4index == 0)
	{
		free(tolex->box4);
		tolex->box4 = NULL;
	}
	if (tolex->box4index > 0)
	{
		tolex->box4[tolex->box4index++] = '\0';
	}
}
