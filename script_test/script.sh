nb=0
j=0
k=$1
for ((a=$k; a>0; a--))
do
	ARG="`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`"
	./push_swap $ARG > test
	echo $result
	nb=$(expr $nb + $(cat test | wc -l))
	ok=$(cat test | ./checker $ARG)
	echo $ok
done
	nb=$(expr $nb / $k)
echo "$nb"
