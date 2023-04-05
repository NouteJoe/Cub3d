#include "../cub3d.h"

int remoove_space( char *str, int i)
{
	while(str[i] == ' ')
		i++;
	return(i);
}

void ft_isdigit( char **tmp)
{
	int i = 0;
	int j = 0;
	while (tmp[j])
	{
		i = 0;
		while (tmp[j][i])
		{
			if (tmp[j][i] >= '0' && tmp[j][i] <= '9')	
				i++;
			else
				ft_error(5); //add new error?
		}
		j++;
	}
}

void	find_textures(t_cub *cub)
{
	int 	i;
	int		j= 0;
	char 	**str;
	
	str = cub->tmp_file;
	while(j < 6)
	{
		i = 0;
		i = remoove_space(str[j], i);
		if(strncmp("F ", str[j], 2) == 0)
		{
			i = i + 2;
			char **tmp = ft_split(&str[j][i], ',');
			ft_isdigit(tmp);
			cub->F.r = ft_atoi(tmp[0]);
			cub->F.g = ft_atoi(tmp[1]);
			cub->F.b = ft_atoi(tmp[2]);
		}
		else if(strncmp("C ", str[j], 2) == 0)
		{
			i = i + 2;
			char **tmp = ft_split(&str[j][i], ',');
			ft_isdigit(tmp);
			cub->C.r = ft_atoi(tmp[0]);
			cub->C.g = ft_atoi(tmp[1]);
			cub->C.b = ft_atoi(tmp[2]);
		}
		else if(strncmp("NO ", str[j], 3) == 0)
		{ 	
			i = i + 3;
			i =  remoove_space(str[j], i);
			cub->NO = ft_substr(str[j], i, ft_strlen(str[j]) - i);
		}
		else if(strncmp("WE ", str[j], 3) == 0)
		{
			i = i + 3;
			i =  remoove_space(str[j], i);
			cub->WE = ft_substr(str[j], i, ft_strlen(str[j]) - i);
		}
		else if(strncmp("SO ", str[j], 3) == 0)
		{
			i = i + 3;
			i =  remoove_space(str[j], i);
			cub->SO = ft_substr(str[j], i, ft_strlen(str[j]) - i);
		}
		else if(strncmp("EA ", str[j], 3) == 0)
		{
			i = i + 3;
			i =  remoove_space(str[j], i);
			cub->EA = ft_substr(str[j], i, ft_strlen(str[j]) - i);
		}
		j++;
	}
}
int check_color(t_cub *cub)
{
	if (cub->C.r < 0 || cub->C.r > 255 || cub->C.g < 0 ||cub->C.g > 255 || cub->C.b < 0 || cub->C.b > 255)
		return(1);
	if (cub->F.r < 0 || cub->F.r > 255 || cub->F.g < 0 ||cub->F.g > 255 || cub->F.b < 0 || cub->F.b > 255)
		return(1);
	return(0);
}
void	check_file(t_cub *cub, char *str)
{
	if (ft_strncmp(str + ft_strlen(str) - 4, ".cub", 4))
		ft_error(3);
	cub->map_cub = str;
	cub->fd = open(str, O_RDONLY);
	if (cub->fd < 1)
		ft_error(2); ///check error
	cub->tmp = get_next_line(cub->fd);
	while (cub->tmp)
	{
		if (cub->flag == 0)
		{
			cub->get_next = cub->tmp;
			cub->flag = 1;
		}
		else
			cub->get_next = ft_strjoin(cub->get_next, cub->tmp);
		cub->tmp = get_next_line(cub->fd);
	}
	cub->tmp_file = ft_split(cub->get_next, '\n');
	find_textures(cub);
	
	//need check path
	if(cub->EA == NULL || cub->WE == NULL || cub->SO == NULL || cub->NO == NULL)
		ft_error(4); //need this verification?
		
	// check error color
	if (check_color(cub))
		ft_error(5);
	find_map(cub);
}