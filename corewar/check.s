.name "Check !"
.comment "en fait C forker !"

start:
    ld %-5, r2
    ld %-5, r3
    st r2, :end
    ldi :end, %2, r4
    st r4, 20
end:
