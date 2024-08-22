/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmestini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:37:50 by bmestini          #+#    #+#             */
/*   Updated: 2024/07/17 22:37:51 by bmestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include "./gc/gc.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
// #define WORD 1
// #define PIPE 2
// #define REDIR_IN 3
// #define REDIR_OUT 4
// #define HEREDOC 5
// #define APPEND 6

typedef struct s_list
{
	char				*content;
	struct s_list		*next;
}						t_list;

typedef enum e_num
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HEREDOC,
	APPEND,
	WHITESPACE,
	QUOTES
}						t_tokens;

typedef struct s_lexer
{
	char				*str;
	t_tokens			tokens;
	struct s_lexer		*next;
}						t_lexer;
typedef struct s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
}						t_env;

///////////////////execute////////////
typedef struct s_file
{
	char				*file_name;
	t_tokens			file_type;
	bool				quotes;
	struct s_file		*next;
}						t_file;

typedef struct s_command
{
	char				**cmd;
	t_file				*file;
	struct s_command	*next;
}						t_command;
////////////////////////////////////////////

typedef struct s_tool
{
	char				*cmd;
	char				**env_copy;
	t_lexer				*lexer_list;
	t_command			*command;
	t_env				*env;
}						t_tool;