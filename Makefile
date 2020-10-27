# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-wij <mvan-wij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/27 13:16:39 by mvan-wij      #+#    #+#                  #
#    Updated: 2020/10/27 14:50:40 by mvan-wij      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= libft

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRCEXT		= c
SRCDIR		= .
HEADERDIR	= .
OBJEXT		= o
BUILDDIR	= obj
BINDIR		= bin

SOURCES		= $(shell find '$(SRCDIR)/' -type f -name '*.$(SRCEXT)')
OBJECTS		= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,\
			   $(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

all: $(NAME)

$(NAME): $(BUILDDIR)/ $(OBJECTS)
	ar -cq $(NAME).a $(BUILDDIR)/*.$(OBJEXT)

so $(NAME).so: $(BUILDDIR)/ $(OBJECTS)
	$(CC) -shared $(BUILDDIR)/*.$(OBJEXT) -o $(NAME).so

clean:
	/bin/rm -rf $(BUILDDIR)/

fclean: clean
	/bin/rm -f $(NAME).a

re: fclean all

$(BUILDDIR)/:
	mkdir -p $(BUILDDIR)

$(BINDIR)/:
	mkdir -p $(BINDIR)

$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) -I$(HEADERDIR) -c $< -o $@

.PHONY: all clean fclean re
