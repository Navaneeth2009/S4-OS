echo "ARITHMETIC CALCULATOR OPERTIONS "
echo "1->ADDITION,2->DIFFERENCE,3->PRODUCT,4->DIVISION"
echo "Enter operation to be performed : "
read op
case $op in 
1)echo "Enter the first and second number : "
read s1 
read s2
sum=$(( $s1 + $s2 )) 
echo "Sum is $sum " ;;
2)echo "Enter the first and second number :"
read sb1 
read sb2
diff=$(( $sb1 - $sb2 ))
echo "The difference is $diff";;
3)echo "Enter the first and second number  : "
read m1 
read m2
prod=$(( $m1 * $m2 ))
echo "The product is $prod";;
4)echo "Enter the divident and divisor : "
read in 
read out
quotient=$(( $in / $out ))
echo "The quotient is $quotient";;
*)echo "Invalid option" ;;
esac
