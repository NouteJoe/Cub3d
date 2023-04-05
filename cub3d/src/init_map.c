/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:41:02 by gmarzull          #+#    #+#             */
/*   Updated: 2023/03/30 15:41:37 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
/*
void	init_map(t_cub *cub)
{
	cub->len = init_text(cub);
	cub->map = malloc(sizeof(char *) * cub->len);
	if (!cub->map)
		ft_error(2);
	close(cub->fd);
	cub->fd = open(cub->map_cub, O_RDONLY);
	if (cub->fd < 0)
		ft_error(2);
	init_map2(cub);
}

void	init_map2(t_cub *cub)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	while (i < 8)
	{
		tmp = get_next_line(cub->fd);
		free (tmp);
		i++;
	}
	i = 0;
	while (i < cub->len)
	{
		tmp = get_next_line(cub->fd);
		if (tmp == NULL)
			break ;
		cub->map[i] = tmp;
		i++;
	}
	cub->map[i] = NULL;
}

int	init_text(t_cub *cub)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = -1;
	cub->text = malloc(sizeof(char *) * 9);
	if (!cub->text)
		ft_error(2);
	while (++i < 8)
		cub->text[i] = get_next_line(cub->fd);
	cub->text[i] = NULL;
	i = 0;
	while (1)
	{
		tmp = get_next_line(cub->fd);
		i++;
		if (tmp == NULL)
		{
			free (tmp);
			break ;
		}
		free (tmp);
	}
	return (i);
}*/
