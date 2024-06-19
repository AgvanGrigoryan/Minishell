/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:56:11 by natamazy          #+#    #+#             */
/*   Updated: 2024/06/19 14:50:27 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utilities.h"

void	pwd(int fdtowrite, int *is_builtin)
{
	char	path[PATH_MAX];

	// (void) fdtowrite;
	// printf("PWD_YEEE\n");
	if (!getcwd(path, PATH_MAX))
	{
		ft_putstr_fd("ERROR\n", fdtowrite);
		return ;
	}
	ft_putstr_fd(path, fdtowrite);
	ft_putstr_fd("\n", fdtowrite);
	*is_builtin = 1;
}
