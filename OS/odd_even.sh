echo "ENTER THE NUMBER: "
read n
if [ $(($n % 2)) == 0 ]
then
echo "NUMBER IS EVEN"
else 
echo "NUMBER IS ODD"
fi
#student@dl-15:~/NIMA_46$ gedit oddeven.sh
#student@dl-15:~/NIMA_46$ chmod +x oddeven.sh
#student@dl-15:~/NIMA_46$ ./oddeven.sh
#ENTER THE NUMBER: 
#86
#NUMBER IS EVEN
#student@dl-15:~/NIMA_46$ ./oddeven.sh
#ENTER THE NUMBER: 
#85
#NUMBER IS ODD
