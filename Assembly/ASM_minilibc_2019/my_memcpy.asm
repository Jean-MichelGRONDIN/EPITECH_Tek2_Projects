BITS 64

section .text
GLOBAL memcpy

memcpy:
    push rbp
    mov rbp, rsp
    xor rax, rax

my_loop:
    cmp rax, rdx
    je end

    mov cl, [rsi + rax]
    mov [rdi + rax], cl
    inc rax

    jmp my_loop

end:
    mov rax, rdi
    leave
    ret