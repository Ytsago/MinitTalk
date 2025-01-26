GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m
RED    = \033[31m
RESET  = \033[0m

CFLAGS = -Wall -Wextra -Werror -g3
CC = cc
AR = ar
ARFLAG = -rcs

FILE = client.c

SFILE = get_signal.c

INCDIR = inc/

LIB_D = libft/

LIB = $(LIB_D)libft.a

SRCDIR = src/

SRCS = $(SRCS_D)$(FILE)

OBJDIR = .Obj/

OBJS = $(FILE:%.c=$(OBJDIR)%.o)

SOBJS = $(SFILE:%.c=$(OBJDIR)%.o)

INC = minitalk.h

NAME = client

SNAME = server

all: $(NAME) $(SNAME)

$(NAME) : $(OBJS)
	@echo "$(YELLOW)Creating final product : $(BLUE)$@...$(RESET)"
	@$(CC) $(CFLAGS) $^ $(LIB) -o $@ && echo "$(GREEN)$@ Created successfully !$(RESET)"

$(SNAME) : $(SOBJS)
	@echo "$(YELLOW)Creating final product : $(BLUE)$@...$(RESET)"
	@$(CC) $(CFLAGS) $^ $(LIB) -o $@ && echo "$(GREEN)$@ Created successfully !$(RESET)"

$(OBJDIR)%.o: $(SRCDIR)%.c $(LIB) $(INCDIR)$(INC) | $(OBJDIR)
	@echo "$(YELLOW)Compiling...$(RESET)"
	$(CC) -c $(CFLAGS) -I $(INCDIR) -I $(LIB_D)$(INCDIR) $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIB): FORCE
	@$(MAKE) -C $(LIB_D) --no-print-directory

clean:
	@echo "$(RED)Deleting object files...$(RESET)"
	@rm -rf $(OBJDIR) && echo "$(GREEN)Done !$(RESET)"
	@$(MAKE) $@ -C $(LIB_D) --no-print-directory
	

fclean: clean
	@echo "$(RED)Deleting executable or library $(NAME) and $(SNAME)...$(RESET)"
	@rm -f $(NAME) && echo "$(GREEN)Done !$(RESET)"
	@rm -f $(SNAME) && echo "$(GREEN)Done !$(RESET)"
	@$(MAKE) $@ -C $(LIB_D) --no-print-directory

re: fclean all

FORCE:

.PHONY: clean fclean re all bonus