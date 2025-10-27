/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:54:20 by jechoi            #+#    #+#             */
/*   Updated: 2025/04/08 13:22:14 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*save;
	t_list	*newlist;
	t_list	*newnode;

	save = lst;
	newlist = NULL;
	while (save)
	{
		newnode = ft_lstnew(f(save->content));
		if (newnode == NULL)
		{
			ft_lstclear(&newlist, del);
			return ((void *)(0));
		}
		ft_lstadd_back(&newlist, newnode);
		save = save->next;
	}
	return (newlist);
}
