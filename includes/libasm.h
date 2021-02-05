/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:31:07 by rledrin           #+#    #+#             */
/*   Updated: 2020/01/23 13:33:14 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *stc);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const char *buf, int len);
ssize_t	ft_read(int fd, void *buf, size_t len);
char	*ft_strdup(char *str);

#endif