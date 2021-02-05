#include "includes/libasm.h"

static void		test_ft_strlen()
{
	printf("TEST FT_STRLEN :\n");
	printf("	[1] \"\"\n");
	printf("		<string.h>  =  %lu\n", strlen(""));
	printf("		<libasm.h>  =  %lu\n\n", ft_strlen(""));
	printf("	[2] \"    \"\n");
	printf("		<string.h>  =  %lu\n", strlen("    "));
	printf("		<libasm.h>  =  %lu\n\n", ft_strlen("    "));
	printf("	[3] \"0123456789\"\n");
	printf("		<string.h>  =  %lu\n", strlen("0123456789"));
	printf("		<libasm.h>  =  %lu\n\n", ft_strlen("0123456789"));
}

static void		test_ft_strcpy()
{
	char	dst[300];
	char	dst2[300];

	printf("TEST FT_STRCPY :\n");
	printf("	[1] \"0123456789\"\n");
	printf("		<string.h>  =  \"%s\"\n", strcpy(dst, "0123456789"));
	printf("		<libasm.h>  =  \"%s\"\n\n", ft_strcpy(dst, "0123456789"));
	memset(dst, 0, 300);
	memset(dst2, 0, 300);
	printf("	[2] \"\"\n");
	printf("		<string.h>  =  \"%s\"\n", strcpy(dst, ""));
	printf("		<libasm.h>  =  \"%s\"\n\n", ft_strcpy(dst, ""));
	memset(dst, 0, 300);
	memset(dst2, 0, 300);
	printf("	[3] \"    \"\n");
	printf("		<string.h>  =  \"%s\"\n", strcpy(dst, "    "));
	printf("		<libasm.h>  =  \"%s\"\n\n", ft_strcpy(dst, "    "));
}

static void		test_ft_strcmp()
{
	printf("TEST FT_STRCMP :\n");
	printf("	[1] \"0123456789\" \"0123456789\"\n");
	printf("		<string.h>  =  %d\n", strcmp("0123456789", "0123456789"));
	printf("		<libasm.h>  =  %d\n\n", ft_strcmp("0123456789", "0123456789"));
	printf("	[2] \"01234\" \"01236\"\n");
	printf("		<string.h>  =  %d\n", strcmp("01234", "01236"));
	printf("		<libasm.h>  =  %d\n\n", ft_strcmp("01234", "01236"));
	printf("	[3] \"01236\" \"01234\"\n");
	printf("		<string.h>  =  %d\n", strcmp("01236", "01234"));
	printf("		<libasm.h>  =  %d\n\n", ft_strcmp("01236", "01234"));
}

static void		test_ft_write()
{
	printf("TEST FT_WRITE :\n");
	printf("	[1] \"0123456789\"\n");
	write(1, "		<unistd.h>  =  ", 17);
	write(1, "0123456789", 10);
	printf("\n");
	write(1, "		<libasm.h>  =  ", 17);
	ft_write(1, "0123456789", 10);
	printf("\n");
	printf("	[2] \"    \"\n");
	write(1, "		<unistd.h>  =  \"", 19);
	write(1, "    ", 4);
	printf("\"\n");
	write(1, "		<libasm.h>  =  \"", 19);
	ft_write(1, "    ", 4);
	printf("\"\n");
	printf("\n");
	// printf("		<unistd.h>  =  ", strlen("    "));
	// printf("		<libasm.h>  =  ", ft_strlen("    "));
	// printf("	[3] \"0123456789\"\n");
	// printf("		<unistd.h>  =  ", strlen("0123456789"));
	// printf("		<libasm.h>  =  ", ft_strlen("0123456789"));
}

