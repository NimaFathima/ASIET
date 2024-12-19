echo "ENTER NUMBER : "
read n
sum=0
while [ $n -gt 0 ] 
do
l=$(($n % 10))
sum=$(($sum + $l))
n=$(($n / 10))
done
echo "SUM = $sum"
