cmake_minimum_required(VERSION 3.15)
project(glitched)

set(CMAKE_CXX_STANDARD 17)

add_executable(glitched
        main.cpp
        constants.h
        util/AudioFile.cpp
        util/AudioFile.h
        track/SongWriter.cpp
        track/SongWriter.h
        synth/Oscillator.cpp
        synth/Oscillator.h util/Tuning.cpp util/Tuning.h synth/Instrument.cpp synth/Instrument.h synth/mod/Envelope.cpp synth/mod/Envelope.h track/NoteMachine.cpp track/NoteMachine.h misc/songs.h synth/Filter.cpp synth/Filter.h synth/mod/Parameter.h synth/mod/LFO.cpp synth/mod/LFO.h synth/mod/Parameter.cpp synth/effects/Effect.h synth/effects/Overdrive.cpp synth/effects/Overdrive.h)