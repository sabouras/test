/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_linkedlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmestini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:34:52 by bmestini          #+#    #+#             */
/*   Updated: 2024/07/31 06:34:53 by bmestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

static int	search_in(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static t_env	*new_node(char *envp_line)
{
	t_env	*lst;
	char	*key;
	char	*value;

	lst = malloc(sizeof(t_env));
	gc_push(lst);
	key = ft_substr(envp_line, 0, search_in(envp_line, '='));
	lst->key = key;
	value = ft_substr(envp_line, search_in(envp_line, '=') + 1,
			ft_strlen(envp_line));
	lst->value = value;
	lst->next = NULL;
	return (lst);
}

static t_env	*get_last_node(t_env *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

static void	add_back(t_env **head, t_env *new)
{
	if (!head)
		return ;
	if (head && *head)
	{
		get_last_node(*head)->next = new;
		return ;
	}
	*head = new;
}

t_env	*envp_to_list(char **envp)
{
	int		i;
	t_env	*list;

	i = 0;
	list = 0;
	while (envp[i])
	{
		add_back(&list, new_node(envp[i]));
		i++;
	}
	return (list);
}