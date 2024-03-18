/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:04:54 by miguelgo          #+#    #+#             */
/*   Updated: 2024/03/14 12:06:51 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

int	ft_is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_trim_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_is_in_set(s1[i], set))
		i++;
	return (i);
}

int	ft_trim_end(char const *s1, char const *set, int len)
{
	int	i;

	i = len - 1;
	while (i >= 0 && ft_is_in_set(s1[i], set))
	{
		i--;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		start;
	int		end;
	int		i;
	char	*rst;

	len = ft_strlen(s1);
	start = ft_trim_start(s1, set);
	end = ft_trim_end(s1, set, len);
	if (start > end)
		end = start;
	rst = (char *)malloc((sizeof(char)) * (end - start + 1));
	if (!rst)
		return (0);
	i = 0;
	while (start < end)
	{
		rst[i] = s1[start];
		i++;
		start++;
	}
	rst[i] = '\0';
	return (rst);
}
/*int	main()
{
  char *trimmed;

    // Prueba 1: Cadena con espacios al principio y al final
    trimmed = ft_strtrim("   holaquetal   ", " ");
    printf("Prueba 1: \"%s\"\n", trimmed);
    free(trimmed);

    // Prueba 2: Cadena sin espacios para recortar
    trimmed = ft_strtrim("holaquetal", "hola");
    printf("Prueba 2: \"%s\"\n", trimmed);
    free(trimmed);

    // Prueba 3: Cadena con caracteres a recortar en ambos extremos
    trimmed = ft_strtrim("xxxyyyholaquetalxxx", "xy");
    printf("Prueba 3: \"%s\"\n", trimmed);
    free(trimmed);

    return 0;
}*/
