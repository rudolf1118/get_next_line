/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rharutyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:06:20 by rharutyu          #+#    #+#             */
/*   Updated: 2024/03/07 19:06:21 by rharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_new_line(t_list *list)
{
	int	index;

	if (!list)
		return (0);
	while (list)
	{
		index = 0;
		while (list->buf[index] && index < BUFFER_SIZE)
		{
			if (list->buf[index] == '\n')
				return (1);
			++index;
		}
		list = list->next;
	}
	return (0);
}

void	deletealloc(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*temp;

	if (!(*list))
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free((*list)->buf);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	if (clean_node->buf[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}

t_list	*find_last_node(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	copy_str(t_list *list, char *str)
{
	int	i;
	int	index;

	index = 0;
	if (!list)
		return ;
	while (list)
	{
		i = 0;
		while (list->buf[i])
		{
			if (list->buf[i] == '\n')
			{
				str[index++] = '\n';
				str[index] = '\0';
				return ;
			}
			str[index++] = list->buf[i++];
		}
		list = list->next;
	}
	str[index] = '\0';
}

int	len_to_new_line(t_list *list)
{
	int	index;
	int	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		index = 0;
		while (list->buf[index])
		{
			if (list->buf[index] == '\n')
			{
				len++;
				return (len);
			}
			++len;
			++index;
		}
		list = list->next;
	}
	return (len);
}
