/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmestini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:55:01 by bmestini          #+#    #+#             */
/*   Updated: 2024/07/17 22:55:05 by bmestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./../../minishell.h"

t_lexer	*ft_lexer_new(char *str, t_tokens type)
{
	t_lexer	*new_node;

	new_node = malloc(sizeof(t_lexer));
	gc_push(new_node);
	new_node->str = str;
	new_node->tokens = type;
	new_node->next = NULL;
	return (new_node);
}

t_file	*ft_file_new(char *file_name, t_tokens type, int q)
{
	t_file	*new_node;

	new_node = malloc(sizeof(t_file));
	gc_push(new_node);
	new_node->file_name = file_name;
	new_node->file_type = type;
	if (q)
		new_node->quotes = true;
	else
		new_node->quotes = false;
	new_node->next = NULL;
	return (new_node);
}

t_command	*ft_command_new(char *command, t_file *file)
{
	t_command	*new_node;
	char		**command_arg;
	int			i;

	command_arg = ft_split(command, ' ');
	if (!command_arg)
		return (NULL);
	i = 0;
	while (command_arg[i])
		i++;
	new_node = malloc(sizeof(t_command));
	gc_push(new_node);
	new_node->cmd = malloc(sizeof(char *) * (i + 1));
	gc_push(new_node->cmd);
	i = 0;
	while (command_arg[i])
	{
		new_node->cmd[i] = remove_quotes(command_arg[i]);
		i++;
	}
	new_node->cmd[i] = NULL;
	new_node->file = file;
	new_node->next = NULL;
	return (new_node);
}

t_env	*ft_env_new(char *key, char *value)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	gc_push(new_node);
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}