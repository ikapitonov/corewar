.name "Check !"
.comment "en fait C forker !"

start:
    sti r1, %:live1, %1

live1:
    live %100
    ld %0, r2
    zjmp %:live1
end:
