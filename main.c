/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmestini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:38:06 by bmestini          #+#    #+#             */
/*   Updated: 2024/07/31 06:38:07 by bmestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

char	**convert_env(t_env *envar)
{
	t_env	*cur;
	char		**env;
	int			i;

	i = 0;
	cur = (envar);
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	env = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (cur)
	{
		env[i] = ft_strjoin(cur->key, ft_strjoin("=", cur->value));
		i++;
		cur = cur->next;
	}
	env[i] = NULL;
	return (env);
}

int	exec_command(t_command	*cmnd, t_env *envar)
{
	char	**ev;

	ev = convert_env(envar);
	if (execve(cmnd->cmd[0], cmnd->cmd, ev) == -1)
		exit(127);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_tool	tools;
	t_env	*list;

	if (ac != 1 || av[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	list = envp_to_list(env);
	loop_minishell(&tools, list);
	
}