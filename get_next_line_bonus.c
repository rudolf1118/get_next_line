#include "get_next_line_bonus.h"

void polish_list(t_list **list)
{
    t_list *last_node;
    t_list *clean_node;
    char *buf;
    int i;
    int k;


    buf = malloc(BUFFER_SIZE + 1);
    clean_node = malloc (sizeof(t_list));
    if (!buf || !clean_node)
        return ;
    last_node = find_last_node(*list);
    i = 0;
    k = 0;
    while (last_node->buf[i] && last_node->buf[i] != '\n')
        ++i;
    /*
     maybe our file don't have '\n'-s, only '\0'-s.
     */
    while (last_node->buf[i] != '\0' && last_node->buf[++i] != '\0')
        buf[k++] = last_node->buf[i];
    buf[k] = '\0';
    clean_node->buf = buf;
    clean_node -> next = NULL;
    deletealloc(list,clean_node, buf);
}

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

void append (t_list **list, char *buf, int fd)
{
    t_list *new_node;
    t_list *last_node;

    last_node = find_last_node(list[fd]);
    new_node = malloc (sizeof(t_list));
    if (!new_node)
        return ;
    if (!last_node)
        list[fd] = new_node;
    else
        last_node->next = new_node;
    new_node->buf = buf;
    new_node->next = NULL;
}

void create_list(t_list **list, int fd)
{
    int read_char;
    char *buf;

    while (!found_new_line(list[fd]))
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
        append(list, buf, fd);
    }
}

char *get_next_line(int fd)
{
    static t_list *list[4096];
    char *next_line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (read(fd, &next_line, 0) < 0)
    {
        deletealloc(&list[fd], NULL, NULL);
        return (NULL);
    }
    create_list(list, fd);
    if (!(list[fd]))
        return (NULL);
    next_line = get_line(list[fd]);
    polish_list(&list[fd]);
    return (next_line);
}
/*
#include <stdio.h>

int main ()
{
    int fd;
    char *line;
    int lines;
    lines = 1;
    fd = open("text.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%d next -> %s \n", lines++, line);
    }
}
 */