/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 16:06:12 by abrault           #+#    #+#             */
/*   Updated: 2014/04/18 19:16:25 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS

# include <sys/types.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>

typedef struct s_file	t_file;
typedef struct s_list	t_list;

struct					s_file
{
	struct dirent		*elem;
	t_file				*back;
	t_file				*next;
};

struct					s_list
{
	char				*name;
	t_list				*next;
};

t_list	*add_list(char *str, t_list *list);
t_list	*get_search_list(int ac, char **av);
void	*get_command(int ac, char **av, char **option);
t_file	*add_file(struct dirent *l_dir, t_file *file);
int		swap_file(t_file *first, t_file *second);
t_file	*sort(char o, t_file *file);
void	display(t_file *file, char *option);

#endif
