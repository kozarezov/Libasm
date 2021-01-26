/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 11:25:36 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/09/12 17:56:46 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <string.h>
#include <errno.h>
#include <fcntl.h>

void test_strlen()
{
	printf("\033[0;32m\n=== ft_strlen === \n\033[0m");
	printf("\n");
	printf("M: Vide => %zu\n", ft_strlen(""));
	printf("R: Vide => %zu\n", strlen(""));
	printf("M: Normal => %zu\n", ft_strlen("Hello"));
	printf("R: Normal => %zu\n", strlen("Hello"));
	printf("M: Long => %zu\n", ft_strlen("Hello world; test1; test2; test3; test4; test5\n"));
	printf("R: Long => %zu\n", strlen("Hello world; test1; test2; test3; test4; test5\n"));
}

void test_strcmp()
{
	printf("\033[0;32m\n=== ft_strcmp === \n\033[0m");
	printf("\n");
	printf("Vide, Vide => %d\n", ft_strcmp("", ""));
    printf("Vide, Vide => %d\n", strcmp("", ""));
	printf("Normal, Vide => %d\n", ft_strcmp("Hello", ""));
    printf("Normal, Vide => %d\n", strcmp("Hello", ""));
	printf("Vide, Normal => %d\n", ft_strcmp("", "World"));
    printf("Vide, Normal => %d\n", strcmp("", "World"));
	printf("Normal, Normal: same => %d\n", ft_strcmp("Hello", "Hello"));
    printf("Normal, Normal: same => %d\n", strcmp("Hello", "Hello"));
	printf("Normal, Normal: diff => %d\n", ft_strcmp("Hello", "Hel"));
    printf("Normal, Normal: diff => %d\n", strcmp("Hello", "Hel"));
	printf("Normal, Normal: diff => %d\n", ft_strcmp("Hel", "Hello"));
    printf("Normal, Normal: diff => %d\n", strcmp("Hel", "Hello"));
}

void test_strcpy()
{
	char dest[100];
	printf("\033[0;32m\n=== ft_strcpy ===\n\033[0m");
	printf("\n");
	printf("Vide => %s\n", ft_strcpy(dest, ""));
    printf("Vide => %s\n", strcpy(dest, ""));
	printf("Normal => %s\n", ft_strcpy(dest, "Hello"));
    printf("Normal => %s\n", strcpy(dest, "Hello"));
	printf("Long => %s\n", ft_strcpy(dest, "Hello world; test1; test2; test3; test4; test5"));
    printf("Long => %s\n", strcpy(dest, "Hello world; test1; test2; test3; test4; test5"));
}

void test_strdup()
{
	printf("\033[0;32m\n=== ft_strdup ===\n\033[0m");
	printf("\n");
	printf("Vide => %s\n", ft_strdup(""));
    printf("Vide => %s\n", strdup(""));
	printf("Normal => %s\n", ft_strdup("Hello"));
    printf("Normal => %s\n", strdup("Hello"));
	printf("Long => %s\n", ft_strdup("Hello world; test1; test2; test3; test4; test5"));
    printf("Long => %s\n", strdup("Hello world; test1; test2; test3; test4; test5"));
}

void test_write()
{
	int fd;
	char *str = "Hello world\n";

	printf("\033[0;32m\n=== ft_write ===\n\033[0m");
	printf("\n");
	ft_write(1, str, 12);
	write(1, str, 12);

	ft_write(1, &"", 1);
    write(1, &"", 1);
	ft_write(1, &"\n", 1);
	write(1, &"\n", 1);

	fd = open("write.txt", O_CREAT | O_APPEND | O_WRONLY, S_IRUSR | S_IWUSR);
	ft_write(fd, str, 12);
	write(fd, str, 12);
	close(fd);

	errno = 0;
	ft_write(-1, str, 12);
	printf("errno => %d\n", errno);

	errno = 0;
	write(-1, str, 12);
	printf("errno => %d\n", errno);
	
	fd = open("write.txt", O_WRONLY);
	ft_write(fd, str, 12);
	write(fd, str, 12);
	printf("fd => %d\n", fd);
	close(fd);
}

void test_read()
{
	int	fd;
	int ret;
	char *buf;

	printf("\033[0;32m\n=== ft_read ===\n\033[0m");
	printf("\n");

	errno = 0;
	fd = open("read.txt", O_RDONLY);
	buf = calloc(100, sizeof(char));
	ret = read(fd, buf, 50);
	buf[50] = '\0';
	printf("fd => %d\nret => %d\nbuf => %s\nerrno => %d\n\n", fd, ret, buf, errno);
	free(buf);
	close(fd);

	errno = 0;
	fd = open("read.txt", O_RDONLY);
	buf = calloc(100, sizeof(char));
	ret = ft_read(fd, buf, 50);
	buf[50] = '\0';
	printf("fd => %d\nret => %d\nbuf => %s\nerrno => %d\n\n", fd, ret, buf, errno);
	free(buf);
	close(fd);

	errno = 0;
	buf = calloc(100, sizeof(char));
	ret = read(-1, buf, 50);
	buf[50] = '\0';
	printf("fd => %d\nret => %d\nbuf => %s\nerrno => %d\n\n", -1, ret, buf, errno);
	free(buf);

	errno = 0;
	buf = calloc(100, sizeof(char));
	ret = ft_read(-1, buf, 50);
	buf[50] = '\0';
	printf("fd => %d\nret => %d\nbuf => %s\nerrno => %d\n\n", -1, ret, buf, errno);
	free(buf);
}

int main()
{
	printf("\n");
	printf("\033[0;34m===== TEST LIBASM =====\n\033[0m");
	printf("\n");

	test_strlen();
	test_strcmp();
	test_strcpy();
	test_strdup();
	test_read();
	test_write();
	return (0);
}
