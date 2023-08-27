		AREA RESET,DATA,READONLY
		EXPORT __Vectors
__Vectors
		DCD 0x10001000
		DCD Reset_Handler
		ALIGN
		AREA mycode,CODE,READONLY
		ENTRY
		EXPORT Reset_Handler
Reset_Handler
		LDR R0,=NUM
		LDR R1,[R0]
		LDR R2,= DEST
		MOV R3,#0
UP 		CMP R1,#0xA
		BCC STORE
		SUB R1,#0xA
		ADD R3,#1
		B UP
STORE   STR R1,[R2],#4
		MOV R1,R3
		MOV R3,#0
		CMP R3,R1
		BCC UP
		LDR R4,=DEST
		SUB R5,R2,R4
		SUB R5,#4
LOOP 	LDR R6,[R4]
        ADD R6,#0x30
		STR R6,[R4],#4
		SUBS R5,#4
		BCS LOOP
STOP	
		B STOP
NUM DCD 0xA1
		AREA mydata,DATA,READWRITE
DEST DCD 0,0
		END