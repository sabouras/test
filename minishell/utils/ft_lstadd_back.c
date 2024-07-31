/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmestini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 03:42:56 by bmestini          #+#    #+#             */
/*   Updated: 2024/07/22 03:42:57 by bmestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./../../minishell.h"

void	ft_lstadd_back(t_lexer **lst, t_lexer *new)
{
	t_lexer	*last;

	last = *lst;
	if (lst == NULL || new == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
}