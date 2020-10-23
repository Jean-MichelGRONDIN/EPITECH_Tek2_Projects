BITS 64

section .text
GLOBAL strlen

strlen:
    push rbp
    mov rbp, rsp
    xor rax, rax


my_loop:
    mov cl, [rdi + rax]
    cmp cl, 0
    je end

    inc rax

    jmp my_loop

end:
    leave
    ret