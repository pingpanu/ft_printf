# ft_printf

-- Introduction --

printf is the most basic function in C language, every programmer are introduced with the following code
  'printf("Hello world");
However, printf function is capable for wide array of output thanks to the use of functions in stdarg.h library, including va_list and va_arg. This project is to replicate the printf function for better understanding of va_arg and va_list.

-- Difference from printf --

This ft_printf have several difference from printf, including
1) Only support %c, %s, %p, %d, %i, %u, %x, %X, and %%.
2) Don't have safety buffer handling
3) Don't support * flag.

-- How to use --

It can executed in the same manner of printf, but if you execute anything mentioned above (eg. %f, %a, * flag) it won't return anything.
Here's additional feature of the ft_printf

    printf("%25.5s", "Loneliness");
    
    1) 25 (number before .) is called width, indicated the width of the output, if it's larger than the 2) or argument length (10 for "Loneliness").
      1.1) Any space that is not the argument, it is " ". EXCEPT if 0 flag detected.
      1.2) If width is less that argument length or precision, it do nothing.
      1.3) You can typre - before width to make it align LEFT.
    2) 5 (number after .) is called precision, indicated the precision of the output.
      2.1) For %c and %s, it cut the output if precision is less than argument's length.
      2.2) Other argument will increase output length IF precision is LARGER than argument's length.
    3) This function capable of +, " ", and # flag.
      3.1) + will add + sign in front of numeric arguments (%d and %i)
      3.2) " " will add 1 space in front of any arguments, EXCEPT %c, %%, and %p.
      3.3) # will add 0X or 0x in front of hexadecimal arguments (%x or %X).
    To sum up, this line will return string with length of 25 units, but the string only contained "Lonel".

-- Testing --

  I had tested the program with these tester
    1) https://github.com/Tripouille/printfTester (100%)
    2) https://github.com/paulo-santana/ft_printf_tester (100%)
 
 -- How its work --
  Here's the explanation for each folders
  1) incs is header file folder (.h)
  2) libft is the function make to replicate basic glibc function (eg. strlen, strcat and etc.)
  3) srcs is the source files
  4) utils (in srcs folder) is the folder for auxillary function that ft_printf will call.
  
  The ft_printf will generate va_list arguments and f struct. All of these will be use to make output arguments via print_argument (eg. print_c) by logically check the conditions, then call .c files in utils. This logical structure make this ft_printf easy to expand, you just edit some part in get_params.c and ft_putall.c .
  
 -- Other notes --
  I would like to make it capable of * flag and other arguments (%f for float)
