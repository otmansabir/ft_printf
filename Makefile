SRC = ft_int.c ft_llu.c ft_printf.c ft_putc.c ft_putlew.c ft_putstr.c ft_putup.c ft_voidx0.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc 

RM = rm -rf

NAME = libftprintf.a

AR = ar -cr 

HR = ft_printf.h

all : $(NAME) 

$(NAME) : $(OBJ) 
	$(AR) $(NAME) $(OBJ)

%.o : %.c $(HR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean 
	$(RM) $(NAME)

re : fclean all 

.PHONY : all clean fclean re 
