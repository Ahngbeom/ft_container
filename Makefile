NAME = a.out

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
INCFLAGS = -I ./includes -I ./vector_test

SRSC_DIR = ./srcs/
SRCS_FILENAME = #ft_vector.cpp
SRCS = $(addprefix $(SRSC_DIR), $(SRCS_FILENAME)) ./my_main.cpp
OBJS = $(SRCS:.cpp=.o)

all		: $(NAME)

.cpp.o	:
		@ $(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
		@ $(CXX) $(CXXFLAGS) $(INCFLAGS) $^ -o $@

clean	:
		@ $(RM) $(OBJS)

fclean	: clean
		@ $(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re