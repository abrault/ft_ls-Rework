/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 17:00:01 by abrault           #+#    #+#             */
/*   Updated: 2014/04/18 19:06:04 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <libft.h>
#include <sys/stat.h>
#include <time.h>

static t_file	*reverse_liste(t_file *file)
{
	t_file		*ptr;

	while (file)
	{
		if (file->back == NULL)
			ptr = file;
		file = file->back;
	}
	return (ptr);
}

static void		option_l(char *file_name)
{
	(void)file_name;
}

void			display(t_file *file, char *option)
{
	if (option[1] == '_')
		file = reverse_liste(file);
	while (file)
	{
		if (ft_strchr(file->elem->d_name, '.') && option[0] == 'a')
			;
		else
		{
			if (option[2] == '_')
				option_l(file->elem->d_name);
			ft_putendl(file->elem->d_name);
		}
		if (option[1] != '_')
			file = file->back;
		else
			file = file->next;
	}
}
