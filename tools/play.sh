#!/bin/sh
# Build, boot an emulator (window + host GPU), install and launch the game.
# Usage: tools/play.sh [avd]   (default: bb_tv; e.g. bb_phone)
set -e
AVD=${1:-bb_tv}
cd "$(dirname "$0")/.."
export JAVA_HOME=${JAVA_HOME:-/opt/homebrew/opt/openjdk@17}
export ANDROID_HOME=${ANDROID_HOME:-$HOME/Library/Android/sdk}
export PATH="$ANDROID_HOME/platform-tools:$ANDROID_HOME/emulator:$PATH"

[ -d assets/data ] || tools/fetch_game_data.sh
./gradlew -q assembleDebug

if ! adb devices | grep -q '^emulator-'; then
    emulator -avd "$AVD" -gpu host >/dev/null 2>&1 &
fi
adb wait-for-device
until [ "$(adb shell getprop sys.boot_completed | tr -d '\r')" = 1 ]; do sleep 2; done

adb install -r build/outputs/apk/debug/BlipBlop-debug.apk
adb shell am start -n com.blip.blop/.Smartblip
