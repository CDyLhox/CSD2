project(elecflute VERSION 0.0.1)

if(MSVC)
    find_package(liblo CONFIG REQUIRED)
else()
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(LIBLO REQUIRED IMPORTED_TARGET liblo)
endif()

juce_add_console_app(elecflute PRODUCT_NAME "MagicBox")
target_sources(elecflute PRIVATE 
    main.cpp
    callback.cpp 
    effect.cpp 
    delay.cpp 
    Waveshaper.cpp 
    allpass.cpp
    rms.cpp)

target_compile_definitions(elecflute PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

add_library(tools
    tools/interpolation.cpp
    tools/osc.cpp
    tools/uiutility.cpp
)

target_include_directories(tools PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/tools
)

target_link_libraries(tools PUBLIC
    PkgConfig::LIBLO
)


if(MSVC)  
target_link_libraries(elecflute PRIVATE
        tools

        liblo::liblo

        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        #        juce::juce_recommended_warning_flags
)

else()
    target_link_libraries(elecflute PRIVATE
        tools

        PkgConfig::LIBLO 

        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        #juce::juce_recommended_warning_flags
)
endif()


target_compile_features(elecflute PRIVATE cxx_std_20)
