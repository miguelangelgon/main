/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:22:12 by miguelgo          #+#    #+#             */
/*   Updated: 2024/03/14 15:35:25 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*rst;

	i = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	rst = malloc(sizeof(char) * (len + 1));
	if (!rst)
		return (0);
	while (i < len)
	{
		rst[i] = f(i, s[i]);
		i++;
	}
	rst[len] = '\0';
	return (rst);
}
