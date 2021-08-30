SRCS			= srcs/push_swap.c \
			  	  srcs/parser.c \
				  utils/parser_utils.c \
			  	  utils/stack_utils_1.c \
			  	  utils/stack_utils_2.c \
				  utils/stack_utils_3.c \
				  utils/push_swap_utils.c \
				  sorter/lazysort.c \
				  sorter/lazysort_scoring.c \
				  utils/sorter_utils.c \
				  utils/board_utils.c

BSRCS			= srcs/checker.c \
				  srcs/parser.c \
				  utils/parser_utils.c \
				  utils/checker_utils.c \
			 	  utils/opelist_utils.c \
			  	  utils/stack_utils_1.c \
			  	  utils/stack_utils_2.c \
				  utils/push_swap_utils.c

OBJS			= $(SRCS:.c=.o)

BOBJS			= $(BSRCS:.c=.o)

NAME			= push_swap

NAMECHECKER		= checker

LIB				= libft.a

LIBHEADER		= libft.h

LIBDIR			= libft/

HEADERS			= includes/

CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f

CC				= gcc

AR				= ar rcs

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(HEADERS) -I$(LIBDIR)

$(NAME):		$(LIB) $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(HEADERS) -lft -L.

$(NAMECHECKER):	$(LIB) $(BOBJS)
				$(CC) $(CFLAGS) $(BOBJS) -o $(NAMECHECKER) -I$(HEADERS) -lft -L.

all:			$(NAME)

clean:
				$(RM) $(OBJS) $(BOBJS) $(LIB)

fclean:			clean
				$(RM) $(NAME) $(NAMECHECKER)

re:				fclean all

bonus:			$(NAMECHECKER)

$(LIB):	
				@cd $(LIBDIR) && make bonus
				@cd $(LIBDIR) && make clean
				@cd $(LIBDIR) && mv $(LIB) ../

.PHONY:			all clean fclean c.o re bonus
