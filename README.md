
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

currently `glitched` runs as an offline synthesizer, meaning that it computes its output when run and then writes it to disk (`out.wav`).
inputs are hardcoded and thus outputs are deterministic.
this will be improved soon, allowing the user to provide NoteAsm code to make it more interesting to actually run the program on your own.

for information on NoteAsm, see `[noteasm.md](doc/noteasm.md)`


