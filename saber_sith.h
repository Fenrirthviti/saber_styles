#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 2
#define VOLUME 1000
const unsigned int maxLedsPerStrip = 193;
#define CLASH_THRESHOLD_G 2.5 //Increase if false clashes
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SSD1306
#define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
#define IDLE_OFF_TIME 60 * 1000
#endif

#ifdef CONFIG_PROP
#include "../props/saber_sa22c_buttons.h" 
#endif

#ifdef CONFIG_PRESETS
#include "CustomStyles.h"
Preset presets[] = {
   { "TheSecond", "tracks/JFO1.wav",
    StylePtr<SithOrange>(), "Second\nSister"},
   { "JFOOrng", "tracks/JFO4.wav", 
    StylePtr<JFOOrange>(), "jfo\norange"},
   { "SmthJedi", "tracks/mars.wav",
    StylePtr<GreenResponsive>(), "green"},
   { "SmthJedi", "tracks/mars.wav",
    &style_charging, "Battery\nLevel"}
};
BladeConfig blades[] = {
 // Edit this number to actual pixels in blade.
 { 0, WS281XBladePtr<117, bladePin, Color8::GRBw, PowerPINS<bladePowerPin2, bladePowerPin3> >(), CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
