#!/bin/bash

echo "Enter a number:"
read num

if [ $num -lt 2 ]; then
  echo "$num is not a prime number."
  exit 0
fi

is_prime=true

for (( i=2; i<$num; i++ )); do
  if (( $num % $i == 0 )); then
    is_prime=false
    break
  fi
done

if $is_prime; then
  echo "$num is a prime number."
else
  echo "$num is not a prime number."
fi
