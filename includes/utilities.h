/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:16:01 by aggrigor          #+#    #+#             */
/*   Updated: 2024/05/28 10:33:16 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include "minishell.h"
# include "tokenization.h"

int			ft_isalpha(int c);
int			ft_isspace(char c);
void		print_token_list(t_token *token_list);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
void		ft_token_list_clear(t_token **lst);
int			ft_is_operator(char *s, int i);
t_env_elem	*init_env(char **env);
void		check_env(t_shell *shell);
int			ft_strcmp(char *s1, char *s2);
char		*find_key(char	*full_key_val);
char		*find_value(char	*full_key_val);

#endif