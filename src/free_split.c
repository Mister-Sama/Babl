/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** free_split - 2022
**
** *****************************************************************************
*/

#include	"babl.h"

void		std_free_split(char	**split)
{
  size_t	i;

  i = 0;
  if (split == NULL)
    return;
  while (split[i] != NULL)
    {
      free(split[i]);
      i = i + 1;
    }
  free(split);
}
