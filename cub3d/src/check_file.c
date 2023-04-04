#include "../cub3d.h"

int remoove_space( char *str, int i)
{
	while(str[i] == ' ')
		i++;
	return(i);
}

int	find_textures(t_cub *cub)
{
	int 	i;
	int		j= 0;
	char 	**str = cub->tmp_file;

	while(j < 6)
	{
		i = 0;
		i = remoove_space(str[j], i);
		if(strncmp("F ", str[j], 2) == 0)
		{
			i = i + 2;
			char **tmp = ft_split(&str[j][i], ',');
			cub->F.r = ft_atoi(tmp[0]);
			cub->F.g = ft_atoi(tmp[1]);
			cub->F.b = ft_atoi(tmp[2]);
		//	printf("F r = %hhu\n",cub->F.r);
		//	printf("F g = %hhu\n",cub->F.g);
		//	printf("F b = %hhu\n",cub->F.b);
		}
		else if(strncmp("C ", str[j], 2) == 0)
		{
			i = i + 2;
			char **tmp = ft_split(&str[j][i], ',');
			cub->F.r = ft_atoi(tmp[0]);
			cub->F.g = ft_atoi(tmp[1]);
			cub->F.b = ft_atoi(tmp[2]);
		//	printf("C r = %hhu\n",cub->F.r);
		//	printf("C g = %hhu\n",cub->F.g);
		//	printf("C b = %hhu\n",cub->F.b);
		}
		else if(strncmp("NO ", str[j], 3) == 0)
		{ 	
			i = i + 3;
			i =  remoove_space(str[j], i);
			cub->NO =	ft_substr(str[j], i, ft_strlen(str[j]) - i);
			//printf("NO ----%s \n", cub->NO);
		}
		else if(strncmp("WE ", str[j], 3) == 0)
		{
			i = i + 3;
			i =  remoove_space(str[j], i);
			cub->WE =	ft_substr(str[j], i, ft_strlen(str[j]) - i);
			//printf("WE ----%s \n", cub->WE);
		}
		else if(strncmp("SO ", str[j], 3) == 0)
		{
			i = i + 3;
			i =  remoove_space(str[j], i);
			cub->SO =	ft_substr(str[j], i, ft_strlen(str[j]) - i);
			//printf("SO ----%s \n", cub->SO);
		}
		else if(strncmp("EA ", str[j], 3) == 0)
		{
			i = i + 3;
			i =  remoove_space(str[j], i);
			cub->EA =	ft_substr(str[j], i, ft_strlen(str[j]) - i);
		//	printf("EA ----%s \n", cub->EA);
		}
		else
			printf("test\n");
		j++;
	}
return(0);
}

int	check_file(t_cub *cub, char *str)
{
	if (ft_strncmp(str + ft_strlen(str) - 4, ".cub", 4))
		ft_error(3);
	cub->map_cub = str;//av[1]  necessaire?
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

	// verification  du split
	/*int i = 0;
	while(cub->tmp_file[i])
	{
	 printf("%s\n", cub->tmp_file[i]);
	 i++;
	 }*/
	//remplir les donner quand aucunes est a NULL, le reste est la carte
	find_textures(cub);//add error
	find_map(cub);
	
	return (1);
}