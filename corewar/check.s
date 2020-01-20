.name "Check !"
.comment "en fait C forker !"

start:
    live %1
    live %1
    live %1
    live %1
    live %1
    live %1
    live %1
    live %1
    ld %0, r1
    zjmp %4
    xor r3, r3, r3
end:
