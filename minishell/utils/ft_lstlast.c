/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmestini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 03:44:00 by bmestini          #+#    #+#             */
/*   Updated: 2024/07/22 03:44:01 by bmestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./../../minishell.h"

t_lexer	*ft_lstlast(t_lexer *lst)
{
	t_lexer	*p;

	if (lst == NULL)
		return (NULL);
	p = lst;
	while (p->next != NULL)
		p = p->next;
	return (p);
}