#include "pipex.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*zero_s;

	zero_s = s;
	while (n--)
		zero_s[n] = c;
	return ((void *)zero_s);
}
