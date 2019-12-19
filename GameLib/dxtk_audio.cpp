//******************************************************************************
//
//
//      DirectXTKAudio
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "dxtk_audio.h"

namespace GameLib
{
    namespace audio
    {
        using DirectX::AUDIO_ENGINE_FLAGS;
        using DirectX::AudioEngine;
        using DirectX::SoundEffect;
        using DirectX::WaveBank;

        using DirectX::AudioEngine_Default;
        using DirectX::AudioEngine_Debug;

        //--------------------------------
        //  コンストラクタ
        //--------------------------------
        DXTKAudio::DXTKAudio()
        {
            // Create DirectXTK for Audio objects
            AUDIO_ENGINE_FLAGS eflags = AudioEngine_Default;
#ifdef _DEBUG
            eflags = eflags | AudioEngine_Debug;
#endif
            audioEngine.reset(new AudioEngine(eflags));
            for (auto &p : musicVolume) p = 1.0f;
            for (auto &p : soundVolume) p = 1.0f;
        }

        //--------------------------------
        //  デストラクタ
        //--------------------------------
        DXTKAudio::~DXTKAudio()
        {
            audioEngine.reset();
        }

        //--------------------------------
        //  オーディオエンジンのリセット
        //--------------------------------
        bool DXTKAudio::reset()
        {
            return audioEngine->Reset();
        }

        //--------------------------------
        //  音楽読込
        //--------------------------------
        void DXTKAudio::musicLoad(int trackNo, const wchar_t* waveFileName, float volume)
        {
            if (musicInst[trackNo]) musicInst[trackNo].reset();
            music[trackNo].reset(new SoundEffect(audioEngine.get(), waveFileName));
            musicVolume[trackNo] = volume;
        }

        //--------------------------------
        //  音楽解放
        //--------------------------------
        void DXTKAudio::musicUnload(int trackNo)
        {
            if (musicInst[trackNo]) musicInst[trackNo].reset();
            music[trackNo].reset(nullptr);
        }

        //--------------------------------
        //  音楽再生
        //--------------------------------
        void DXTKAudio::musicPlay(int trackNo, bool isLoop)
        {
            if (!music[trackNo]) return;
            musicInst[trackNo] = music[trackNo]->CreateInstance();
            musicInst[trackNo]->Play(isLoop);
            musicInst[trackNo]->SetVolume(musicVolume[trackNo]);
        }

        //--------------------------------
        //  音楽停止
        //--------------------------------
        void DXTKAudio::musicStop(int trackNo)
        {
            if (!musicInst[trackNo]) return;
            musicInst[trackNo]->Stop();
        }

        //--------------------------------
        //  音楽一時停止
        //--------------------------------
        void DXTKAudio::musicPause(int trackNo)
        {
            if (!musicInst[trackNo]) return;
            musicInst[trackNo]->Pause();
        }

        //--------------------------------
        //  音楽再開
        //--------------------------------
        void DXTKAudio::musicResume(int trackNo)
        {
            if (!musicInst[trackNo]) return;
            musicInst[trackNo]->Resume();
        }

        //--------------------------------
        //  音楽ボリューム設定
        //--------------------------------
        void DXTKAudio::musicSetVolume(int trackNo, float volume)
        {
            if (!musicInst[trackNo]) return;
            musicInst[trackNo]->SetVolume(volume);
        }

        //--------------------------------
        //  SoundStateの取得
        //--------------------------------
        DirectX::SoundState DXTKAudio::musicGetState(int trackNo)
        {
            return musicInst[trackNo]->GetState();
        }

        //--------------------------------
        //  ループの有無の取得
        //--------------------------------
        bool DXTKAudio::musicIsLooped(int trackNo)
        {
            return musicInst[trackNo]->IsLooped();
        }

        //--------------------------------
        //  panの設定
        //--------------------------------
        void DXTKAudio::musicSetPan(int trackNo, float pan)
        {
            return musicInst[trackNo]->SetPan(pan);
        }

        //--------------------------------
        //  pitchの設定
        //--------------------------------
        void DXTKAudio::musicSetPitch(int trackNo, float pitch)
        {
            return musicInst[trackNo]->SetPitch(pitch);
        }

        //--------------------------------
        //  フォーマットの取得
        //--------------------------------
        const WAVEFORMATEX* DXTKAudio::musicGetFormat(int trackNo)
        {
            return music[trackNo]->GetFormat();
        }

        //--------------------------------
        //  音楽が使用中かどうか
        //--------------------------------
        bool DXTKAudio::musicIsInUse(int trackNo)
        {
            return music[trackNo]->IsInUse();
        }




        //--------------------------------
        //  効果音の読み込み（xwbファイル）
        //--------------------------------
        void DXTKAudio::soundLoad(const wchar_t* xwbFileName, float volume)
        {
            for (int i = 0; i < WAVE_FILE_MAX; i++)
            {
                for (int j = 0; j < WAVE_SOUND_MAX; j++)
                {
                    if (soundInst[i][j])
                    {
                        soundInst[i][j].reset();
                    }
                }
            }

            waveBank.reset(new WaveBank(audioEngine.get(), xwbFileName));

            for (auto &p : soundVolume) p = volume;
        }

        //--------------------------------
        //  効果音の再生
        //--------------------------------
        void DXTKAudio::soundPlay(int trackNo)
        {
            for (int i = 0; i < WAVE_SOUND_MAX; i++)
            {
                if (soundInst[trackNo][i])
                {
                    DirectX::SoundState state = soundInst[trackNo][i]->GetState();
                    if (state != DirectX::SoundState::STOPPED) continue;
                }
                
                soundInst[trackNo][i] = waveBank->CreateInstance(trackNo);
                if (soundInst[trackNo][i])
                {
                    soundInst[trackNo][i]->SetVolume(soundVolume[trackNo]);
                    soundInst[trackNo][i]->Play();
                    break;
                }
            }
        }

        //--------------------------------
        //  効果音のボリューム設定
        //--------------------------------
        void DXTKAudio::soundSetVolume(int trackNo, float vol)
        {
            soundVolume[trackNo] = vol;
        }
    }
}

//******************************************************************************