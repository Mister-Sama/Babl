/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** get_symbol - 2022
**
** *****************************************************************************
*/

#include        "babl.h"

t_variable      *std_get_symbol(char		*cmd,
				size_t		*i,
				t_symbol_table	**tab)
{
  char		*name;
  t_variable	*var;

  if ((name = std_find_name(cmd, i)) == NULL)
    return (NULL);
  var = std_search_symbol(cmd, i, name, tab);
  free(name);
  if (var == NULL)
    return (NULL);
  return (var);
}
