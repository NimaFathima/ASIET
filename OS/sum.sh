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

#student@dl-15:~/NIMA_46$ gedit sum.sh
#student@dl-15:~/NIMA_46$ chmod +x sum.sh
#student@dl-15:~/NIMA_46$ ./sum.sh
#ENTER NUMBER : 
#865
#SUM = 19
