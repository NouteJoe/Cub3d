#include "../cub3d.h"

void	find_map(t_cub *cub)
{
	int 	j;
	int 	i;
	char 	**str;
	int 	len;
	int 	size_j;

	str = cub->tmp_file;
	len = 0;
	while(str[len+6])
	 	len++;
	cub->map = malloc(sizeof(char *)* (len + 1));
	j = 6;
	i = 0;
	size_j = 0;
	while(str[j])
	{
		cub->map[i] = malloc(sizeof(char) * ft_strlen(str[j] + 1));
		cub->map[i] = str[j];
		size_j = ft_strlen(str[j]);
		cub->map[i][size_j + 1]= '\0';	
		i++;
		j++;
	}
	cub->map[i] = NULL;
	check_map(cub->map, len);
}

void	check_map(char **str, int len)
{
	int i;
	int j;
    int len_i;

	j = 0;
	while(j < len)
	{
		i = 0;
        len_i =(int) ft_strlen(str[j]);
		while(str[j][i])
		{
			if(str[j][i] == '0')
			 { 
				check_map2(str, j, i , len_i);
				if (j < len-1)
				{
					if(str[j+1][i] != '1' && str[j+1][i] != 'N'&& str[j+1][i] != '0')
						ft_error(6);
				}
				if (j < len - 1 && i > 0)
				{
					if (str[j+1][i-1] != '1' && str[j+1][i-1] != 'N' && str[j+1][i-1] != '0')
						ft_error(6);
				}
				if (j < len - 1 && i < len_i)
				{
					if (str[j+1][i+1] != '1' && str[j+1][i+1] != 'N'&& str[j+1][i+1] != '0')
						ft_error(6);
				}
			 }
			 i++;
		}	
		j++;
	}
}
void	check_map2(char **str, int j, int i, int len_i)
{
	if(i > 0)
	{
		if(str[j][i-1] != '1' && str[j][i-1] != 'N' && str[j][i-1] != '0')
			ft_error(6);
	}
	if (i < len_i)
	{
		if(str[j][i+1] != '1' && str[j][i+1] != 'N'&& str[j][i+1] != '0')
			ft_error(6);
	}
	 if (j > 0)
	{
		if(str[j-1][i] != '1' && str[j-1][i] != 'N' && str[j-1][i] != '0')
			ft_error(6);
	}
	if (j > 0 && i > 0)
	{
		if (str[j-1][i-1] != '1' && str[j-1][i-1] != 'N' && str[j-1][i-1] != '0')
			ft_error(6);
	}
	if (j > 0 && i < len_i)
	{
		if (str[j-1][i+1] != '1' && str[j-1][i+1] != 'N' && str[j-1][i+1] != '0')
			ft_error(6);
	}
}