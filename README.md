
# glitched

a glitchy synth and sequencer program

## build

the `cmake` tool is used to assist in buildfile generation

```
mkdir build
cd build
cmake ..
make
```

a binary `./glitched` should be output

## playing

currently `glitched` runs as an offline synthesizer, meaning that it computes its output when run and then writes it to disk to a WAV file.

program inputs for the sequencers are read in the NoteAsm binary format.

the program also comes with a very basic built-in assembler to compile NoteAsm text programs to binaries.

### examples

### general usage

```
 Usage:
  ./glitched <engine> <input> <output>
```

#### assemble an input file

`in.nasm`:

```
vel 96 # set velocity
dur 24 # set duration
bps 48 # set beats per second

dur 16
play 49
play 51
play 53

ret
```

assemble with:
```sh
./glitched nasm in.nasm notes.bin
```
this will create `notes.bin` containing our output binary.

#### run a binary in the sequencer

this will read the binary we just produced using the assembler and run it through the `salt` synthesis engine and output audio to `out.wav`.
```sh
./glitched salt notes.bin out.wav
```

### sequencer

the sequencer operates by executing NoteAsm instructions in a virtual machine and mixing the output into audio buffers.

read the page on [NoteAsm](doc/noteasm.md) for information on NoteAsm.

