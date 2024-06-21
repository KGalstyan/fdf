#include "fdf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
void	free_matrix(int **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	is_digit(char h)
{
	return (h >= '0' && h <= '9');
}

// void	free_stack(t_stack **stack)
// {
// 	t_stack	*tmp;

// 	if (!stack || !(*stack))
// 		return ;
// 	while (*stack)
// 	{
// 		tmp = (*stack)->next;
// 		free(*stack);
// 		*stack = tmp;
// 	}
// 	*stack = NULL;
// }