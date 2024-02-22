#include "get_next_line.h"

char *get_line (t_list *list)
{
    int length;
    char *next_str;

    if (!list)
        return (NULL);
    length = len_to_new_line(list);
    next_str = malloc(length + 1);
    if (!next_str)
        return (NULL);
    copy_str(list, next_str);
    return (next_str);
}

void append (t_list **list, char *buf)
{
    t_list *new_node;
    t_list *last_node;

    last_node = find_last_node(*list);
}

void create_list(t_list **list, int fd)
{
    int read_char;
    char *buf;

    while (!found_newline(*list))
    {
        buf = malloc(BUFFER_SIZE + 1);
        if (!buf)
            return ;
        read_char = read(fd, buf, BUFFER_SIZE);
        if (!read_char)
        {
            free(buf);
            return ;
        }
        buf[read_char] = '\0';
        append(list, buf);
    }
}

char *get_next_line (int fd)
{
    static t_list *list;
    char *next_line;

    list = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
        return (NULL);
    create_list(&list, fd);
        if (!list)
            return (NULL);
    next_line = get_line(list);
}