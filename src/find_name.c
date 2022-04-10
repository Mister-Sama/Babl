/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** find_name - 2022
**
** *****************************************************************************
*/

#include        "babl.h"

char		*std_find_name(char	*str,
			       size_t	*index)
{
  int		i;
  char		*symbol;

  i = 0;
  std_read_space(str, index);
  while (std_is_char_symbol(str[*index + i]))
    i = i + 1;
  if (i == 0)
    return (NULL);
  symbol = malloc((i + 1) * sizeof(char));
  if (symbol == NULL)
    return (NULL);
  std_read_symbol(str, index, symbol, i);
  return (symbol);
}

