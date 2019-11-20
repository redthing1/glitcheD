
# NoteAsm

## introduction
noteasm is the name for the language/encoding the glitched sequencer uses

## specification
`<opcode> [arg]`

### opcodes
```
NOP = 0x00, // nop
MODE = 0x01, // set mode
PLAY = 0x10, // play note
PUSH = 0x11, // push to note stack
FRAME = 0x12, // start note stack
BATCH = 0x13, // play note stack
REST = 0x14, // seek forward
BACK = 0x15, // seek back
DUR = 0x20, // set _dur
VEL = 0x21, // set _vel
BPS = 0x22, // set _bps
RET = 0x99, // ret
```

## examples

### single notes

use `PLAY` followed by a value, for example `PLAY 49` to play note 49.

### chords

use the stack functionality to play chords.
`FRAME` will tell the machine to wait for multiple notes to be added to stack.
then, use `PUSH` to add notes to the stack (execute in a row to add notes to a chord).
finally, use `BATCH` to play and mix all the notes currently in the stack.

### seeking

use `REST` and `BACK` to go forward and back in time by `_dur`, respectively.
