/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:57:27 by ceccentr          #+#    #+#             */
/*   Updated: 2020/09/12 17:30:47 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

size_t	   ft_strlen(const char *str);
char       *ft_strcpy(char *dst, const char *src);
int        ft_strcmp(const char *s1, const char *s2);
char       *ft_strdup(const char *s1);
ssize_t    ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t    ft_read(int fildes, void *buf, size_t nbyte);

#endif