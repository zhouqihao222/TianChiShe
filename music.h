#ifndef MUSIC_H
#define MUSIC_H

#pragma once
#include <windows.h>
#include<ctime>
#include<string>
#include<Mmsystem.h>
#include <stdio.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
class music
{
    MCI_OPEN_PARMS mciOP;
    DWORD music_timeing;
public:
    music(string path);
    ~music();
    DWORD get_muisic_pos();


    void PlayMusic()
    {
        if (music_timeing == get_muisic_pos())
        {
            mciSendCommand(mciOP.wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, NULL);
            MCI_PLAY_PARMS play;//定义播放结构题变量
            mciSendCommand(mciOP.wDeviceID, MCI_PLAY, MCI_NOTIFY, DWORD_PTR(&play));
        }
    }
};

#endif // MUSIC_H
