BITS 64

section .text
GLOBAL memset

memset:
    push rbp
    mov rbp, rsp
    xor rax, rax

my_loop:
    mov cl, [rdi + rax]
    cmp cl, 0
    je end

    cmp rax, rdx
    je end

    mov [rdi + rax], sil
    inc rax

    jmp my_loop

end:
    mov rax, rdi
    leave
    ret