/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:39:09 by dolewski          #+#    #+#             */
/*   Updated: 2015/11/25 09:39:20 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (s1[i])
	{
		if (s1[i] == s2[j])
		{
			tmp = ((char *)s1) + i;
			while (s1[i + j] == s2[j])
			{
				if (s2[j + 1] == '\0')
					return (tmp);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
