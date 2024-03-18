/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:39:31 by miguelgo          #+#    #+#             */
/*   Updated: 2024/03/15 18:20:28 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s1 && !s2)
		return (NULL);
	join = (char *)malloc((sizeof(*s1)
				* ((ft_strlen(s1)) + ft_strlen(s2) + 1)));
	if (!join)
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		join[i] = s2[k];
		i++;
		k++;
	}
	join[i] = '\0';
	return (join);
}
/*int	main()
{
printf("%s", *ft_strjoin("hola", "mundo"));
return 0;
}*/
