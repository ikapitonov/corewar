start:
    sti r1, %:live1, %1
    ldi %:live1, %0, r3
    sti r3, %50, %0
    ldi %:live1, %4, r3
    sti r3, %50, %4
    ldi %:live1, %8, r3
    sti r3, %50, %8
    fork %:end

live1:
    live %100
    ld %0, r2
    zjmp %:live1
end: