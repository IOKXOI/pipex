/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iok <iok@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:33:55 by sydauria          #+#    #+#             */
/*   Updated: 2022/11/20 13:46:29 by iok              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_commands
{
	char				**commands;
	int					pid;
	struct s_commands	*next;
}	t_commands;

typedef struct s_elements
{
	int			argc;
	int			pipefd[3];
	int			*pid_register;
	char		*here_doc;
	char		**paths;
	char		**files;
	t_commands	*first;
	t_commands	*node_commands;
	t_commands	*last;
}	t_elements;

// PARSING ////////////////////////////////////////////////////////////////////
void	init_struct(int argc, char *argv[], char *envp[], t_elements *elements);
//char	**get_commands(int argc, char *argv[]);
///////////////////////////////////////////////////////////////////////////////

// EXEC ///////////////////////////////////////////////////////////////////////
int		forking(t_elements *elements, char *envp[]);
void	ft_child(char *commands, t_commands *node, char **envp, t_elements *e);
void	ft_parent(char *commands, t_elements *elements);
void	process(char *commands, t_commands *node, char *envp[], t_elements *e);
///////////////////////////////////////////////////////////////////////////////

// CHECK //////////////////////////////////////////////////////////////////////
char	*try_to_access(char **commands, t_elements *elements);
void	check_argv(int argc, char *argv[]);
///////////////////////////////////////////////////////////////////////////////

// CHAIN_LIST /////////////////////////////////////////////////////////////////
void	new_node(t_elements *elements);
///////////////////////////////////////////////////////////////////////////////

// FREE ///////////////////////////////////////////////////////////////////////
void	error(char *str, t_elements *elements);
void	error_127(char *str, t_elements *elements);
void	free_paths(char **paths);
void	free_this_node(t_commands *node, t_elements *elements);
void	free_list(t_commands *node);
void	free_files(char **files);
///////////////////////////////////////////////////////////////////////////////

// BONUS///////////////////////////////////////////////////////////////////////
void	here_doc(char *limiter, t_elements *elements);
///////////////////////////////////////////////////////////////////////////////
#endif
