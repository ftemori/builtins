#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *s);

int	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	return (0);
}

int	ft_env(char **env)
{
	int	i = 0;
	while (env[i] != NULL)
	{
		if (ft_putstr(env[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	if (ft_env(env) == -1)
		return (-1);
	return (0);
}