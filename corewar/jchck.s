.name "Check !"
.comment "en fait C forker !"

gobepc: st r1, :buff
	st r6,-4
	ld :buff,r1
    st r1, 100
buff:
