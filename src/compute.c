/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** compute - 2022
**
** *****************************************************************************
*/

#include                "babl.h"

t_variable		*std_compute(char		*cmd,
				     size_t		*i,
				     t_symbol_table	**tab)
{
  t_variable		*var;

  var = std_get_variable(cmd, i, tab);
  if (var == NULL)
    return (NULL);
  return (std_ternaire(var, i, cmd, tab));
}
