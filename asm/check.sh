arr=($(cat file3.txt))
for i in $arr
do 
	valgrind ./asm "42-corewar/tests/asm/error/$i" | grep "definitely lost"
	echo $i
done
