cmake_minimum_required(VERSION 3.10) 
project(theScarySynth VERSION 0.0.1)
juce_add_console_app(theScarySynth PRODUCT_NAME "example")
target_sources(theScarySynth PRIVATE main.cpp audioToFile.cpp oscillator.cpp sine.cpp square.cpp saw.cpp callback.cpp melody.cpp synth.cpp organSynth.cpp additiveSynth.cpp UIUtility.cpp)
target_compile_definitions(theScarySynth PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(theScarySynth
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(theScarySynth PRIVATE cxx_std_20)
