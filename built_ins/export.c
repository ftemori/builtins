#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	**ft_unset(char *v_name, char **env);

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	**export(char *v_name, char *v_value, char **env)
{
	int	i;
	int	k;
	int	m;

	i = 0;
	k = -1;
	m = 0;
	while (env[i] != NULL)
		i++;
	env[i] = malloc(ft_strlen(v_name) + ft_strlen(v_value) + 2);
	while (v_name[++k] != '\0')
		env[i][k] = v_name[k];
	env[i][k] = '=';
	k++;
	while (v_value[m] != '\0')
	{
		env[i][k] = v_value[m];
		k++;
		m++;
	}
	env[i][k] = '\0';
	i++;
	env[i] = NULL;
	return (env);
}

/*int	main(int ac, char **av, char **env)

{
	char	*variable_name = "printing";
	char	*variable_value = "haello world";
	int	i = 15;

	env = export(variable_name, variable_value, env);
	env = export("second", "The longest string in the town baby ;)", env);
	char	*path = "/home/ftemori/Desktop/built_ins/script.sh";
	int	res = system(path);
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	sleep(5);
	i = 15;
	printf("\n\n\n\n");
	env = ft_unset(variable_name, env);
	res = system(path);
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	
	return (0);
}*/