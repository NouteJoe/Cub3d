#include "../cub3d.h"

int	find_map(t_cub *cub)
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
		cub->map[i] = malloc(sizeof(char) * ft_strlen(str[j]+1));//malloc?
		cub->map[i] = str[j];
		size_j = ft_strlen(str[j]);
		cub->map[i][size_j+1]= '\0';
		///print la map
		//printf("%s\n", cub->map[i]);	
		i++;
		j++;
	}
	cub->map[i] = NULL;
	check_map(cub->map, len);
	return(0);
}

int	check_map(char **str, int len)
{
	int i = 0;
	int j = 0;
    int len_i;

	while(j < len)
	{
		i = 0;
        len_i =(int) ft_strlen(str[j]);
		while(str[j][i] != '\0' )
		{
			if(str[j][i] == '0')
			 { 
				if(i > 0)
				{
					if(str[j][i-1] != '1' && str[j][i-1] != 'N' && str[j][i-1] != '0')
						printf("error1\n");
				}
			     if (i < len_i)
				{
					if(str[j][i+1] != '1' && str[j][i+1] != 'N'&& str[j][i+1] != '0')
						printf("error2\n");
				}
				 if (j > 0)
				{
					if(str[j-1][i] != '1' && str[j-1][i] != 'N' && str[j-1][i] != '0')
						printf("error3\n");
				}
				 if (j < len-1)
				{
					if(str[j+1][i] != '1' && str[j+1][i] != 'N'&& str[j+1][i] != '0')
						printf("error4\n");
				}
				if (j > 0 && i > 0)
				{
					if (str[j-1][i-1] != '1' && str[j-1][i-1] != 'N' && str[j-1][i-1] != '0')
						printf("error5\n");
				}
				if (j > 0 && i < len_i)
				{
					if (str[j-1][i+1] != '1' && str[j-1][i+1] != 'N' && str[j-1][i+1] != '0')
						printf("error6\n");
				}
				if (j < len - 1 && i > 0)
				{
					if (str[j+1][i-1] != '1' && str[j+1][i-1] != 'N' && str[j+1][i-1] != '0')
						printf("error7\n");
				}
				if (j < len - 1 && i < len_i)
				{
					if (str[j+1][i+1] != '1' && str[j+1][i+1] != 'N'&& str[j+1][i+1] != '0')
						printf("error8\n");
				}
			 }
			 i++;
		}	
		j++;
	}
	return(0);
}