/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyildiri <tyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:39:58 by tyildiri          #+#    #+#             */
/*   Updated: 2022/11/12 00:41:52 by tyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	before_secondbox(char *argv, t_lexout *tolex)
{
	int	a;
	int	i;

	a = 0;
	i = 0;
	a += lexer_escapespace(argv, tolex);
	i += secondbox(argv, tolex, a);
	return (i);
}

int	secondbox(char *argv, t_lexout *tolex, int i)
{
	while (tolex->box2runaway != 1 && argv[i] != '\0' && argv[i] != '|')
	{
		if (argv[i] == '"')
			i += secondboxinquote(argv + i, tolex);
		else if (argv[i] == 39)
			i += secondboxinsinglequote(argv + i, tolex);
		else if (argv[i] == '-')
		{
			if (((argv[i + 1] <= 13 && argv[i + 1] >= 9) || argv[i + 1] == 32))
				return (i);
			while (!((argv[i] <= 13 && argv[i] >= 9) || argv[i] == 32) \
		&& argv[i] != '"' && argv[i] != '\0' && argv[i] != 39 && argv[i] != '|')
				tolex->box2[tolex->box2index++] = argv[i++];
			tolex->box2lastisspace = 0;
		}
		else if (tolex->box2index > 0 && tolex->box2lastisspace != 1)
		{
			tolex->box2[tolex->box2index++] = argv[i++];
			tolex->box2lastisspace = 0;
		}
		else
			tolex->box2runaway = 1;
		i += lexer_escapespace(argv + i, tolex);
	}
	return (i);
}

int	secondboxinquote(char *argv, t_lexout *tolex)
{
	int	i;

	i = 1;
	if (secondbox_fornorm_v2(argv, tolex) == 2)
		return (2);
	if (secondbox_fornorm_v2(argv, tolex) == 0)
		return (0);
	else
	{
		if (((argv[i] <= 13 && argv[i] >= 9)
				|| argv[i] == 32) && tolex->box2lastisspace == 1)
		{
			tolex->box2runaway = 1;
			return (0);
		}
		while (argv[i] != '"')
		{
			if ((argv[i] <= 13 && argv[i] >= 9) || argv[i] == 32)
				tolex->illegalflag = 1;
			tolex->box2[tolex->box2index++] = argv[i++];
		}
	}
	tolex->box2lastisspace = 0;
	return (i + 1);
}

int	secondboxinsinglequote(char *argv, t_lexout *tolex)
{
	int	i;

	i = 1;
	if (secondbox_fornorm(argv, tolex) == 2)
		return (2);
	if (secondbox_fornorm(argv, tolex) == 0)
		return (0);
	else
	{
		if (((argv[i] <= 13 && argv[i] >= 9)
				|| argv[i] == 32) && tolex->box2lastisspace == 1)
		{
			tolex->box2runaway = 1;
			return (0);
		}
		while (argv[i] != 39)
		{
			if ((argv[i] <= 13 && argv[i] >= 9) || argv[i] == 32)
				tolex->illegalflag = 1;
			tolex->box2[tolex->box2index++] = argv[i++];
		}
	}
	tolex->box2lastisspace = 0;
	return (i + 1);
}

int	isbeforeflag(t_lexout *tolex)
{
	int	i;

	i = tolex->box2index;
	if (tolex->box2index == 0)
		return (1);
	if (((tolex->box2[i] <= 13 && tolex->box2[i] >= 9)
			|| tolex->box2[i] == 32))
		return (1);
	return (0);
}
