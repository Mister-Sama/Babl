/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** read_text - 2022
**
** *****************************************************************************
*/

#include	"babl.h"

bool		std_read_text(const char	*str,
			      size_t		*index,
			      const char	*token)
{
  size_t	i;
  size_t	j;

  i = 0;
  j = 0;
  std_read_space(&str[*index], &i);
  while (str[*index + i] == token[j] && str[i] != '\0')
    {
      i = i + 1;
      j = j + 1;
    }
  if (token[j] != '\0')
    return (false);
  *index = (token[j] == '\0') ? *index + i : *index;
  return (true);
}

