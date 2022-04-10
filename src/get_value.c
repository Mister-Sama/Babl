/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** get_value - 2022
**
** *****************************************************************************
*/

#include        "babl.h"

t_variable	*std_get_value(char	*cmd,
			       size_t	*i)
{
  t_variable	*var;
  t_value	*val;
  int		nbr;

  if (std_read_integer(cmd, i, &nbr) == false)
    return (NULL);
  var = malloc(sizeof(t_variable));
  if (var == NULL)
    return (NULL);
  val = malloc(sizeof(t_value));
  if (val == NULL)
    {
      free(var);
      return (NULL);
    }
  val->value = nbr;
  var->type = VAL;
  var->data = val;
  return (var);
}
