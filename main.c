/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:26:44 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/26 16:49:49 by andrferr         ###   ########.fr       */
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
	file_read(argv[1], cub3d);
	
	/*t_list *a = cub3d->textures;
	while (a)
	{
		t_textures *aux;

		aux = (t_textures *)a->content;
		ft_printf("ident: %s - path: %s\n", aux->identifier, aux->path);
		a = a->next;
	}*/
	free_cub3d(cub3d);
	return (0);
}
