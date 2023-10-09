#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_free(char **str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *str, int c);
int		ft_strlen(const char *str);

#endif
