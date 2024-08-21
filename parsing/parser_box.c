/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmestini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 00:58:32 by bmestini          #+#    #+#             */
/*   Updated: 2024/07/22 03:38:33 by bmestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"


#include <stdlib.h>

void	ft_lstadd_back_file(t_file **lst, t_file *new)
{
    t_file	*current;

    if (!lst || !new)
        return;

    if (*lst == NULL) 
    {
        *lst = new;
        return;
    }

    current = *lst;
    while (current->next != NULL) 
        current = current->next;

    current->next = new; 
}

void	ft_lstadd_back_command(t_command **lst, t_command *new)
{
    t_command	*current;

    if (!lst || !new)
        return;

    if (*lst == NULL) 
    {
        *lst = new;
        return;
    }

    current = *lst;
    while (current->next != NULL) 
        current = current->next;

    current->next = new; 
}

void	add_node_command(t_command **head, t_file **file_head, char *command)
{
	t_command	*node;

	node = ft_command_new(command, (*file_head));
	ft_lstadd_back_command(head, node);
}

void	handle_redirection(t_lexer **head, t_file **file, int token_type)
{
	char	*file_name;
	t_file	*node;
	// char	*rm_quotes;
	// char	quotes;
	int q = 0;

	file_name = NULL;
	if ((*head)->next && (*head)->next->tokens == WHITESPACE)
		*head = (*head)->next;
	*head = (*head)->next;
	while (*head && (*head)->tokens == WORD)
	{
		// Skip any whitespace within the file name
		if ((*head)->tokens == WHITESPACE)
			break ;
		// Append the current token's string to file_name
		file_name = ft_strjoin(file_name, (*head)->str);
		// Move to the next token
		*head = (*head)->next;
	}
	if((file_name[0] == '\'' || file_name[0] == '\"') && (file_name[ft_strlen(file_name) - 1] == file_name[0]))
		q = 1;
	// rm_quotes = remove_quotes(file_name);
	node = ft_file_new(file_name, token_type,q);
	ft_lstadd_back_file(file, node);
}

void	kroos(t_lexer **head, char **command, t_file **file)
{
	while ((*head) && (*head)->tokens != PIPE)
	{
		if ((*head)->tokens == WORD)
		{
			while ((*head) && (*head)->tokens == WORD)
			{
				*command = ft_strjoin(*command, (*head)->str);
				if ((*head)->next && (*head)->next->tokens == WHITESPACE)
					*command = ft_strjoin(*command, " ");
				(*head) = (*head)->next;
			}
		}
		else if ((*head)->tokens != WORD)
		{
			if ((*head)->tokens == REDIR_IN || (*head)->tokens == REDIR_OUT
				|| (*head)->tokens == HEREDOC || (*head)->tokens == APPEND)
				handle_redirection(head, file, (*head)->tokens);
			else
				(*head) = (*head)->next;
		}
	}
}