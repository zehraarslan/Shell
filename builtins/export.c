/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyildiri <tyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:37:04 by tyildiri          #+#    #+#             */
/*   Updated: 2022/11/12 00:38:17 by tyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_export(t_shell *shell)
{
	char	**temp;

	temp = duplicate_env(shell->env);
	compare_ascii(temp);
	show_export(temp);
}

int	ft_strncmp_ascii(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	while (i < size && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	compare_ascii(char **temp)
{
	int		i;
	int		j;
	char	*tem2;

	i = 0;
	while (temp[i])
	{
		j = 0;
		while (temp[i + j])
		{
			if (ft_strncmp_ascii(temp[i], temp[i + j], ft_strlen(temp[i])) > 0)
			{
				tem2 = temp[i + j];
				temp[i + j] = temp[i];
				temp[i] = tem2;
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	show_export(char **temp)
{
	int		i;
	int		a;
	char	t;

	a = 0;
	t = 0;
	i = 0;
	show_export_helper(temp, i, a, t);
}

void	show_export_helper(char **temp, int i, int a, int t)
{
	while (temp[i])
	{
		a = 0;
		t = 0;
		write(1, "declare -x ", 12);
		while (temp[i][a] != '=' && temp[i][a] != '\0')
		{
			write(1, &temp[i][a], 1);
			a++;
		}
		if (temp[i][a] == '=')
		{
			write(1, "=\"", 2);
			t = 1;
		}
		while (temp[i][a] != '\0')
		{
			a += 1;
			write(1, &temp[i][a], 1);
		}
		if (t == 1)
			write(1, "\"", 1);
		printf("\n");
		i++;
	}
}
