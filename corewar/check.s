.name "Check !"
.comment "en fait C forker !"

start:
    fork %:end
    live %41231
    ld %1073741824 r2
    ld %0, r1
    zjmp %4
    xor r3, r3, r3
    zjmp %4
end:
