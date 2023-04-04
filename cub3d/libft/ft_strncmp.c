/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:47:22 by gmarzull          #+#    #+#             */
/*   Updated: 2023/03/06 15:51:06 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const char	*t1;
	const char	*t2;
	size_t		i;

	t1 = s1;
	t2 = s2;
	i = 0;
	if (n == 0)
		return (0);
	n -= 1;
	while (t1[i] && t2[i] && t1[i] == t2[i] && i < n)
		i++;
	return (((unsigned char)t1[i] - (unsigned char)t2[i]));
}
