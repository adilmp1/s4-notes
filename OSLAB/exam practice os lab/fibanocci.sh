echo "enter the number"

read n

a=0
b=1
c=0

# d=$((a+b+34234))

echo -e

for(( i=0;i<$n;i++ ));do
    c=$((a+b))
    a=$b
    b=$c
    echo $a
done