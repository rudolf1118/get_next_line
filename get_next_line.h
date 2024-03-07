/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rharutyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:02:18 by rharutyu          #+#    #+#             */
/*   Updated: 2024/03/07 19:02:20 by rharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*buf;
	struct s_list	*next;
}					t_list;

void				create_list(t_list **list, int fd);
void				append(t_list **list, char *buf);
void				polish_list(t_list **list);
char				*get_line(t_list *list);
void				deletealloc(t_list **list, t_list *clean_node, char *buf);
int					len_to_new_line(t_list *list);
void				copy_str(t_list *list, char *buf);
t_list				*find_last_node(t_list *list);
int					found_new_line(t_list *list);
char				*get_next_line(int fd);
#endif
