/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyildiri <tyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:44:39 by tyildiri          #+#    #+#             */
/*   Updated: 2022/11/12 00:45:05 by tyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_node(t_node *node, t_lexout *table)
{
	node->command = table->box1;
	node->flags = table->box2;
	node->argument = table->box3;
	node->redirections = table->box4;
	node->illegalflag = table->illegalflag;
	node->null_num = table->box3null;
	node->illegalcommand = table->illegalcommand;
	node->id = table->currentnode;
	node->in = 0;
	node->out = 0;
	node->cmd_path = NULL;
	node->next_node = NULL;
	node->my_path = NULL;
	node->exec_args = NULL;
	node->heredoc_input = NULL;
}

void	create_node(t_shell *shell, t_lexout *table)
{
	static int		count;
	static t_node	*prev;
	t_node			*node;

	if (table->currentnode == 0)
		count = 0;
	node = malloc(sizeof(t_node));
	init_node(node, table);
	if (count)
	{
		prev->next_node = node;
		node->previous_node = prev;
	}
	else
	{
		shell->head = node;
		node->previous_node = NULL;
	}
	prev = node;
	++count;
	if (count == table->totalnode)
		shell->tail = node;
	set_node(shell, node);
}

int	builtin_check(char *command)
{
	if (ft_strncmp_exact(command, "echo", 5) || \
		ft_strncmp_exact(command, "/bin/echo", 10))
		return (1);
	else if (ft_strncmp_exact(command, "cd", 3) || \
		ft_strncmp_exact(command, "/usr/bin/cd", 12))
		return (2);
	else if (ft_strncmp_exact(command, "pwd", 4) || \
		ft_strncmp_exact(command, "/bin/pwd", 9))
		return (3);
	else if (ft_strncmp_exact(command, "export", 7))
		return (4);
	else if (ft_strncmp_exact(command, "unset", 6))
		return (5);
	else if (ft_strncmp_exact(command, "env", 4) || \
		ft_strncmp_exact(command, "/usr/bin/env", 13))
		return (6);
	else if (ft_strncmp_exact(command, "exit", 5))
		return (7);
	return (0);
}

char	*search_in_path(t_shell *shell, t_node *node)
{
	int		i;
	char	*searched;

	i = is_there_path(shell);
	if (!access(node->command, X_OK) && node->command != NULL)
		return (ft_strdup(node->command));
	else if (i == -1)
		return (NULL);
	else
	{
		node->my_path = split_path(shell, i);
		i = 0;
		while (node->my_path[i])
		{
			searched = ft_strjoin_path(node->my_path[i], node->command);
			if (!access(searched, X_OK) && node->command != NULL)
				return (searched);
			free(searched);
			++i;
		}
		return (NULL);
	}
}
