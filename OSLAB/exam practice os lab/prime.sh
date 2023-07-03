echo "Enter a number: "
read n
if [ $n -lt 2 ];then
    echo "$n is not prime"
fi
flag=true
for(( i=2;i<$n;i++ ));do
    if(( $n % $i == 0 )); then
        flag=false
    fi
done

if $flag; then
    echo "prime"
else
    echo "not prime"
fi