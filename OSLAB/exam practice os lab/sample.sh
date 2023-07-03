echo "enter n"
read n

if(( n<2 ));then
    echo "not prime"
    exit 0
fi

flag=0

for(( i=2;i<=$n/2;i++ ));do
    if((n%i==0));then
        flag=1
    fi
done

if((flag==1));then
    echo "not prime"
else
    echo "prime"
fi

