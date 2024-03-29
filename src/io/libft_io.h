/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_io.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/27 14:57:31 by mvan-wij      #+#    #+#                 */
/*   Updated: 2022/04/06 12:57:03 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_IO_H
# define LIBFT_IO_H

# include <unistd.h>

ssize_t	ft_putchar_fd(char c, int fd);
ssize_t	ft_putendl_fd(char *s, int fd);
ssize_t	ft_putnbr_base_len_fd(long long nbr, char *basechars, int base, int fd);
ssize_t	ft_putnbr_base_fd(long long nbr, char *basechars, int fd);
ssize_t	ft_putnbr_fd(int n, int fd);
ssize_t	ft_putstr_fd(char *s, int fd);

#endif
