#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2);

int	last_variable(char **env)
{
	int	i = i;
	while (env[i + 1] != NULL)
		i++;
	return (i);
}

char	**ft_unset(char *v_name, char **env)
{
	int	i = 0, lv;
	while (env[i] != NULL)	// if the variable does not exist in env, and it goes to NULL?
	{
		if (ft_strcmp(v_name, env[i]) == 0)
		{
			if (env[i + 1] == NULL)
			{
				fprintf(stderr, "\nfirst if\n");
				env[i] = NULL;
				return (env);
			}
			else
			{
				lv = last_variable(env);
				env[i] = env[lv];
				env[lv] = NULL;
				return (env);
			}
		}
		i++;
	}
	return (NULL);
}

/*int	mian(int ac, char **av, char **env)
{
	int	i = 0;
	char	*v_name = "variable";
	ft_unset(v_name, env);
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}*/