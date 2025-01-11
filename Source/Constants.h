#pragma once

namespace Constants {
    // Plugin dimensions
    inline constexpr int pluginWidth = 600;
    inline constexpr float aspectRatio = 0.75f;

    inline constexpr int pluginHeight = (pluginWidth * aspectRatio);

    inline constexpr int componentPadding = 10;

    // Rotary slider size
    inline constexpr int rotarySliderSize = 125;

    // Label settings
    inline constexpr int labelHeight = 20;
    inline constexpr int knobPadding = 10;
}