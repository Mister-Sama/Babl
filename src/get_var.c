/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** get_variable - 2022
**
** *****************************************************************************
*/

#include	"babl.h"

t_variable	*std_get_variable(char			*cmd,
				  size_t		*i,
				  t_symbol_table	**tab)
{
  t_variable	*var;
  size_t	save;

  save = *i;
  if ((var = std_get_value(cmd, i)) != NULL)
    return (var);
  if (save != *i)
    return (NULL);
  else if ((var = std_get_symbol(cmd, i, tab)) != NULL)
    return (var);
  if (save != *i)
    return (NULL);
  else if (std_read_text(cmd, i, "("))
    {
      var = std_compute(cmd, i, tab);
      if (std_read_text(cmd, i, ")"))
	return (var);
    }
  return (NULL);
}

