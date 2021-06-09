NAME = so_long

HEADER = includes/so_long.h

LIST = get_next_line_utils.c get_next_line.c so_long.c check_map.c\
	utils.c work_with_img.c print_img.c utils2.c utils_for_lst.c

FLAGS = -Wall -Wextra -Werror

FLAGSMLX = -lmlx -framework OpenGL -framework AppKit

OBJ = $(LIST:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

%.o : %.c $(HEADER)
	gcc $(FLAGS) -I$(HEADER) -c $< -o $@

${NAME} : $(OBJ) $(HEADER)
	gcc $(FLAGS) $(OBJ) -I./includes $(FLAGSMLX) libmlx.dylib -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all