/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:18:23 by dolewski          #+#    #+#             */
/*   Updated: 2015/11/29 15:28:40 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	j = 0;
	new = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
		if (new != NULL)
		{
			while (s1[++i])
				new[i] = s1[i];
			while (s2[j])
			{
				new[i + j] = s2[j];
				j++;
			}
			new[i + j] = '\0';
		}
	}
	return (new);
}
