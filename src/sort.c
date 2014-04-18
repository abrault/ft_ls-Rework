/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 16:56:22 by abrault           #+#    #+#             */
/*   Updated: 2014/04/18 18:58:14 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <libft.h>
#include <sys/stat.h>
#include <time.h>

static t_file	*sort_by_ascii(t_file *file)
{
	int				change;
	t_file			*ptr;

	change = 1;
	ptr = file;
	while (change)
	{
		change = 0;
		while (file && file->back != NULL)
		{
			if (ft_strcmp(file->elem->d_name, file->back->elem->d_name) > 0)
				change = swap_file(file, file->back);
			else
			{
				file = file->back;
				if (file == NULL)
					file = ptr;
			}
		}
		file = ptr;
	}
	return (file);
}

static t_file	*sort_by_time(t_file *file)
{
	int				change;
	t_file			*ptr;
	struct stat		_stat[2];

	change = 1;
	ptr = file;
	while (change)
	{
		change = 0;
		while (file && file->back != NULL)
		{
			stat(file->elem->d_name, &_stat[0]);
			stat(file->back->elem->d_name, &_stat[1]);
			if (_stat[0].st_mtime < _stat[1].st_mtime)
				change = swap_file(file, file->back);
			else
			{
				file = file->back;
				if (file == NULL)
					file = ptr;
			}
		}
		file = ptr;
	}
	return (file);
}

t_file			*sort(char o, t_file *file)
{
	if (o == 'a') // Par code ascii
		file = sort_by_ascii(file);
	else if (o == 't') // Par date + heure
		file = sort_by_time(file);
	return (file);
}
