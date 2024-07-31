/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmestini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 01:01:56 by bmestini          #+#    #+#             */
/*   Updated: 2024/07/19 05:01:57 by bmestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./../../minishell.h"

char	*remove_quotes(char *arg)
{
	char	quote_char;
	char	*str;

	int (i), (j), (k);
	i = 0;
	j = 0;
	str = malloc(ft_strlen(arg) * (sizeof(char) + 1));
	gc_push(str);
	while (arg[i])
	{
		if (arg[i] == '"' || arg[i] == '\'')
		{
			quote_char = arg[i++];
			k = i;
			while (arg[k] != quote_char && arg[k])
				k++;
			if (!arg[k])
				return (arg);
			while (arg[i] && arg[i] != quote_char)
				str[j++] = arg[i++];
			if (arg[i])
				i++;
		}
		else
			str[j++] = arg[i++];
	}
	return (str[j] = '\0', str);
}

t_command	*parser(t_lexer *data)
{
	t_lexer		*head;
	char		*command;
	t_file		*file;
	t_command	*command_list;

	command = NULL;
	head = data;
	command_list = NULL;
	file = NULL;
	while (head)
	{
		while (head && head->tokens != PIPE)
			kroos(&head, &command, &file);
		add_node_command(&command_list, &file, command);
		command = NULL;
		file = NULL;
		if (head && head->tokens == PIPE)
			head = head->next;
	}
	// display_token_command(command_list);
	return (command_list);
}