/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 04:31:15 by troberts          #+#    #+#             */
/*   Updated: 2022/04/21 22:50:24 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		(*del)((*lst)->content);
		ft_memdel((void **)lst);
		*lst = ptr;
	}
	*lst = NULL;
}
