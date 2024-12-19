echo "ENTER THE NUMBER"
read n
fact=1
if [ $n -eq 1 -o $n -eq 0 ]
then
echo "factorial = 1"
else
for (( i=$n;i>0;i-- ))
do
fact=$((fact*i)) 
done
echo "factorial = $fact"
fi
