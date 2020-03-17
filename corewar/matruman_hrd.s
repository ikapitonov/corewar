.name "matruman"
.comment "Prepare to segfault, mthrfckrs!"

start:
sti r1, %1, %:live1
sti r1, %1, %:landing
st r2, :start
ldi %:liveblock, %0, r11
ldi %:liveblock, %4, r12
ldi %:liveblock, %8, r13
ldi %:liveblock, %12, r14
ldi %:liveblock, %16, r15

ld %:end, r2
ld %16, r3
landing:
    live %0
    sti r11, r2, %0
    sti r12, r2, %-2
    sti r13, r2, %-4
    sti r14, r2, %-6
    sti r14, r2, %-8
    add r2, r3, r2
    ld %0, r16
    zjmp %:landing
liveblock:
    and 
    live1:
        live %0
        zjmp %:live1
        fork %5
end:
