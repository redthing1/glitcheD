cmake_minimum_required(VERSION 3.15)
project(glitched)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")

add_executable(glitched
        main.cpp
        defs.h
        misc/songs.h
        synth/Oscillator.cpp
        synth/Oscillator.h
        synth/SaltSynth.cpp
        synth/SaltSynth.h
        synth/mod/Envelope.cpp
        synth/mod/Envelope.h
        synth/Filter.cpp
        synth/Filter.h
        synth/mod/Parameter.h
        synth/mod/Parameter.cpp
        synth/mod/LFO.cpp
        synth/mod/LFO.h
        synth/effects/Effect.h
        synth/effects/Overdrive.cpp
        synth/effects/Overdrive.h
        track/NoteMachine.cpp
        track/NoteMachine.h
        track/WaveHelper.cpp
        track/WaveHelper.h
        util/AudioFile.cpp
        util/AudioFile.h
        util/Tuning.cpp
        util/Tuning.h
        synth/effects/Delay.cpp
        synth/effects/Delay.h synth/Instrument.h grain/SandSynth.cpp grain/SandSynth.h util/StereoSample.cpp util/StereoSample.h util/ConfigHelper.h track/NasmAssembler.cpp track/NasmAssembler.h)