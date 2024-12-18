project(soundingSynth VERSION 0.0.1)
juce_add_console_app(soundingSynth PRODUCT_NAME "example")
target_sources(soundingSynth PRIVATE main.cpp audioToFile.cpp oscillator.cpp sine.cpp square.cpp saw.cpp callback.cpp melody.cpp synth.cpp organSynth.cpp additiveSynth.cpp)
target_compile_definitions(soundingSynth PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(soundingSynth
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(soundingSynth PRIVATE cxx_std_20)
