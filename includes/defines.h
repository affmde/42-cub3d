/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:04:27 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/24 10:15:05 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

//window size
# define WIDTH 1280//1980
# define HEIGHT 720//1080

//pi
# define PI 3.141593

//directions
# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4

//moving
# define PLAYER_BODY 0.5
# define MOVEMENT_SPEED 0.08
# define TEST_SPEED 1
# define ROTATE_SPEED 0.07

//minimap
# define MINIMAP_SIZE 7
# define MINI_RAY_ACCURACY 3
# define MINI_RAY_DIST 25
# define MINI_RAY_MAX_DIST 84
# define RAY_LEN_ACCURACY 0.15

//crosshair
# define CH_MID 3
# define CH_LEN 10
# define CH_COLOR 0x00FF00

//keys
# define MAC_UP 13
# define MAC_RIGHT 2
# define MAC_LEFT 0
# define MAC_DOWN 1
# define MAC_R_LEFT 123
# define MAC_R_RIGHT 124
# define LIN_UP 119
# define LIN_RIGHT 100
# define LIN_DOWN 115
# define LIN_LEFT 97
# define LIN_R_RIGHT 65363
# define LIN_R_LEFT 65361
# define FRAME_RATE 10
# define MAC_CTRL 256
# define LIN_CTRL 65507

#endif
