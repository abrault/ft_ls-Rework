/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 16:17:04 by abrault           #+#    #+#             */
/*   Updated: 2014/04/18 21:03:11 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_ls.h>

void		*get_command(int ac, char **av, char **option)
{
	int		y;
	int		j;
	char	*str;
	char	*ptr;

	str = ft_strdup(*option);
	y = 0;
	while ((y++ || 1) && y < ac)
	{
		j = 0;
		if (av[y][0] != '-' || ft_strlen(av[y]) == 1)
			return (str);
		while ((j++ || 1) && av[y][j] != '\0')
		{
			if ((ptr = ft_strchr(str, av[y][j])) == NULL)
				return (str);
			(*option)[ptr - str] = '_';
		}
	}
	return (str);
}

t_list		*get_search_list(int ac, char **av)
{
	t_list		*list;
	int			i;
	t_list		*ptr;

	i = 1;
	list = NULL;
	list = add_list(".", list);
	ptr = list;
	while (i < ac)
	{
		ft_putendl(av[i]);
		if (av[i][0] != '-')
			list = add_list(av[i], list);
		i++;
	}
	return (ptr);
}
