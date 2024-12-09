#!/bin/bash
echo -e "\nWelcome to the Calculator\n"
while true; do
  echo "Enter first number:"
  read n1
  echo "Enter second number:"
  read n2

  echo -e "\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit"
  read ch

  case $ch in
    1) echo "Addition = $((n1+n2))";;
    2) echo "Subtraction = $((n1-n2))";;
    3) echo "Multiplication = $((n1*n2))";;
    4) 
       if [ $n2 -eq 0 ]; then
        echo "Division by zero is not allowed!\n"
       else
        echo "Division = $((n1/n2))"  
       fi
       ;;
    5) echo "Exiting"; exit;;
    *) echo "Invalid input";;
  esac
  echo -e "\n"
done