sum=0
i=1
while [  $i != 0  ]
do
echo "Enter number : "
read new
sum=$(( $sum + $new ))
echo "Enter 0 to stop adding : "
read i
done
echo "The total sum is $sum"
