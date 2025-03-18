project(06_RMS VERSION 0.0.1)
juce_add_console_app(06_RMS PRODUCT_NAME "06_RMS")
target_sources(06_RMS PRIVATE main.cpp)
target_compile_definitions(06_RMS PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(06_RMS PRIVATE
        oscillators
        audio
	TOOLBELT
	#interpolation

        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        #        juce::juce_recommended_warning_flags
)

target_compile_features(06_RMS PRIVATE cxx_std_20)
