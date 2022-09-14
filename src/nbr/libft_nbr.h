/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_nbr.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/27 14:51:23 by mvan-wij      #+#    #+#                 */
/*   Updated: 2022/04/11 13:44:01 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_NBR_H
# define LIBFT_NBR_H

# include <stdint.h>
# include <stdbool.h>

bool		ft_atod_strict(char *str, double *result_ptr);
double		ft_atod(char *str);
bool		ft_atodl_strict(char *str, long double *result_ptr);
long double	ft_atodl(char *str);
bool		ft_atoi_strict(char *str, int *result_ptr, bool *had_overflow);
int			ft_atoi(const char *str, bool *had_overflow);
bool		ft_atoll_strict(char *str, long long *result_p, bool *had_overflow);
long long	ft_atoll(const char *str, bool *had_overflow);
int			ft_get_digit(int num, int pos, int base);
char		*ft_itoa_base(int64_t nbr, char *basechars);
char		*ft_itoa_basei(int64_t nbr, uint8_t base, int cap);
char		*ft_itoa(int64_t nbr);
uint8_t		ft_nbrlen_u(uint64_t nbr, uint64_t base);
uint8_t		ft_nbrlen(int64_t nbr, uint32_t base);
int			ft_set_digit(int num, int pos, int new_digit, int base);
char		*ft_utoa_base(uint64_t nbr, char *basechars);
char		*ft_utoa_basei(uint64_t nbr, uint8_t base, int cap);
char		*ft_utoa(uint64_t nbr);

#endif
