#include "get_next_line.h"

int found_newline(t_list *list)
{
    int index;

    if (!list)
        return (0);
	while (list)
	{
		index = 0;
		while (list -> buf[index] && index < BUFFER_SIZE)
		{
			if (list -> buf[index] == '\n')
				return (1);
			index++;
		}
		list = list -> next;
	}
}

t_list *find_last_node(t_list *list)
{
	if (!list)
		return (NULL);
	while (list -> next)
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
			str[index] = list->buf[i];
			index++;
			i++;
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
		return (NULL);
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
			len++;
			index++;
		}
		list = list->next;
	}
	return (len);
}
