/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 16:04:55 by abrault           #+#    #+#             */
/*   Updated: 2014/04/18 21:03:15 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_ls.h>

t_file	*get_liste(t_file *file)
{
	DIR				*dir;
	struct dirent	*l_dir;

	dir = opendir(".");
	while ((l_dir = readdir(dir)))
		file = add_file(l_dir, file);
	closedir(dir);
	return (file);
}

int		main(int ac, char **av)
{
	char			*option;
	t_file			*file;

	file = NULL;
	option = ft_strdup("arlRt");
	free(get_command(ac, av, &option));
	file = get_liste(file);
	file = sort('a', file);
	if (option[4] == '_')
		file = sort('t', file);
	display(file, option);
	free(option);
	return (0);
}
