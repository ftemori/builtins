#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct	s_data
{
	int	word_count;
	int	sqn;
	int	dqn;
	char	**array;
	char	*tmp;
}	t_data;

int	quo_num(char *tmp, t_data *data)
{
	int	i = 0, s = 0, d = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\'')
			s++;
		if (tmp[i] == '\"')
			d++;
		i++;
	}
	if ((s % 2 == 0 || s == 0) && (d % 2 == 0 || d == 0))
	{
		data->sqn = s;
		data->dqn = d;
		return (s);
	}
	return (-1);
}

int	quo_arrangement(char *str)
{
	int	i = 0, k =0;
	char	*sstr = malloc(strlen(str) * sizeof(char));
	while (str[i])
	{
		if (str[i] == '\'' && str[i + 1] != '\'')
		{
			sstr[k] = str[i];
			k++;
			i++;
		}
		else if (str[i] == '\"' && str[i + 1] != '\"')
		{
			sstr[k] = str[i];
			i++;
			k++;
		}
		else
			i += 2;
	}
	sstr[k] = '\0';
	if (sstr[0] == sstr[2] && sstr[0] != '\0')
	{
		free(sstr);
		return (-1);
	}
	if (sstr[0] != '\0')
		if (quo_arrangement(sstr) == -1)
		{
			free(sstr);
			return (-1);
		}
	free(sstr);
	return (0);
}

int	quo_order(char *tmp, t_data *data)
{
	int	i = 0, k = 0;
	char	*q_string;
	q_string = malloc((data->sqn + data->dqn + 1) * sizeof(char));
	while (tmp[i])
	{
		if (tmp[i] == '\'')
		{
			q_string[k] = '\'';
			k++;
		}
		if (tmp[i] == '\"')
		{
			q_string[k] = '\"';
			k++;
		}
		i++;
	}
	q_string[k] = '\0';
	printf("q_str: %s\n", q_string);
	if (quo_arrangement(q_string) == -1)
	{
		free(q_string);
		return (-1);
	}
	free(q_string);
	return (0);
}

int	ft_strcpy(t_data *data, char *tmp, int len, int k)
{
	int	i = 0;
	printf("TMP: %s   | i: %i\n", tmp, len);
	data->array[k] = malloc((len + 1) * sizeof(char));
	if (!data->array[k])
		return (-1);
	while (i < len)
	{
		data->array[k][i] = tmp[i];
		i++;
	}
	data->array[k][i] = '\0';
	return (0);
}

int	space_splitt(t_data *data, char *tmp, int k)
{
	int	i = 0, m = 0;
	if (tmp[0] == '\0')
		return (-1);
	while (tmp[i] == ' ')
		i++;
	tmp = tmp + i;
	i = 0;
// THERE IS A PROBLEM IN THIS FUNCTION: IT IS NOT PUTTING THE '=' SIGN TO THE ARRAY!
// =================================================================================
	while (tmp[i] != '\0' && tmp[i] != ' ' && tmp[i] != '=')
		i++;
	if (tmp[0] != '=')
		ft_strcpy(data, tmp, i, k);
	if (tmp[0] == '=')
	{
		ft_strcpy(data, tmp, 1, k);
		i++;
	}
	k++;
	if (space_splitt(data, tmp + i, k) == -1 || tmp[i] == '\0')
		data->array[k] = NULL;
	return (0);
	
}

int	chop_the_string(char *tmp, t_data *data)
{
	int	i = 0;
	if (data->sqn + data->dqn == 0)
		space_splitt(data, tmp, 0);	// split at space and '='
	
	return (0);
}

int	word_counter(t_data *data)
{
	int	i = 0, k = 0;
	while (data->tmp[i] != '\0')
	{
		if (data->tmp[i] == ' ' && data->tmp[i + 1] != ' ' && \
		data->tmp[i + 1] != '\0' && data->tmp[i + 1] != '=')
			k++;
		if (data->tmp[i] == '=')
			k++;
		i++;
	}
	return (k);
}

char	**input_validation(char *tmp)
{
	int	l = 0;
	t_data	data;
	data.tmp = tmp;
	if (quo_num(tmp, &data) == -1)
	{
		free(tmp);
		return (NULL);
	}
	data.word_count = word_counter(&data);
	if (data.sqn + data.dqn > 0)
		if (quo_order(tmp, &data) == -1)
		{
			free(tmp);
			return (NULL);
		}
	data.array = malloc((data.word_count + 1) * sizeof(char *));
	if (chop_the_string(tmp, &data) == -1)
	{
		printf("not working BROOOOO\n");
		return (NULL);
	}

	return (data.array);
}

int	main(void)
{
	int	i = 0;
	char	*tmp;
	char	**array;
	tmp = readline("promp> ");
	
	if ((array = input_validation(tmp)) == NULL)
	{
		printf("wrong input you goofy");
		return (0);
	}
	while (array[i] != NULL)
	{
		printf("<%s>\n", array[i]);
		i++;
	}
	return (0);
}
