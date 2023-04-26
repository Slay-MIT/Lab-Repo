Data Segment
     Array dW 0020H, 0030H, 0010H, 0012H, 0016H, 0040H, 1234H, 0026H, 0033H
     Num dW 34H
     notfound dB "Not Found $"
     found dB "Found $"
     msg1 dB 10,13, "$"
Data ends
Code Segment
Assume CS:Code, DS:Data

    Start: MOV AX, Data
           MOV DS, AX
           MOV CX, 12H
           MOV AX, Num
           LEA SI, Array
           DEC SI
     Back: INC SI
           CMP AX, [SI]
           LoopNZ Back
           JCXZ Exit0
           LEA DX, found
           JMP Exit2

    Exit0: LEA DX, notfound
           JMP Exit2

   ; Exit1: LEA DX, found
          ; JMP Exit2

    Exit2: MOV AH, 09H
           INT 21H
           MOV AH, 4CH
           INT 21H
Code ends
end start
                    
