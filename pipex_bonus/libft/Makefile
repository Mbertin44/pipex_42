# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momo <momo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 13:53:50 by mbertin           #+#    #+#              #
#    Updated: 2022/10/06 21:14:38 by momo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_split.c  ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_strrchr.c \
		ft_strlcat.c ft_strlcpy.c ft_strmapi.c ft_strnstr.c ft_strtrim.c \
		ft_substr.c ft_tolower.c ft_toupper.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_printf_ext.c get_next_line.c get_next_line_utils.c
 \

OBJS = ${SRCS:%c=%o}

NAME = libft.a

AR = ar rcs

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
		@${AR} ${NAME} ${OBJS}

clean:
		@${RM} ${OBJS}

fclean: clean
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re