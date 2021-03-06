/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** is_char_symbol - 2022
**
** *****************************************************************************
*/

#include        "babl.h"

bool		std_is_char_symbol(char		c)
{
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
	  (c >= '0'&& c <= '9') || c == '_');
}
