/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:15:47 by miguelgo          #+#    #+#             */
/*   Updated: 2024/03/15 18:33:17 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*clear;
	t_list	*next_node;

	clear = *lst;
	if (*lst && lst)
	{
		while (clear)
		{
			next_node = clear->next;
			del(clear->content);
			free(clear);
			clear = next_node;
		}
	}
	*lst = NULL;
}
