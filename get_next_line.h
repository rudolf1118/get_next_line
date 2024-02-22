#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list 
{
    char *buf;
    struct s_list *next                                                                                                          ;
} t_list;








#endif // end of GET_NEXT_LINE