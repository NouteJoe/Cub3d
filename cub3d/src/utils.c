/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:34:41 by gmarzull          #+#    #+#             */
/*   Updated: 2023/03/27 13:41:04 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(int i)
{
	printf("Error\n");
	if (i == 1)
		printf("Need one and only one map as argument.");
	if (i == 2)
		printf("Memory allocation failed");
	if (i == 3)
		printf(".cub file not valid");
	if (i == 4)
		printf("Miss textures path\n");
	if (i == 5)
		printf("Check code color\n");
	if (i == 6)
		printf("Invalid map, miss wall\n");
	exit(1);
}

void	print_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			printf("%c", tab[i][j]);
			j++;
		}
		i++;
	}
	printf("\n");
}
