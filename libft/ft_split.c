/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:02:06 by miguelgo          #+#    #+#             */
/*   Updated: 2024/03/18 19:47:24 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

static void	ft_free(char **res)
{
	int	i;

	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			word++;
		i++;
	}
	return (word);
}

static char	**write_result(char const *s, char c, char **res)
{
	size_t	start;
	size_t	i;
	size_t	word;

	start = 0;
	i = 0;
	word = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
		{
			res[word] = ft_substr(s, start, i - start + 1);
			if (!res[word])
			{
				ft_free(res);
				return (0);
			}
			word++;
		}
		if (s[i] == c && (s[i + 1] != c || s[i + 1] != '\0'))
			start = i + 1;
		i++;
	}
	res[word] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**res;

	i = 0;
	if (!s)
		return (0);
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (0);
	res = write_result(s, c, res);
	return (res);
}
/*int main(void)
{
	char const *input_string = "wwwwwwholawwwwwquewwwwtalwwww";
	char delimiter = 'w';

	char **result = ft_split(input_string, delimiter);

	if (result)
	{
		int i = 0;
		while (result[i])
		{
			printf("Word %d: %s\n", i + 1, result[i]);
			free(result[i]);
			i++;
		}
		free(result);
	}
	else
	{
		printf("Error: Memory allocation failed.\n");
	}

	return 0;
}*/
