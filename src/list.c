/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 17:56:32 by abrault           #+#    #+#             */
/*   Updated: 2014/04/18 21:03:14 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdlib.h>

t_file		*add_file(struct dirent *l_dir, t_file *file)
{
	t_file		*new_file;

	new_file = malloc(sizeof(t_file));
	new_file->elem = l_dir;
	new_file->back = file;
	new_file->next = NULL;
	if (file)
		file->next = new_file;
	return (new_file);
}

int			swap_file(t_file *first, t_file *second)
{
	t_file		*new_file;

	new_file = malloc(sizeof(t_file));
	new_file->elem = first->elem;
	first->elem = second->elem;
	second->elem = new_file->elem;
	free(new_file);
	return (1);
}
