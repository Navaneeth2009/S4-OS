echo "Enter a number : "
read num
number=$num
rev=0
while [ $number -gt 0 ]
do
n=$(( $number % 10 ))
rev=$(( $rev * 10 + $n ))
number=$(( $number / 10 ))
done
if [ $num -eq $rev ]
then
echo "number is palindrome"
else 
echo "number is not palindrome"
fi
