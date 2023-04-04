#include "../cub3d.h"

int	find_map(t_cub *cub)
{
	int j = 6;
	int i = 0;
	char 	**str = cub->tmp_file;
	int len= 0;

	while(str[j])
	{
	 //printf("%s\n", str[j]);
		 j++;
	 	len++;
	 }
	cub->map = malloc(sizeof(char *) * (len + 1));
	j = 6;
	while(str[j])
	{
		cub->map[i] = str[j];//malloc?
		printf("%s\n", cub->map[i]);
		i++;
		j++;
	}
	//check_map(cub->map, len);
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
       // printf("j = %d\n", j);
       printf("len i = %d\n", len_i);
		while(str[j][i] != '\0' )
		{
			if(str[j][i] == ' ')
			 { 
                 printf("test j %d   i = %d\n", j, i);
				if(i > 0)
				{
					if(str[j][i-1] != '1' && str[j][i-1] != ' ')
						printf("error1\n");
				}
			     if (i < (int)ft_strlen(str[j])) //-1?
				{
                  
					if(str[j][i+1] != '1' && str[j][i+1] != ' ')
						printf("error2\n");
				}
				 if (j > 0)
				{
					if(str[j][i-1] != '1' && str[j-1][i] != ' ')
						printf("error3\n");
				}
				 if (j <= len)
				{
					if(str[j][i+1] != '1' && str[j+1][i] != ' ')
						printf("error4\n");
				}
			 }
           //  printf("i = %d\n", i);
			 i++;
		}	
        
		j++;
	}
	return(0);
}