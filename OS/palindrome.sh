echo "ENTER NUMBER : "
read n
a=$n
b=o
while [ $a -gt 0 ]
do
c=$(($a % 10))
b=$(($b*10 + $c))
a=$(($a / 10))
done
if [ $b -eq $n ]
then
echo "THE NUMBER IS PALINDROME"
else
echo "THE NUMBER IS NOT PALINDROME"
fi
