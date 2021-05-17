/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 10:45:08 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/05/15 13:27:47 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdint.h>

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *b, const char *l, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int64_t n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *));

int		ft_lstinsert(t_list **lst, t_list *new, unsigned int i);

void	*ft_malloc(size_t size);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isspace(int c);
int		ft_isxdigit(int c);
int		ft_ispunct(int c);
int		ft_isgraph(int c);
int		ft_iscntrl(int c);
uint8_t	ft_nbrlen(int64_t nbr, uint32_t base);
uint8_t	ft_nbrlen_u(int64_t nbr, uint32_t base);
char	*ft_itoa_base(int64_t nbr, char *basechars);
char	*ft_itoa_basei(int64_t nbr, uint8_t base, int cap);
char	*ft_utoa(uint64_t nbr);
char	*ft_utoa_base(uint64_t nbr, char *basechars);
char	*ft_utoa_basei(uint64_t nbr, uint8_t base, int cap);
int		ft_putnbr_base(long long nbr, char *basechars);
char	*ft_strtolower(char *str);
char	*ft_strtoupper(char *str);
void	*ft_memdup(const void *ptr, size_t size);
double	ft_atod(const char *str);

typedef struct s_tree
{
	void			*content;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

t_tree	*ft_treenew(void *content, t_tree *left, t_tree *right);

int		get_next_line(int fd, char **line);

#endif