static void		test_ft_read()
{
int			fd;
	char		buffer[500];
	char		show[500];
	ssize_t		ret;

	memset(show, 0, 100);
	memset(buffer, 0, 100);
	printf("TEST FT_READ :\n");
	printf("	[1] open(\"main.c\", O_RDONLY)\n");
	fd = open("testlib.c", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		<unistd.h>  =  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("testlib.c", O_RDONLY);
	ret = ft_read(fd, buffer, 10);
	printf("		<libasm.h>  =  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	memset(show, 0, 100);
	memset(buffer, 0, 100);
	printf("	[2] open(\"Makefile\", O_RDONLY)' '' '50'\n");
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, buffer, 50);
	printf("		<unistd.h>  =  %zd - %s\n", ret, strncpy(show, buffer, 50));
	close(fd);
	fd = open("Makefile", O_RDONLY);
	ret = ft_read(fd, buffer, 50);
	printf("		<libasm.h>  =  %zd - %s\n", ret, strncpy(show, buffer, 50));
	close(fd);
	memset(show, 0, 100);
	memset(buffer, 0, 100);
	printf("	[3] open(\"dontexist\", O_RDONLY)' '' '10'\n");
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		<unistd.h>  =  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = ft_read(fd, buffer, 10);
	printf("		<libasm.h>  =  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	memset(show, 0, 100);
	memset(buffer, 0, 100);
	printf("	[4] open(\"testlib.c\", O_RDONLY)' 'NULL' '10'\n");
	fd = open("testlib.c", O_RDONLY);
	ret = read(fd, NULL, 10);
	printf("		<unistd.h>  =  %zd\n", ret);
	close(fd);
	fd = open("testlib.c", O_RDONLY);
	ret = ft_read(fd, NULL, 10);
	printf("		<libasm.h>  =  %zd\n", ret);
	close(fd);
	memset(show, 0, 100);
	memset(buffer, 0, 100);
	printf("	[5] 42, \"\", 10'\n");
	ret = read(42, buffer, 10);
	printf("		<unistd.h>  =  %zd - %s\n", ret, strncpy(show, buffer, 10));
	ret = ft_read(42, buffer, 10);
	printf("		<libasm.h>  =  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	memset(show, 0, 100);
	memset(buffer, 0, 100);
	fd = open("empty_file", O_RDONLY | O_TRUNC | O_CREAT, 0777);
	printf("	[6] open(\"empty_file\", O_RDONLY | O_TRUNC | O_CREAT, 0777)' '' '10'\n");
	ret = read(fd, buffer, 10);
	printf("		<unistd.h>  =  %zd - %s\n", ret, strncpy(show, buffer, 10));
	ret = ft_read(fd, buffer, 10);
	printf("		<libasm.h>  =  %zd - %s\n\n", ret, strncpy(show, buffer, 10));
	close(fd);
	remove("empty_file");
}

static void		test_ft_strdup()
{
	printf("TEST FT_STRDUP :\n");
	printf("	[1] \"\"\n");
	printf("		<string.h>  =  \"%s\"\n", strdup(""));
	printf("		<libasm.h>  =  \"%s\"\n", ft_strdup(""));
	printf("	[2] \"    \"\n");
	printf("		<string.h>  =  \"%s\"\n", strdup("    "));
	printf("		<libasm.h>  =  \"%s\"\n", ft_strdup("    "));
	printf("	[3] \"0123456789\"\n");
	printf("		<string.h>  =  \"%s\"\n", strdup("0123456789"));
	printf("		<libasm.h>  =  \"%s\"\n\n", ft_strdup("0123456789"));
}

int			main(int argc, char *argv[])
{
	if (argc == 1 || !strcmp(argv[1], "ft_strlen"))
		test_ft_strlen();
	if (argc == 1 || !strcmp(argv[1], "ft_strcpy"))
		test_ft_strcpy();
	if (argc == 1 || !strcmp(argv[1], "ft_strcmp"))
		test_ft_strcmp();
	if (argc == 1 || !strcmp(argv[1], "ft_write"))
		test_ft_write();
	if (argc == 1 || !strcmp(argv[1], "ft_read"))
		test_ft_read();
	if (argc == 1 || !strcmp(argv[1], "ft_strdup"))
		test_ft_strdup();
	return (0);
}
