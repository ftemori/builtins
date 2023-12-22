#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *s);
int	ft_strcmp(char *s1, char *s2);

int	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
	return (0);
}

int	ft_echo(char **av)
{
	int	i = 1;
	char	c = 'y';
	if (ft_strcmp("-n", av[1]) == 0)
	{
		i = 2;
		c = 'n';
	}
	while (av[i] != NULL)
	{
		ft_putstr(av[i]);
		if (av[i + 1] != NULL)
			write(1, " ", 1);
		if (av[i + 1] == NULL && c == 'y')
			write(1, "\n", 1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		write(1, "\n", 1);
	else
		ft_echo(av);
	return (0);
}