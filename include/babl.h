/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** babl - 2022
**
** *****************************************************************************
*/

#include	<stdbool.h>
#include	<fcntl.h>
#include	<malloc.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stddef.h>

#ifndef		__BABL_H__
#define		__BABL_H__

#define		MIN(c) ((c >= 'A' && c <= 'Z') ? (c + ('a' - 'A')) : (c))

typedef enum	e_type
  {
    ADR,
    VAL,
    FUNC
  }		t_type;

typedef enum	e_symbol_id
{
  SYM_NULL,
  SYM_PLUS,
  SYM_MINUS,
  SYM_MUL,
  SYM_DIV,
  SYM_MOD,
  SYM_EQUAL,
  SYM_DIFF,
  SYM_LOWER,
  SYM_STRICT_LOWER,
  SYM_UPPER,
  SYM_STRICT_UPPER,
}		t_symbol_id;

typedef	struct	s_value
{
  int		value;
}		t_value;

typedef struct	s_adress
{
  char		*adress;
}		t_adress;

typedef struct	s_function
{
  void		*local_table;
  char		*code;
  int		result;
}		t_function;

typedef struct  s_symbol_node
{
  char		*name;
  int		type;
  void		*data;
  void		*next;
}		t_symbol_node;

typedef struct	s_variable
{
  int		type;
  void		*data;
}		t_variable;

typedef struct	s_symbol_table
{
  void		*table;
}		t_symbol_table;


bool            std_strcmp(const char			*str1,
                           const char			*str2);

size_t		std_strlen(const char			*str);

int             std_write_errors(const char		*str,
                                 int			error_value);

char            *std_read_file(const int		fd,
                               size_t			*len);

void            *std_realloc(void			*ptr,
                             size_t			size);

char            **std_split(const char			*str,
                            char			token);

void            std_print_split(char			**split);

void            std_free_split(char			**split);

int             std_puts(const char			*str);

char            *std_strcat(char			*dest,
                            const char			*src);

bool            std_read_text(const char		*str,
                              size_t			*index,
                              const char		*token);

bool            std_read_chars(const char		*str,
                               size_t			*index,
                               const char		*token);

bool            std_read_symbol(const char		*str,
                                size_t			*index,
                                char			*output,
                                size_t			output_len);

bool            std_is_char_symbol(char			c);

bool            std_read_space(const char		*str,
                               size_t			*index);

int             std_find_symbol(const char		*str,
                                size_t			*index,
                                char			**env);

bool            std_read_integer(const char		*str,
                                 size_t			*index,
                                 int			*output);

int		std_read_line(char			*line,
			      t_symbol_table		*table,
			      int			*result);

int		std_exec_babl(char			**cmd);

char            *std_find_name(char			*str,
                               size_t			*i);

t_function      *std_get_func_parameters(char		*line,
					 size_t		*i,
					 int		res);

t_symbol_node  *std_push_symbol(t_symbol_table         **table,
				char                   *name,
				int                    type,
				void                   *data);

int		std_add_function(char			*line,
				 t_symbol_table		*table,
				 size_t			*i,
				 int			type);

t_symbol_table	*std_init_table();

char		*std_get_text(char			*str,
			      size_t			*i);

int             std_add_variable(char                   *line,
                                 t_symbol_table         *table,
                                 size_t                 *i);

int             std_add_adress(char			*line,
                               t_symbol_table		*table,
                               size_t			*i,
                               char			*name);

int             std_add_value(char			*line,
                              t_symbol_table		*table,
                              size_t			*i,
                              char			*name);

bool            std_strcasecmp(const char		*s1,
                               const char		*s2);

t_variable      *std_get_value(char			*cmd,
                               size_t			*i);

t_variable	*std_compute(char			*cmd,
			     size_t			*i,
			     t_symbol_table		**tab);

void            std_free_variable(t_variable		*var);

void    	*std_add_parameter(t_symbol_table       *ntab,
				   char                 *cmd,
				   size_t               *i,
				   t_symbol_table       **tab);

t_symbol_table	*std_copy_symbol_table(t_symbol_table   *tab);

int		std_exec_main(char			*cmd,
			      t_symbol_table		*table,
			      size_t			*i,
			      int			*result);

t_variable	*std_assign_symbol(char                 *cmd,
				   size_t               *i,
				   t_symbol_node        *symbol,
				   t_symbol_table       **tab);

t_variable      *std_get_variable(char                  *cmd,
                                  size_t                *i,
                                  t_symbol_table        **tab);

t_variable      *std_get_symbol(char			*cmd,
                                size_t			*i,
                                t_symbol_table		**tab);

t_symbol_node   *std_push_symbol(t_symbol_table         **table,
                                 char                   *name,
                                 int                    type,
                                 void                   *data);

t_variable      *std_search_symbol(char                 *cmd,
                                   size_t               *i,
                                   char                 *symbol,
                                   t_symbol_table       **tab);

t_variable	*std_compare(t_variable			*var,
			     size_t			*index,
			     char			*str,
			     t_symbol_table		**tab);

t_variable	*std_sum(t_variable			*var,
			 size_t				*index,
			 char				*str,
			 t_symbol_table			**tab);

t_variable	*std_ternaire(t_variable		*var,
			      size_t			*index,
			      char			*str,
			      t_symbol_table		**tab);

t_variable	*std_prod(t_variable			*var,
			  size_t			*index,
			  char				*str,
			  t_symbol_table		**tab);

#endif

