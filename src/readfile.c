/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** readfile - 2022
**
** *****************************************************************************
*/

#include	"babl.h"

char		*std_read_file(const int	fd,
			       size_t		*len)
{
  char		*save;
  char		*str;
  int		sread;

  *len = 0;
  str = NULL;
  sread = 4096 * sizeof(char);
  while (sread == 4096 * sizeof(char))
    {
      save = malloc(4096 * sizeof(char));
      if (save == NULL)
	return (str);
      sread = read(fd, save, 4096 * sizeof(char));
      save = std_realloc(save, sread + 1);
      str = std_realloc(str, std_strlen(str) + sread + 1);
      if (std_strcat(str, save) == NULL)
	return (NULL);
      *len = *len + sread;
      free(save);
    }
  return (str);
}
