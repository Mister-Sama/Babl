/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** strcat - 2022
**
** *****************************************************************************
*/

#include	"babl.h"

char		*std_strcat(char	*dest,
			    const char	*src)
{
  size_t	i;
  size_t	j;

  i = std_strlen(dest);
  j = 0;
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  dest[i] = '\0';
  return (dest);
}

