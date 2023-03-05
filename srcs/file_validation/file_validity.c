/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:56:34 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/05 11:45:30 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	file_validity(t_cub3d *cub3d)
{
	int error_code;

	error_code = valid_map(cub3d);
	if (error_code)
	{
		validity_error_msg(1);
		free_cub3d(cub3d);
		return (1);
	}
	error_code = elements_validity(cub3d);
	if (error_code)
	{
		
		if (error_code == 1)
			validity_error_msg(2);
		else if (error_code == 2)
			validity_error_msg(3);
		free_cub3d(cub3d);
		return (1);
	}
	return (0);
}
