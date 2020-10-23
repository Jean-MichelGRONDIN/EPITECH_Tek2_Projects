BITS 64

section .text
GLOBAL strncmp

strncmp:
    push rbp
    mov rbp, rsp
    xor rax, rax

my_loop:
    cmp rax, rdx
    je end_equal

    mov cl, [rdi + rax]
    cmp cl, 0
    je end_not_equal

    mov ch, [rsi + rax]
    cmp ch, 0
    je end_not_equal

    cmp cl, ch
    je extension

    jmp end_not_equal

extension:
    cmp rax, rdx
    je end_equal
    inc rax
    jmp my_loop

end_not_equal:
    mov rcx, rax
    mov r8b, [rdi + rcx]
    mov r9b, [rsi + rcx]
    sub r8b, r9b
    movzx rax, r8b
    leave
    ret

end_equal:
    mov rax, 0
    leave
    ret