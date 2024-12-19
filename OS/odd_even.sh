echo "ENTER THE NUMBER: "
read n
if [ $(($n % 2)) == 0 ]
then
echo "NUMBER IS EVEN"
else 
echo "NUMBER IS ODD"
fi
