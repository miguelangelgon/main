/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:56:16 by miguelgo          #+#    #+#             */
/*   Updated: 2024/03/12 20:07:51 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*a;
	const unsigned char	*b;

	if (dst < src)
		return (ft_memcpy(dst, src, len));
	a = (unsigned char *)dst;
	b = (const unsigned char *)src;
	if (dst == src || !len)
		return (dst);
	while (len--)
	{
		a[len] = b[len];
	}
	return (dst);
}
