/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box3_fornorm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyildiri <tyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:40:00 by tyildiri          #+#    #+#             */
/*   Updated: 2022/11/12 00:41:50 by tyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	thirdbox_is_null(t_lexout *tolex)
{
	if (tolex->box3index == 0)
	{
		free(tolex->box3);
		tolex->box3 = NULL;
		return (1);
	}
	return (0);
}
