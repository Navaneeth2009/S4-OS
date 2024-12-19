echo "Enter the number to check wheteher odd or even : "
read num
if [ $(($num%2)) == 0 ]
then
echo "The number $num is even" 
else
echo "The number $num is odd"
fi
