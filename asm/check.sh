arr=($(cat file8.txt))
for i in $arr
do 
	valgrind ./asm "/Users/matruman/Desktop/core1/asm/42-corewar/tests/asm/valid2/$i"
	echo $i
done
