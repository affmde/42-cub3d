/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:26:44 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/27 16:34:51 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d *cub3d;
	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments.", 2);
		return (1);
	}
	cub3d = cub3d_init();
	if(file_read(argv[1], cub3d))
	{
		ft_printf("HERE\n");
		free_cub3d(cub3d); //CHECK HERE SEG FAULT CREATED BY NEW LINE IN MIDDLE OF MAP!!!!!
		return (0);
	}
	if (valid_map(cub3d))
	{
		ft_putendl_fd("Invalid map.", 2);
		free_cub3d(cub3d);
		return (0);
	}
	/*t_list *a = cub3d->textures;
	while (a)
	{
		t_textures *aux;

		aux = (t_textures *)a->content;
		ft_printf("ident: %s - path: %s\n", aux->identifier, aux->path);
		a = a->next;
	}*/
	t_list *a = cub3d->map->map;
	int	i;
	i = 0;
	while (a)
	{
		ft_printf("i: %d - %s",i, a->content);
		a = a->next;
		i++;
	}
	ft_printf("map height: %d\n", cub3d->map->height);
	free_cub3d(cub3d);
	return (0);
}
