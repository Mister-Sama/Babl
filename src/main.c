/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** main - 2022
**
** *****************************************************************************
*/

#include	"babl.h"

int		main(int	argc,
		     char	*argv[])
{
  int		fd;
  char		*file;
  char		**split;
  size_t	len;

  if (argc != 2)
    return (-1);
  fd = open(argv[1], O_RDONLY);
  if (fd == -1)
    return (-1);
  file = std_read_file(fd, &len);
  split = std_split(file, '\n');
  return (std_exec_babl(split));
}

