; Hello World program in Assembler.

section .text
  global _start  ; must be declared for linker (ld)

_start:          ; tells linker entry point
  mov  edx, 26   ; message length
  mov  ecx, msg  ; move the memory address of our message string into ecx
  mov  ebx, 1    ; write to the file descriptor (stdout)
  mov  eax, 4    ; system call number (sys_write)
  int  80h       ; call kernel

  mov  ebx, 0    ; return 0 status on exit (no error)
  mov  eax, 1    ; system call number (sys_exit)
  int  80h       ; call kernel

section .data
  ; string to be printed plus 0Ah (line feed character)
  msg db 'Hello, World! (Assembler)', 0Ah
