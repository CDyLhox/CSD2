project(Eindopdracht VERSION 0.0.1)
juce_add_console_app(Eindopdracht PRODUCT_NAME "MagicBox")
target_sources(Eindopdracht  PRIVATE main.cpp callback.cpp effect.cpp tremolo.cpp delay.cpp Waveshaper.cpp timestretcher.cpp rms.cpp)
target_compile_definitions(Eindopdracht PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(Eindopdracht PRIVATE
        oscillators
        audio
	transformation

        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        #        juce::juce_recommended_warning_flags
)

target_compile_features(Eindopdracht PRIVATE cxx_std_20)
