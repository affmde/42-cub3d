/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:11:27 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/12 14:41:57 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	load_textures(t_cub3d *cub3d)
{
	t_list		*tmp;
	t_textures	*texture;

	int	h = 32;
	int	w = 32;
	tmp = cub3d->textures;
	while (tmp)
	{
		texture = tmp->content;
		texture->img = ft_calloc(1, sizeof(t_img));
		texture->img->img_ptr = mlx_xpm_file_to_image(cub3d->ptr, texture->path, &w, &h);
		texture->img->data = (int *)mlx_get_data_addr(texture->img->img_ptr, &texture->img->bpp, &texture->img->size_l, &texture->img->endian);
		write(1, "#", 1);
		printf("size: %d\n", texture->img->size_l);
		tmp = tmp->next;
	}
}
