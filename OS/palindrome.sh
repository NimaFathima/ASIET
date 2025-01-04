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
#student@dl-15:~/NIMA_46$ gedit palindrome.sh
#student@dl-15:~/NIMA_46$ chmod +x palindrome.sh
#student@dl-15:~/NIMA_46$ ./palindrome.sh
#ENTER NUMBER : 
#868
#THE NUMBER IS PALINDROME
#student@dl-15:~/NIMA_46$ ./palindrome.sh
#ENTER NUMBER : 
#856
#THE NUMBER IS NOT PALINDROME
#student@dl-15:~/NIMA_46$ 

