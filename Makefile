NAME	=	pipex

SRCS	=	main.c       \
		controller.c \
		spliter.c    \
		quote.c      \
		pathfinder.c \
		utils.c      \
		utils2.c

SRCS_BONUS	=	main_bonus.c	

OBJS	=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

CC	=	cc

CFLAGS	=	-Wall -Werror -Wextra

RM	=	rm -rf 

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

.c.o:
		$(CC) $(CFLAGS) -c $<

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS) $(OBJS_BONUS)
		ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

.PHONY: all clean fclean re bonus
