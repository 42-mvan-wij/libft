# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-wij <mvan-wij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/27 13:16:39 by mvan-wij      #+#    #+#                  #
#    Updated: 2020/11/25 13:36:47 by mvan-wij      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= libft

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

SRCEXT			= c
SRCDIR			= .
HEADERDIR		= .
OBJEXT			= o
BUILDDIR		= obj

SOURCES			= ./ft_split.c $\
				  ./ft_toupper.c $\
				  ./ft_strrchr.c $\
				  ./ft_putstr_fd.c $\
				  ./ft_strncmp.c $\
				  ./ft_isascii.c $\
				  ./ft_isalnum.c $\
				  ./ft_memchr.c $\
				  ./ft_memccpy.c $\
				  ./ft_strlcpy.c $\
				  ./ft_strnstr.c $\
				  ./ft_putnbr_fd.c $\
				  ./ft_bzero.c $\
				  ./ft_putchar_fd.c $\
				  ./ft_memmove.c $\
				  ./ft_isdigit.c $\
				  ./ft_memcmp.c $\
				  ./ft_memcpy.c $\
				  ./ft_tolower.c $\
				  ./ft_isalpha.c $\
				  ./ft_putendl_fd.c $\
				  ./ft_itoa.c $\
				  ./ft_strdup.c $\
				  ./ft_strlen.c $\
				  ./ft_substr.c $\
				  ./ft_strjoin.c $\
				  ./ft_atoi.c $\
				  ./ft_strmapi.c $\
				  ./ft_strlcat.c $\
				  ./ft_strtrim.c $\
				  ./ft_calloc.c $\
				  ./ft_isprint.c $\
				  ./ft_memset.c $\
				  ./ft_strchr.c

BONUSSOURCES	= ./ft_lstclear.c $\
				  ./ft_lstinsert_bonus.c $\
				  ./ft_lstmap.c $\
				  ./ft_lstnew.c $\
				  ./ft_lstlast.c $\
				  ./ft_lstiter.c $\
				  ./ft_lstadd_front.c $\
				  ./ft_lstdelone.c $\
				  ./ft_lstsize.c $\
				  ./ft_lstadd_back.c $\

MYBONUSSOURCES	= ./ft_islower_bonus.c $\
				  ./ft_iscntrl_bonus.c $\
				  ./ft_isupper_bonus.c $\
				  ./ft_isgraph_bonus.c $\
				  ./ft_isxdigit_bonus.c $\
				  ./ft_isspace_bonus.c $\
				  ./ft_ispunct_bonus.c $\
				  ./ft_strtolower_bonus.c $\
				  ./ft_strtoupper_bonus.c $\
				  ./ft_itoa_base_bonus.c $\
				  ./ft_putnbr_base_bonus.c $\
				  ./ft_itoa_basei_bonus.c $\
				  ./ft_memdup_bonus.c

OBJECTS			=	$(patsubst $(SRCDIR)/%,$(BUILDDIR)/%, $\
					$(SOURCES:$(SRCEXT)=$(OBJEXT)))
BONUSOBJECTS	=	$(patsubst $(SRCDIR)/%,$(BUILDDIR)/%, $\
					$(BONUSSOURCES:$(SRCEXT)=$(OBJEXT)) $\
					$(MYBONUSSOURCES:$(SRCEXT)=$(OBJEXT)))

all: $(NAME)

$(NAME): $(NAME).a

$(NAME).a: $(BUILDDIR)/ $(OBJECTS)
	ar -cr $(NAME).a $(OBJECTS)

bonus: $(BUILDDIR)/ $(OBJECTS) $(BONUSOBJECTS)
	ar -cr $(NAME).a $(OBJECTS) $(BONUSOBJECTS)

so $(NAME).so: $(BUILDDIR)/ $(OBJECTS)
	$(CC) $(CFLAGS) -shared $(OBJECTS) -o $(NAME).so

clean:
	/bin/rm -rf $(BUILDDIR)/

fclean: clean
	/bin/rm -f $(NAME).a $(NAME).so

re: fclean all

$(BUILDDIR)/:
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) -I$(HEADERDIR) -c $< -o $@

.PHONY: all clean fclean re so bonus
