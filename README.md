# push_swap

## Final grade 100/100
  
## Description
  Solo – about 60 hours

This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

## Table of Contents

- [Installation](#installation)
- [Mandatory](#Mandatory)

## Installation

Clone this repository using the following command.

    git clone https://github.com/andonimarz/push_swap.git

## Mandatory

  • You have 2 stacks named a and b.
  
  • At the beginning:
  
    ◦ The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
  
    ◦ The stack b is empty.
  
  • The goal is to sort in ascending order numbers into stack a. To do so you have the
  following operations at your disposal:
  
      sa (swap a): Swap the first 2 elements at the top of stack a.
      Do nothing if there is only one or no elements.
      sb (swap b): Swap the first 2 elements at the top of stack b.
      Do nothing if there is only one or no elements.
      ss : sa and sb at the same time.
      pa (push a): Take the first element at the top of b and put it at the top of a.
      Do nothing if b is empty.
      pb (push b): Take the first element at the top of a and put it at the top of b.
      Do nothing if a is empty.
      ra (rotate a): Shift up all elements of stack a by 1.
      The first element becomes the last one.
      rb (rotate b): Shift up all elements of stack b by 1.
      The first element becomes the last one.
      rr : ra and rb at the same time.
      rra (reverse rotate a): Shift down all elements of stack a by 1.
      The last element becomes the first one.
      rrb (reverse rotate b): Shift down all elements of stack b by 1.
      The last element becomes the first one.
      rrr : rra and rrb at the same time.

Your project must comply with the following rules:

  • You have to turn in a Makefile which will compile your source files. It must not relink.
  
  • Global variables are forbidden.
  
  • You have to write a program named push_swap that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
  
  • The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.
  
  • Instructions must be separated by a ’\n’ and nothing else.
  
  • The goal is to sort the stack with the lowest possible number of operations. During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated. If your program either displays a longer list or if the numbers aren’t sorted properly, your grade will be 0.
  
  • If no parameters are specified, the program must not display anything and give the prompt back.

  • In case of error, it must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.
  
  During the evaluation process, a binary will be provided in order to properly check your program. It will work as follows:
  
      $>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
      6
      $>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
      OK
      $>
 
If the program checker_OS displays "KO", it means that your push_swap came up with a list of instructions that doesn’t sort the numbers.
