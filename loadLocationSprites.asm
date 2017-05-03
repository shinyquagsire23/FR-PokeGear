.text
.align 2
.thumb
.thumb_func
.global LoadLocationSprites

start:
		push {r4-r7,lr}
		mov r6, r9
		mov r5, r8
		push {r5,r6}
		add sp, #-0x8
		mov r6, #0x0
		mov r7, #0x0
ret2:	mov r5, #0x0
		lsl r0, r7, #0x10
		mov r8, r0
		add r1, r7, #0x1
		mov r9, r1
ret3:	lsl r0, r5, #0x10
		asr r0, r0, #0x10
		ldr r2, mapVars
		ldr r2, [r2]
		ldrb r2, [r2, #0x6]
		lsl r2, r2, #0x1
		mov r1, r8
		asr r1, r1, #0x10
		ldr r3, branch1
		bl bx_r3
		lsl r4, r0, #0x18
		lsr r4, r4, #0x18
		cmp r4, #0x3A
		beq skipchecks
		cmp r4, #0x49
		beq skipchecks
		cmp r4, #0x4A
		beq skipchecks
		cmp r4, #0x4B
		beq skipchecks
		lsl r0, r5, #0x10
		asr r0, r0, #0x10
		ldr r2, mapVars
		ldr r2, [r2]
		ldrb r2, [r2, #0x6]
		lsl r2, r2, #0x1
		add r2, #0x1
		mov r1, r8
		asr r1, r1, #0x10
		ldr r3, branch1
		bl bx_r3
		lsl r4, r0, #0x18
		lsr r4, r4, #0x18
		cmp r4, #0xD5
		beq nope
		cmp r4, #0x51
		beq whirl
/*		cmp r4, #0x8D
		bne skipchecks
		ldr r0, caveflag
		ldr r3, checkflag
		bl bx_r3
		lsl r0, r0, #0x18
		cmp r0, #0x0
		beq nope*/
skipchecks:	mov r0, #0xA
		str r0, [sp]
		add r0, r6, #0x0
		add r1, r5, #0x0
		add r2, r7, #0x0
		add r3, r6, #0x0
		add r3, #0x23
		lsl r3, r3, #0x18
		lsr r3, r3, #0x18
		bl start2
		add r0, r4, #0x0
		ldr r3, branch2
		bl bx_r3
		lsl r0, r0, #0x18
		lsr r0, r0, #0x18
		cmp r0, #0x2
		beq skipframeswitch
		ldr r0, mapVars
		ldr r0, [r0]
		ldr r0, [r0, #0xC]
		add r0, #0x40
		lsl r1, r6, #0x2
		add r0, r0, r1
		ldr r0, [r0]
		mov r1, #0x1
		ldr r3, somebranch
		bl bx_r3
skipframeswitch:	add r0, r6, #0x1
		lsl r0, r0, #0x18
		lsr r6, r0, #0x18
nope:	add r5, #0x1
		lsl r5, r5, #0x10
		lsr r5, r5, #0x10
		cmp r5, #0x15
		bls ret3
		mov r4, r9
		lsl r7, r4, #0x10
		lsr r7, r7, #0x10
		cmp r7, #0xE
		bls ret2
		add sp, #0x8
		pop {r3,r4}
		mov r8, r3
		mov r9, r4
		pop {r4-r7}
		pop {r0}
		bx r0
		
whirl:	cmp r5, #0x2
		bne nope
		cmp r7, #0x9
		bne nope
		b skipchecks
		
.align 2
mapVars:		.word 0x0203A144
caveflag:		.word 0x00000000
checkflag:		.word 0x0809D791
somebranch:		.word 0x080081A9
branch1:		.word 0x0812386D
branch2:		.word 0x08123D59

start2:		push {r4-r7,lr}
		mov r7, r10
		mov r6, r9
		mov r5, r8
		push {r5-r7}
		add sp, #-0x28
		ldr r5, [sp, #0x48]
		lsl r0, r0, #0x18
		lsr r0, r0, #0x18
		mov r10, r0
		lsl r1, r1, #0x10
		lsr r1, r1, #0x10
		mov r8, r1
		lsl r2, r2, #0x10
		lsr r2, r2, #0x10
		mov r9, r2
		lsl r4, r3, #0x18
		lsr r4, r4, #0x18
		lsl r5, r5, #0x18
		lsr r5, r5, #0x18
		mov r7, #0x0
		ldr r0, mapVars2
		ldr r0, [r0]
		ldr r0, [r0, #0xC]
		str r0, [sp, #0x18]
		mov r2, #0x40
		add r0, sp, #0x18
		lsl r1, r4, #0x10
		orr r1, r2
		str r1, [r0, #0x4]
		ldr r1, paladdr
		str r1, [sp, #0x20]
		ldr r2, val1
		add r6, sp, #0x20
		ldr r1, [r6, #0x4]
		and r1, r2
		orr r1, r5
		str r1, [r6, #0x4]
		mov r1, sp
		strh r4, [r1]
		strh r5, [r1, #0x2]
		ldr r1, oamdata
		str r1, [sp, #0x4]
		ldr r1, framedata
		str r1, [sp, #0x8]
		str r7, [sp, #0xC]
		ldr r1, animdata
		str r1, [sp, #0x10]
		ldr r1, animroutine
		str r1, [sp, #0x14]
		ldr r3, branch3
		bl bx_r3
		add r0, r6, #0x0
		ldr r3, branch4
		bl bx_r3
		mov r0, r8
		lsl r0, r0, #0x10
		asr r0, r0, #0x10
		mov r1, r9
		lsl r1, r1, #0x10
		asr r1, r1, #0x10
		ldr r2, mapVars2
		ldr r2, [r2]
		ldrb r2, [r2, #0x6]
		lsl r2, r2, #0x1
		ldr r3, branch5
		bl bx_r3
		lsl r0, r0, #0x18
		lsr r5, r0, #0x18
		cmp r5, #0x1C
		beq whirl2
		add r0, r5, #0x0
		ldr r3, branch6
		bl bx_r3
		lsl r0, r0, #0x18
		lsr r0, r0, #0x18
		cmp r0, #0x2
		beq skipnextcheck
		cmp r0, #0x3
		bne skipthisbit
skipnextcheck:	cmp r5, #0x3A
		beq skipthisbit
		cmp r5, #0x49
		beq skipthisbit
		cmp r5, #0x4A
		beq skipthisbit
		cmp r5, #0x4B
		beq skipthisbit
		cmp r5, #0x64
		beq skipthisbit
		mov r7, #0x2
skipthisbit:	mov r3, r8
		lsl r1, r3, #0x3
		lsl r0, r7, #0x10
		asr r0, r0, #0x10
		add r0, #0x1C
		add r1, r1, r0
		ldr r2, mapVars2
		ldr r2, [r2]
		ldrb r2, [r2, #0x7]
		add r2, #0x1
		lsl r2, r2, #0x3
		add r1, r1, r2
		lsl r1, r1, #0x10
		asr r1, r1, #0x10
		mov r3, r9
		lsl r2, r3, #0x3
		add r2, r2, r0
		lsl r2, r2, #0x10
		asr r2, r2, #0x10
		mov r0, sp
		mov r3, #0x3
		ldr r4, branch7
		bl bx_r4
		lsl r0, r0, #0x18
		lsr r0, r0, #0x18
		ldr r2, mapVars2
		ldr r2, [r2]
		ldr r2, [r2, #0xC]
		add r2, #0x40
		mov r1, r10
		lsl r3, r1, #0x2
		add r2, r2, r3
		lsl r1, r0, #0x4
		add r1, r1, r0
		lsl r1, r1, #0x2
		ldr r0, oammem
		add r1, r1, r0
		str r1, [r2]
		add sp, #0x28
		pop {r3-r5}
		mov r8, r3
		mov r9, r4
		mov r10, r5
		pop {r4-r7}
		pop {r0}
		bx r0
		
whirl2:	mov r7, #0x4
		b skipthisbit
		
bx_r3:	bx r3

bx_r4:	bx r4

.align 2
paladdr:		.word mapDotsPalData
oamdata:		.word mapDotsOAMData
framedata:		.word mapDotsFrameData
animdata:		.word 0x082EC6A8
animroutine:	.word 0x08007429
val1:			.word 0xFFFF0000
mapVars2:		.word 0x0203A144
branch3:		.word 0x080084F9
branch4:		.word 0x08008745
branch5:		.word 0x0812386D
branch6:		.word 0x08123D59
branch7:		.word 0x08006DF5
oammem:			.word 0x02020630
