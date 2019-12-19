//******************************************************************************
//
//
//      DirectXTKAudio
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
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
        //  �R���X�g���N�^
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
        //  �f�X�g���N�^
        //--------------------------------
        DXTKAudio::~DXTKAudio()
        {
            audioEngine.reset();
        }

        //--------------------------------
        //  �I�[�f�B�I�G���W���̃��Z�b�g
        //--------------------------------
        bool DXTKAudio::reset()
        {
            return audioEngine->Reset();
        }

        //--------------------------------
        //  ���y�Ǎ�
        //--------------------------------
        void DXTKAudio::musicLoad(int trackNo, const wchar_t* waveFileName, float volume)
        {
            if (musicInst[trackNo]) musicInst[trackNo].reset();
            music[trackNo].reset(new SoundEffect(audioEngine.get(), waveFileName));
            musicVolume[trackNo] = volume;
        }

        //--------------------------------
        //  ���y���
        //--------------------------------
        void DXTKAudio::musicUnload(int trackNo)
        {
            if (musicInst[trackNo]) musicInst[trackNo].reset();
            music[trackNo].reset(nullptr);
        }

        //--------------------------------
        //  ���y�Đ�
        //--------------------------------
        void DXTKAudio::musicPlay(int trackNo, bool isLoop)
        {
            if (!music[trackNo]) return;
            musicInst[trackNo] = music[trackNo]->CreateInstance();
            musicInst[trackNo]->Play(isLoop);
            musicInst[trackNo]->SetVolume(musicVolume[trackNo]);
        }

        //--------------------------------
        //  ���y��~
        //--------------------------------
        void DXTKAudio::musicStop(int trackNo)
        {
            if (!musicInst[trackNo]) return;
            musicInst[trackNo]->Stop();
        }

        //--------------------------------
        //  ���y�ꎞ��~
        //--------------------------------
        void DXTKAudio::musicPause(int trackNo)
        {
            if (!musicInst[trackNo]) return;
            musicInst[trackNo]->Pause();
        }

        //--------------------------------
        //  ���y�ĊJ
        //--------------------------------
        void DXTKAudio::musicResume(int trackNo)
        {
            if (!musicInst[trackNo]) return;
            musicInst[trackNo]->Resume();
        }

        //--------------------------------
        //  ���y�{�����[���ݒ�
        //--------------------------------
        void DXTKAudio::musicSetVolume(int trackNo, float volume)
        {
            if (!musicInst[trackNo]) return;
            musicInst[trackNo]->SetVolume(volume);
        }

        //--------------------------------
        //  SoundState�̎擾
        //--------------------------------
        DirectX::SoundState DXTKAudio::musicGetState(int trackNo)
        {
            return musicInst[trackNo]->GetState();
        }

        //--------------------------------
        //  ���[�v�̗L���̎擾
        //--------------------------------
        bool DXTKAudio::musicIsLooped(int trackNo)
        {
            return musicInst[trackNo]->IsLooped();
        }

        //--------------------------------
        //  pan�̐ݒ�
        //--------------------------------
        void DXTKAudio::musicSetPan(int trackNo, float pan)
        {
            return musicInst[trackNo]->SetPan(pan);
        }

        //--------------------------------
        //  pitch�̐ݒ�
        //--------------------------------
        void DXTKAudio::musicSetPitch(int trackNo, float pitch)
        {
            return musicInst[trackNo]->SetPitch(pitch);
        }

        //--------------------------------
        //  �t�H�[�}�b�g�̎擾
        //--------------------------------
        const WAVEFORMATEX* DXTKAudio::musicGetFormat(int trackNo)
        {
            return music[trackNo]->GetFormat();
        }

        //--------------------------------
        //  ���y���g�p�����ǂ���
        //--------------------------------
        bool DXTKAudio::musicIsInUse(int trackNo)
        {
            return music[trackNo]->IsInUse();
        }




        //--------------------------------
        //  ���ʉ��̓ǂݍ��݁ixwb�t�@�C���j
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
        //  ���ʉ��̍Đ�
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
        //  ���ʉ��̃{�����[���ݒ�
        //--------------------------------
        void DXTKAudio::soundSetVolume(int trackNo, float vol)
        {
            soundVolume[trackNo] = vol;
        }
    }
}

//******************************************************************************