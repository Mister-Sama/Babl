/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** strcmp - 2022
**
** *****************************************************************************
*/

#include	"babl.h"

bool		std_strcmp(const char	*str1,
			   const char	*str2)
{
  size_t	i;

  i = 0;
  while (str1[i] != '\0' || str2[i] != '\0')
    {
      if (str1[i] != str2[i])
	return (false);
      i = i + 1;
    }
  return (true);
}
