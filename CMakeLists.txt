cmake_minimum_required(VERSION 3.15)
project(glitched)

set(CMAKE_CXX_STANDARD 17)

add_executable(glitched

        main.cpp
        constants.h
        misc/songs.h
        synth/Oscillator.cpp
        synth/Oscillator.h
        synth/Instrument.cpp
        synth/Instrument.h
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
        track/SongWriter.cpp
        track/SongWriter.h
        util/AudioFile.cpp
        util/AudioFile.h
        util/Tuning.cpp
        util/Tuning.h
        )