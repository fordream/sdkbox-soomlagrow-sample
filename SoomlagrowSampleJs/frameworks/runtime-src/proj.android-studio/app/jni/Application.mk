APP_STL := gnustl_static

# Uncomment this line to compile to armeabi-v7a, your application will run faster but support less devices
#APP_ABI

APP_CPPFLAGS := -frtti -DCC_ENABLE_CHIPMUNK_INTEGRATION=1 -std=c++11 -fsigned-char
APP_LDFLAGS := -latomic

USE_ARM_MODE := 1


APP_CPPFLAGS += -DCOCOS2D_DEBUG=1
APP_OPTIM := debug

APP_CPPFLAGS += -DNDEBUG
APP_OPTIM := release

APP_PLATFORM := android-9 android-15
