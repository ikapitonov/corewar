.name "matruman"
.comment "Prepare to segfault, mthrfckrs!"

insert0:
    sti r1, %1, %:live0
    st r2, :insert0
insert1:
    sti r1, %1, %:live1
    st r2, :insert1
insert2:
    sti r1, %1, %:live2
    st r2, :insert2
insert3:
    sti r1, %1, %:live3
    st r2, :insert3
insert4:
    sti r1, %1, %:live4
    st r2, :insert4
insert5:
    sti r1, %1, %:live5
    st r2, :insert5
insert6:
    sti r1, %1, %:live6
    st r2, :insert6
insert7:
    sti r1, %1, %:live7
    st r2, :insert7
insert8:
    sti r1, %1, %:live8
    st r2, :insert8
insert9:
    sti r1, %1, %:live9
    st r2, :insert9
insert10:
    sti r1, %1, %:live10
    st r2, :insert10
insert11:
    sti r1, %1, %:live11
    st r2, :insert11
insert12:
    sti r1, %1, %:live12
    st r2, :insert12
insert13:
    sti r1, %1, %:live13
    st r2, :insert13
insert14:
    sti r1, %1, %:live14
    st r2, :insert14
insert15:
    sti r1, %1, %:live15
    st r2, :insert15
insert16:
    sti r1, %1, %:live16
    st r2, :insert16

ld %-1, r2
fork %:live1
ld %1, r2

live0:
    live %0
    and r2, %-2, r4
    zjmp %:live0
    fork %:live1
    ld %2, r2
live1:
    live %0
    and r2, %-3, r4
    zjmp %:live1
    fork %:live2
    ld %4, r2
live2:
    live %0
    and r2, %-5, r4
    zjmp %:live2
    fork %:live3
    ld %8, r2
live3:
    live %0
    and r2, %-9, r4
    zjmp %:live3
    fork %:live4
    ld %16, r2
live4:
    live %0
    and r2, %-17, r4
    zjmp %:live4
    fork %:live5
    ld %32, r2
live5:
    live %0
    and r2, %-33, r4
    zjmp %:live5
    fork %:live6
    ld %64, r2
live6:
    live %0
    and r2, %-65, r4
    zjmp %:live6
    fork %:live7
    ld %128, r2
live7:
    live %0
    and r2, %-129, r4
    zjmp %:live7
    fork %:live8
    ld %256, r2
live8:
    live %0
    and r2, %-257, r4
    zjmp %:live8
    fork %:live9
    ld %512, r2
live9:
    live %0
    and r2, %-513, r4
    zjmp %:live9
    fork %:live10
    ld %1024, r2
live10:
    live %0
    and r2, %-1025, r4
    zjmp %:live10
    fork %:live11
    ld %2048, r2
live11:
    live %0
    and r2, %-2049, r4
    zjmp %:live11
    fork %:live12
    ld %4096, r2
live12:
    live %0
    and r2, %-4097, r4
    zjmp %:live12
    fork %:live13
    ld %8192, r2
live13:
    live %0
    and r2, %-8193, r4
    zjmp %:live13
    fork %:live14
    ld %16384, r2
live14:
    live %0
    and r2, %-16385, r4
    zjmp %:live14
    fork %:live15
    ld %32768, r2
live15:
    live %0
    and r2, %-32769, r4
    zjmp %:live15
    ld %65536, r2
live16:
    live %0
    and r2, %-65537, r4
    zjmp %:live16
