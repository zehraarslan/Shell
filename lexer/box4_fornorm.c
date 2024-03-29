/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box4_fornorm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyildiri <tyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:40:04 by tyildiri          #+#    #+#             */
/*   Updated: 2022/11/12 00:41:46 by tyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	box4passquote(char *argv)
{
	int	i;

	i = 1;
	while (argv[i] != '"' && argv[i] != '\0')
		i++;
	return (i + 1);
}

int	box4passsinglequote(char *argv)
{
	int	i;

	i = 1;
	while (argv[i] != 39 && argv[i] != '\0')
		i++;
	return (i + 1);
}

int	box4inquote_mode2(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	argv[i++] = 32;
	while (argv[i] != '"' && argv[i] != '\0')
	{
		tolex->box4[tolex->box4index++] = argv[i];
		argv[i++] = 32;
	}
	argv[i++] = 32;
	return (i);
}

int	box4insinglequote_mode2(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	argv[i++] = 32;
	while (argv[i] != 39 && argv[i] != '\0')
	{
		tolex->box4[tolex->box4index++] = argv[i];
		argv[i++] = 32;
	}
	argv[i++] = 32;
	return (i);
}
