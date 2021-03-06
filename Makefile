CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_usleep.c main.c tools.c
OFILES = $(CFILES:%.c=%.o)
NAME = philo

all : text $(NAME)

$(NAME) : $(OFILES)
	@$(CC) $(OFILES) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $<

clean :
	@rm -rf *.o
 
fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean all clean

text :
	@echo "\033[1;5;1;36m";

	@echo " ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────"
	@echo " ─██████████████─██████──██████─██████████─██████─────────██████████████─██████████████─██████████████─██████████████─██████──██████─██████████████─████████████████───██████████████─"
	@echo " ─██░░░░░░░░░░██─██░░██──██░░██─██░░░░░░██─██░░██─────────██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░██──██░░██─██░░░░░░░░░░██─██░░░░░░░░░░░░██───██░░░░░░░░░░██─"
	@echo " ─██░░██████░░██─██░░██──██░░██─████░░████─██░░██─────────██░░██████░░██─██░░██████████─██░░██████░░██─██░░██████░░██─██░░██──██░░██─██░░██████████─██░░████████░░██───██░░██████████─"
	@echo " ─██░░██──██░░██─██░░██──██░░██───██░░██───██░░██─────────██░░██──██░░██─██░░██─────────██░░██──██░░██─██░░██──██░░██─██░░██──██░░██─██░░██─────────██░░██────██░░██───██░░██─────────"
	@echo " ─██░░██████░░██─██░░██████░░██───██░░██───██░░██─────────██░░██──██░░██─██░░██████████─██░░██──██░░██─██░░██████░░██─██░░██████░░██─██░░██████████─██░░████████░░██───██░░██████████─"
	@echo " ─██░░░░░░░░░░██─██░░░░░░░░░░██───██░░██───██░░██─────────██░░██──██░░██─██░░░░░░░░░░██─██░░██──██░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░░░██───██░░░░░░░░░░██─"
	@echo " ─██░░██████████─██░░██████░░██───██░░██───██░░██─────────██░░██──██░░██─██████████░░██─██░░██──██░░██─██░░██████████─██░░██████░░██─██░░██████████─██░░██████░░████───██████████░░██─"
	@echo " ─██░░██─────────██░░██──██░░██───██░░██───██░░██─────────██░░██──██░░██─────────██░░██─██░░██──██░░██─██░░██─────────██░░██──██░░██─██░░██─────────██░░██──██░░██─────────────██░░██─"
	@echo " ─██░░██─────────██░░██──██░░██─████░░████─██░░██████████─██░░██████░░██─██████████░░██─██░░██████░░██─██░░██─────────██░░██──██░░██─██░░██████████─██░░██──██░░██████─██████████░░██─"
	@echo " ─██░░██─────────██░░██──██░░██─██░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░░░░░░░░░██─██░░██─────────██░░██──██░░██─██░░░░░░░░░░██─██░░██──██░░░░░░██─██░░░░░░░░░░██─"
	@echo " ─██████─────────██████──██████─██████████─██████████████─██████████████─██████████████─██████████████─██████─────────██████──██████─██████████████─██████──██████████─██████████████─"
	@echo " ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────"
	@echo "\x1b[0m"