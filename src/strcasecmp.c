/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** strcasecmp - 2022
**
** *****************************************************************************
*/

#include        "babl.h"

bool		std_strcasecmp(const char	*s1,
			       const char	*s2)
{
  size_t	i;

  i = 0;
  while (s1[i] != '\0' || s2[i] != '\0')
    {
      if ((MIN(s1[i])) != (MIN(s2[i])))
	return (false);
      i = i + 1;
    }
  return (true);
}
