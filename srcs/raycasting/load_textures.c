/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:11:27 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/13 16:48:31 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_texture_info(t_textures *texture)
{
	texture->img->data = (int *)mlx_get_data_addr(texture->img->img_ptr, &texture->img->bpp, &texture->img->size_l, &texture->img->endian);
	if (!texture->img->data)
	{
		invalid_texture(texture->path);
		return (1);
	}
	return (0);
}

int	load_textures(t_cub3d *cub3d)
{
	t_list		*tmp;
	t_textures	*texture;

	tmp = cub3d->textures;
	while (tmp)
	{
		texture = tmp->content;
		texture->img = ft_calloc(1, sizeof(t_img));
		texture->img->img_ptr = mlx_xpm_file_to_image(cub3d->ptr, texture->path, &texture->height, &texture->width);
		if (!texture->img->img_ptr)
		{
			invalid_texture(texture->path);
			return (1);
		}
		if (get_texture_info(texture))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

