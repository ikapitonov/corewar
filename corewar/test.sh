./corewar -dump $1 ../vm_champs/champs/examples/helltrain.cor ../vm_champs/champs/jumper.cor > file.txt
../vm_champs/corewar -d $1 ../vm_champs/champs/examples/helltrain.cor ../vm_champs/champs/jumper.cor > example.txt
diff file.txt example.txt
