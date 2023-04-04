# include "cub3d.h"

int	test(t_cub *cub, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	cub->text = malloc(sizeof(char *) * 8);
	if (!tmp)
		ft_error(2);
	while (i++ < 8)
		cub->text[i] = get_nex_line(cub->fd);
	cub->text[i] = NULL;
	while (++i)
	{
		tmp = get_next_line(cub->fd);
		if (tmp == NULL)
		{
			free (tmp);
			break ;
		}
		free (tmp);
	}
}