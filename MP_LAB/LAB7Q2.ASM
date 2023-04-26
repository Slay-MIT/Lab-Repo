Printstr macro msg
     LEA DX, msg
     MOV AH, 09H
     INT 21H
endm

printele macro
     MOV AH, 02H
     INT 21H
endm


Data Segment
     Array dB 10H, 26H, 88H, 90H, 50H, 60H, 28H, 8H, 18H, 40H
     Min dB ?
     msg1 dB "Smallest Element: $"
Data ends                                                                                                    
Code Segment                                                                                                                                                                                                                                    
Assume CS:Code, DS:Data
Start:      MOV AX, Data
            MOV DS, AX

            LEA SI, Array
            MOV AL, [SI]
            MOV CX, 9H

      Back: INC SI
            CMP AL, [SI]
            JB Next
            MOV AL, [SI]

      Next: Loop Back

            MOV Min, AL
            Printstr msg1
            MOV AH, 0H
            MOV AH, AL

            MOV CL, 04H
            SHR AH, CL
            AND AH, 0FH
            ADD AH, 30H
            MOV DL, AH
            printele

            MOV AH, Min                             
            AND AH, 0FH
            ADD AH, 30H
            MOV DL, AH
            printele

            MOV AH, 4CH
            INT 21H
code ends
end start
                      


         
