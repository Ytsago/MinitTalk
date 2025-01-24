CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar
ARFLAG = -rcs

GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m
RED    = \033[31m
RESET  = \033[0m

LIBC =	ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c \
		ft_toupper.c ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c \
		ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_strchr.c \
		ft_strrchr.c ft_strnstr.c ft_strdup.c ft_calloc.c ft_atoi.c 

ADDITIONAL =	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c \
				ft_substr.c ft_strtrim.c ft_striteri.c ft_strmapi.c ft_strjoin.c ft_split.c \
				ft_printf.c

BONUSES = 	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c \
			ft_lstiter_bonus.c ft_putnbr_base.c get_next_line.c get_next_line_utils.c \
			ft_atol.c ft_issign.c

INCDIR = inc/

INCH = libft.h ft_printf.h get_next_line.h

INC = $(addprefix $(INCDIR), $(INCH))

SRCDIR = src/

FILES = $(LIBC) $(ADDITIONAL) $(BONUSES)

SRCS = $(addprefix $(SRCDIR), $(FILES))

OBJDIR = .Obj/

OBJS = $(subst $(SRCDIR), $(OBJDIR), $(SRCS:%.c=%.o))

NAME = libft.a

all: $(NAME) $(INC)

$(NAME) : $(OBJS)
	@echo "$(YELLOW)Creating  library : $(BLUE)$(NAME)...$(RESET)"
	@$(AR) $(ARFLAG) $@ $? && echo "$(GREEN)$(NAME) created successfully !$(RESET)"

$(OBJDIR)%.o: $(SRCDIR)%.c $(INC) | $(OBJDIR) msg
	$(CC) -c $(CFLAGS) -I$(INCDIR) $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)Compiling...$(RESET)"

clean:
	@echo "$(RED)Deleting object files...$(RESET)"
	@rm -rf $(OBJDIR) && echo "$(GREEN)Done !$(RESET)"

fclean:
	@echo "$(RED)Deleting executable or library $(NAME)...$(RESET)"
	@rm -f $(NAME) && echo "$(GREEN)Done !$(RESET)"

re: fclean all

.PHONY: clean fclean re all bonus msg
