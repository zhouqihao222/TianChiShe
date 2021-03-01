#include "music.h"

music::music(string path)// "C:\\Users\\ASUS\\source\\repos\\ConsoleApplication2\\bgm1.wav"
{
    mciOP.lpstrElementName = (wchar_t *)path.c_str();  //设置打开的文件的名称
    mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOP);
    MCI_SET_PARMS mciSet;
    mciSet.dwTimeFormat = MCI_FORMAT_MILLISECONDS; //设置时间单位为毫秒
    mciSendCommand(mciOP.wDeviceID, MCI_SET, MCI_SET_TIME_FORMAT, (DWORD)(LPVOID)&mciSet);

    mciSendCommand(mciOP.wDeviceID, MCI_SEEK, MCI_SEEK_TO_END, NULL);
    music_timeing = get_muisic_pos();
}

DWORD music::get_muisic_pos()
{
    MCI_STATUS_PARMS mciStatus;
    mciStatus.dwItem = MCI_STATUS_POSITION;
    DWORD sta1Return = mciSendCommand(mciOP.wDeviceID, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)(LPVOID)&mciStatus);
    DWORD music_timeing = mciStatus.dwReturn; //音乐当前播放时间
    return music_timeing;
}
