# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jechoi <jechoi@student.42gyongsan.kr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 13:07:53 by jechoi            #+#    #+#              #
#    Updated: 2025/04/01 13:12:01 by jechoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_addft.c ft_addft2.c ft_addft3.c ft_char.c ft_memory.c ft_memory2.c ft_split.c ft_str.c ft_str2.c ft_trans.c
OBJS		= $(SRCS:.c=.o)

BONUS		=	libft_bonus.c libft2_bonus.c
BONUS_OBJS	= $(BONUS:.c=.o)

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.

NAME		= libft.a

ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(BONUS_OBJS)
else
	OBJECTS = $(OBJS)
endif

all:			$(NAME)

$(NAME):		$(OBJECTS)
				ar rcs $(NAME) $(OBJECTS)
				
bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
