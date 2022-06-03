NAME = a.out

MAIN = main.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
# CXXFLAGS = -Wc++11-extensions
INCFLAGS = -I ./includes -I ./vector_test

SRSC_DIR = #./srcs/
SRCS_FILENAME = #ft_vector.cpp
SRCS = $(addprefix $(SRSC_DIR), $(SRCS_FILENAME)) $(MAIN)
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