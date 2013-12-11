.thumb
.thumb_func

push {lr}
mov r0, #0x2
mov r1, #0x0
ldr r4, sub_0800445C
bl bx_r4
ldr r2, ofs_08C801A0
mov r1, #0x0
ldr r0, [r2]
ldr r4, sub_0810B958
bl bx_r4
pop {r0}
bx r0

bx_r4:
bx r4
.align 2
sub_0800445C: .word 0x0800445D
sub_0810B958: .word 0x0810B959
ofs_08C801A0: .word 0x08C801A0
