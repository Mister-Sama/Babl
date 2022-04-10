/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** prod - 2022
**
** *****************************************************************************
*/

#include                "babl.h"

static int		std_prod_operator(char		*str,
					 size_t		*index)
{
    return (std_read_text(str, index, "*") ? SYM_MUL :
	    std_read_text(str, index, "/") ? SYM_DIV :
	    std_read_text(str, index, "%") ? SYM_MOD :
	    SYM_NULL);
}

static t_variable       *std_exec_prod(t_variable         *var1,
				       t_variable         *var2,
				       int                operator)
{
  if (var1->type == ADR || var2->type == ADR)
    {
      std_free_variable(var1);
      std_free_variable(var2);
      return (NULL);
    }
  ((t_value *)(var1->data))->value = 
    (operator == SYM_MUL) ? ((t_value *)(var1->data))->value * ((t_value *)(var2->data))->value :
    (operator == SYM_DIV) ? ((t_value *)(var1->data))->value / ((t_value *)(var2->data))->value :
    ((t_value *)(var1->data))->value % ((t_value *)(var2->data))->value;
  std_free_variable(var2);
  return (var1);
}

t_variable		*std_prod(t_variable		*var,
				  size_t		*index,
				  char			*str,
				  t_symbol_table	**tab)
{
  t_variable		*nvar;
  int			operator;

  if (var == NULL)
    return (NULL);
  operator = std_prod_operator(str, index);
  nvar = std_get_variable(str, index, tab);
  if (operator != SYM_NULL)
    {
      if (nvar == NULL)
	return (NULL);
      return (std_prod(std_exec_prod(var, nvar, operator), index, str, tab));
    }
  return (var);
}
