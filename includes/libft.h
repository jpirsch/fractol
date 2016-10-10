/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:35:08 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/09 03:12:02 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# define ABS(x) ((x) < 0 ? -(x) : (x))

void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl(char *s);
void	ft_putnbr(int n);

char	*ft_strcat(char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(char *str);
size_t	ft_strlen(char *s);
char	*ft_strnew(size_t n);
char	*ft_strsub(const char *s, unsigned int start, size_t len);
char	**ft_strsplit(const char *s, char c);
char	*ft_strtrim_char(const char *s, char c);
size_t	ft_strchr_len(const char *s, int c);

int		ft_atoi(char *str);
void	ft_bzero(void *s, size_t n);
size_t	ft_countwords(const char *s, char c);
char	*ft_itoa(int n);
void	*ft_memalloc(size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_tabmalloc(size_t size, size_t len);
#endif
