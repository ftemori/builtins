#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	pwd(void)
{
	char	path[1024];
	char	*newpath;
	if (getcwd(path, sizeof(path)) == NULL)
	{
		// if you want to add an error message
		return (-1);
	}
	write(1, path, ft_strlen(path));		// ft_putstr.c
	return (0);
}

/*int	main(void)
{
	pwd();
	return (0);
}*/