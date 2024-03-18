/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:51:18 by miguelgo          #+#    #+#             */
/*   Updated: 2024/03/16 16:30:18 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*a;
	unsigned int	i;

	if (!s || start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (a == '\0')
		return (0);
	i = 0;
	while (len--)
	{
		a[i] = s[i + start];
		i++;
	}
	a[i] = '\0';
	return (a);
}

/*int	main()
{
	printf("%s", ft_substr("holiquetal", 3, 4));
	return 0;
}*/
