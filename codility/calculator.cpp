// calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

int resolve(std::string::iterator begin, std::string::iterator end)
{
   auto n_begin = begin, n_end = end;
   for (;n_begin != n_end; ++n_begin)
      std::cout << *n_begin;
   std::cout << std::endl;

   auto current = begin;
   while (std::distance(current, end) != 1) {
      if (*current == '+') {
         std::cout << "split by +" << std::endl;
         return resolve(begin, current) + resolve(current + 1, end);
      } else if (*current == '-') {
         std::cout << "split by -" << std::endl;
         return resolve(begin, current) - resolve(current + 1, end);
      } else
         ++current;
   }

   current = begin;
   int result = atoi(&*current++);
   std::cout << "take = " << result;
   while (current != end) {
      if (*current == '*') {
         std::cout << " multiply by ";
         int right = atoi(&*++current);
         std::cout << right;
         result *= right;
         std::cout << " equals " << result;
      } else if (*current == '/') {
         std::cout << " divide by ";
         int right = atoi(&*++current);
         std::cout << right;
         result /= right;
         std::cout << " equals " << result;
      }
      ++current;
   }
   std::cout << std::endl << " sub_result = " << result << std::endl << std::endl;
   return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
   std::string expression("3+3*4+3/1");
   std::cout << "result = " << resolve(expression.begin(), expression.end());
   getchar();
	return 0;
}

   /*if (begin != end) {
      switch(*begin) {
      case '+': 
         {
            if (dupa)
               return left;
            else 
               return left + resolve(++begin, end, false);
         } break;
      case '*':
         {
            return left * resolve(++begin, end, true);
         } break;
      case '/':
         {
            return left / resolve(++begin, end, true);
         } break;
      }
   }

   return left;*/
