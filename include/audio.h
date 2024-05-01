#pragma once

#include <asndlib.h>
#include <mp3player.h>

namespace GDWii {
    class AudioEngine {
    public:
        AudioEngine() {
            ASND_Init();
            MP3Player_Init();
        }

        void PlayMP3(const uint8_t* buffer, s32 length) {
            MP3Player_PlayBuffer(buffer, length, NULL);
        }

        void SetVolume(u32 volume) {
            MP3Player_Volume(volume);
        }
    };
}