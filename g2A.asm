section .text
bits 64

default rel
global imgCvtGrayFloatToInt

imgCvtGrayFloatToInt:

    xor rax, rax          
    movss xmm1, [rel const255]
    movss xmm2, [rel const05]
    
L1:

    cmp rax, rcx
    jge EXIT
    
    movss xmm0, [rdx + rax*4]   
    mulss xmm0, xmm1  
    addss xmm0, xmm2
    cvttss2si r10d, xmm0   

    mov [r8 + rax*4], r10d      
    inc rax

    jmp L1

EXIT:

    xor eax, eax
    ret
              
section .data

    const255: dd 255.0
    const05: dd 0.5