NAME	=	pipex

SRCS	=	main.c       \
		controller.c \
		spliter.c    \
		quote.c      \
		pathfinder.c \
		utils.c      \
		utils2.c

SRCS_BONUS	=	main_bonus.c          \
			get_next_line_bonus.c \
			controller.c          \
			spliter.c             \
			quote.c               \
			pathfinder.c          \
			utils.c               \
			utils2.c

OBJS	=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

CC	=	cc

CFLAGS	=	-Wall -Werror -Wextra

RM	=	rm -rf 

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS)

.c.o:
		$(CC) $(CFLAGS) -c $<

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS_BONUS)
		$(CC) -o $(NAME) $(OBJS_BONUS)

.PHONY: all clean fclean re bonus
