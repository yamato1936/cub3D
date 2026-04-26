#include "../../includes/cub3d.h"

static void	put_str_fd(const char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

int	error_msg(const char *msg)
{
	put_str_fd("Error\n", 2);
	put_str_fd(msg, 2);
	put_str_fd("\n", 2);
	return (0);
}
