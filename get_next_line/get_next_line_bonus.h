#ifndef "GET_NEXT_LINE__BONUS_H"
# define "GET_NEXT_LINE_BONUS_H"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE = 10

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

char    *ft_free(char **str);
char    *clean_buffer(char *storage);
char    *new_line(char *storage);
char    *read_buffer(int fd, char *storage);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(const char *str);

#endif
