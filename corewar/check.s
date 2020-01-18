.name "Check !"
.comment "en fait C forker !"

st r3, :end
start:
sti r1, %:livelab, %1
start1:
sti r1, %:livelab1, %1
ld %12345, r3
st r3, :end
st r3, :start
st r3, :start1
ld %0, r2
fork %:livelab1
fork %:livelab
fork %:livelab
fork %:livelab1
livelab:
    live %123
    zjmp %:livelab
livelab1:
    live %123
    zjmp %:livelab1

end:
