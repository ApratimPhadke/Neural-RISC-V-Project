.section .text
.global _start
_start:
  # Set up stack pointer
  li sp, 0x4000
  # Call main function
  jal ra, main
  # If main returns, loop forever
1:
  j 1b
