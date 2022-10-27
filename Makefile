# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 13:53:50 by mbertin           #+#    #+#              #
#    Updated: 2022/10/26 13:09:07 by mbertin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
LIBFT_PATH	=	libft
LIBFT		=	libft/libft.a

CC		=	gcc
CFLAGS		=	-g -Wall -Werror -Wextra
RM		=	rm -f

SRCS		=	pipex.c					\
				path.c					\
				pipe_and_fork.c			\
				pipex_utils.c			\
				check_and_redirect.c	\

OBJS		= 	${SRCS:.c=.o}

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): 		$(OBJS)
				@echo "Compiling libft..."
				@$(MAKE) -C $(LIBFT_PATH)
				@echo "libft compiled successfully."
				@echo "Compiling $(NAME) sources"
				@$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $(NAME)
				@echo "Done !"


all: 			$(NAME)

# Removes objects
clean:
				@echo "Removing $(NAME) objects..."
				@$(RM) $(OBJS)
				@echo "Removing libft objects..."
				@make clean -C $(LIBFT_PATH)
				@echo "$(NAME) objects successfully deleted."
				@echo "libft objects successfully deleted."

# Removes objects and executable
fclean: 		clean
				@echo "Removing $(NAME) program..."
				@$(RM) $(NAME)
				@echo "Removing libft archive..."
				@$(RM) $(LIBFT)
				@echo "Executable(s) and archive(s) successfully deleted."

exe:			$(NAME)
				valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --trace-=children=yes ./pipex

# Removes objects and executable then remakes all
re: 			fclean all

.PHONY:			all clean fclean bonus re
