/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** sum - 2022
**
** *****************************************************************************
*/

#include		"babl.h"

static int		std_sum_operator(char		*str,
					 size_t		*index)
{
  return (std_read_text(str, index, "+") ? SYM_PLUS :
          std_read_text(str, index, "-") ? SYM_MINUS :
          SYM_NULL);
}

static t_variable	*std_exec_sum(t_variable	*var1,
				      t_variable	*var2,
				      int		operator)
{
  if (var1->type == ADR && var2->type == ADR)
    {
      std_free_variable(var1);
      std_free_variable(var2);
      return (NULL);
    }
  if (var1->type == VAL && var2->type == ADR && operator == SYM_PLUS)
    {
      ((t_adress *)(var2->data))->adress =
	((t_value *)(var1->data))->value + ((t_adress *)(var2->data))->adress;
      std_free_variable(var1);
      return (var2);
    }
  if (var1->type == ADR && var2->type == VAL && operator == SYM_PLUS)
    ((t_adress *)(var1->data))->adress =
      ((t_adress *)(var1->data))->adress + ((t_value *)(var2->data))->value;
  if (var1->type == VAL && var2->type == VAL)
    {
      ((t_value *)(var1->data))->value = (operator == SYM_PLUS) ?
      ((t_value *)(var1->data))->value + ((t_value *)(var2->data))->value :
	((t_value *)(var1->data))->value - ((t_value *)(var2->data))->value;
    }
  std_free_variable(var2);
  return (var1);
}

t_variable		*std_sum(t_variable		*var,
				 size_t			*index,
				 char			*str,
				 t_symbol_table		**tab)
{
  t_variable		*nvar;
  t_variable		*result;
  int			operator;

  if (var == NULL)
    return (NULL);
  result = std_prod(var, index, str, tab);
  operator = std_sum_operator(str, index);
  nvar = std_get_variable(str, index, tab);
  if (operator != SYM_NULL)
    {
      if (nvar == NULL)
	return (NULL);
      return (std_sum(std_exec_sum(result, std_prod(nvar, index, str, tab), operator), index, str, tab));
    }
  return (result);
}

