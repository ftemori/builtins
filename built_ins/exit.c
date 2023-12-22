
void	ft_exit(char *s)
{
	if (ft_strcmp("exit", s) == 0)
		exit(g_exit_status);
}