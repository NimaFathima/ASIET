echo "ENTER THE CHOICE" 
echo "1. Add"
echo "2. Subtract"
echo "3. Multiply"
echo "4. Divide"
read c
echo "ENTER THE NUMBERS"
read num1 num 2

case $c in
1)result=$(($num1 + $num2))
echo "Result: $num1 + $num2 = $result"
;;
2)result=$(($num1 - $num2))
echo "Result: $num1 - $num2 = $result"
;;
3)result=$(($num1 * $num2))
echo "Result: $num1 * $num2 = $result"
;;
4)if [ $num2 -ne 0 ]
then 
result=$(($num1 / $num2))
echo "Result: $num1 / $num2 = $result"
else
echo "Division by zero not possible "
fi
;;
*)echo "Invalid input";;
esac

