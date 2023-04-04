/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:04:21 by gmarzull          #+#    #+#             */
/*   Updated: 2023/03/30 15:40:21 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define PI M_PI
# define HEIGHT 500
# define WIDTH 500

typedef struct s_color
{
	u_int8_t	r;
	u_int8_t	g;
	u_int8_t	b;
	u_int8_t	a;
}	t_color;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_ray
{
	t_vector	start;
	t_vector	end;
}	t_ray;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	double		movspeed;
	double		rotspeed;
	// (...)
}	t_player;

typedef struct s_cub
{
	void		*screen;
	mlx_image_t	*ptr_img;//image
	mlx_t		*mlx_pointer;
	t_player	*player;
	t_ray		*ray;
	char		*map_cub;
	char		**map;//la map
	int			fd;
	char		**text;//au dessus de la map
	int			len;
	int			mapx;
	int			mapy;

	char 		*get_next;
	int			flag;
	char		*tmp;//remplir avec gnl  complet
	char		**tmp_file;// complete copy file av[1], need separate in 2 parts
	char		*NO;//copier la valeur
	char		*SO;
	char		*WE;
	char		*EA;
	t_color		C;
	t_color		F;
}	t_cub;

//minimap.c
void		rendeer_minimap(t_cub *cub);
bool		is_walkable(char c);
void		make_square(t_cub *cub, int x, int y, u_int32_t pixel_color);
void		make_player(t_cub *cub, u_int32_t pixel_color);
void		make_player_fov(t_cub *cub, uint32_t pixel_color);

// init_cub.c
t_cub		*init_cub(void);
mlx_t		*init_mlx(void);
uint32_t	init_color(u_int8_t r, u_int8_t g, u_int8_t b, u_int8_t a);

//init_map.c
void		init_map(t_cub *cub);
void		init_map2(t_cub *cub);
int			init_text(t_cub *cub);

//init_player.c
void		init_vector(t_vector *vector);
void		init_player(t_cub *cub);
void		find_player(t_cub *cub);
void		find_dir(char c, t_vector *dir);

/*// check.c
int			check_map(t_cub *cub, char *str);
int			check_compas(t_cub *cub);
int			check_color(t_cub *cub);
int			check_map2(t_cub *cub);*/

//check_file.c
int			check_file(t_cub *cub, char *str);

int			find_textures(t_cub *cub);
int 		remoove_space( char *str, int i);

//check_map.c
int			check_map(char **str, int len);
int			find_map(t_cub *cub);

//utils.c
void		ft_error(int i);
void		print_tab(char **tab);

//free.c
void		free_cub(t_cub *cub);
void		free_tab(char **tab);

//move.c
void		ft_hook(void *param);
void		ft_move(t_cub *cub, keys_t key);
void		ft_rotate(t_cub *cub, keys_t key);

//ray.c
void		ft_raycast(t_cub *cub);

#endif