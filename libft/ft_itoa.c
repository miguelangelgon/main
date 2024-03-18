/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:37:51 by miguelgo          #+#    #+#             */
/*   Updated: 2024/03/14 15:18:01 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

int	ft_num_len(int n)
{
	int		len;
	long	k;

	len = 0;
	k = n;
	if (k < 0)
	{
		len++;
		k = -k;
	}
	while (k > 9)
	{
		len++;
		k = k / 10;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	long	k;
	char	*num;

	k = n;
	len = ft_num_len(k);
	num = (char *)malloc((sizeof (char)) * (len + 1));
	if (!num)
		return (0);
	i = len - 1;
	if (k < 0)
	{
		num[0] = '-';
		k = -k;
	}
	while (k > 9)
	{
		num[i] = k % 10 + '0';
		k = k / 10;
		i--;
	}
	num[i] = k + '0';
	num[len] = '\0';
	return (num);
}
/*int	main()
{
	printf("%s", ft_itoa(-2147483648));
	return 0;
}*/
