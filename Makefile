# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 16:37:06 by rledrin           #+#    #+#              #
#    Updated: 2020/01/24 14:16:49 by rledrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

CC_FLAGS	=	-Wall -Wextra -Werror

NASM		=	nasm

NASM_FLAGS	=	-f macho64

AR			=	ar -rc

RANLIB		=	ranlib

RM			=	rm -rf

DIR_HEADERS =	./includes/

DIR_SRCS	=	./srcs/

DIR_OBJS	=	./compiled_srcs/


SRC			=	ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_write.s \
				ft_read.s \
				ft_strdup.s \

SRCS		=	$(SRC)

MAIN_SRC	=	testlib.c


OBJS 		=	$(SRCS:%.s=$(DIR_OBJS)%.o)

MAIN_OBJ	=	$(MAIN_SRC:%.c=$(DIR_OBJS)%.o)

NAME 		=	libasm.a


EXEC		=	testlib


$(NAME):		$(OBJS)
				@echo "$(_GREEN) All files compiled. $(_END)✅"
				@$(AR) $(NAME) $(OBJS)
				@ranlib $(NAME)
				@echo "$(_GREEN) Library '$(NAME)' compiled. $(_END)✅"

$(EXEC):		$(NAME) $(MAIN_OBJ)
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) $(NAME) $(MAIN_OBJ) -o $(EXEC) -g3 -fsanitize=address
				@echo "$(_GREEN) Executable '$(EXEC)' created. $(_END)✅"

$(OBJS):		| $(DIR_OBJS)

$(DIR_OBJS)%.o: $(DIR_SRCS)%.s
				@$(NASM) $(NASM_FLAGS) -I $(DIR_HEADERS) -s $< -o $@

$(DIR_OBJS)%.o: %.c
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(DIR_OBJS):
				@mkdir $(DIR_OBJS)

all:			$(NAME)

clean:
				@$(RM) $(DIR_OBJS)
				@$(RM) $(EXEC)
				@echo "$(_RED)'"$(DIR_OBJS)"' has been deleted. $(_END)🗑️"

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(_RED)'"$(NAME)"' has been deleted. $(_END)🗑️"

re:				fclean all

# bonus:			all

# re_bonus:		fclean bonus

.PHONY:			all, clean, fclean, re, bonus, re_bonus
