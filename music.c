#include <windows.h>
// purpose play music of my dj productions
// windows has full 44.100 khz multichannel playback.






DWORD WINAPI MusicThread(LPVOID lpParameter)
{
    // The new thread will start here
    PlaySoundA((LPCSTR)"track1.wav", NULL, SND_FILENAME);

    return 0;
}








void PlayMusic()
{

    // Create a new thread which will start at the DoStuff function
    HANDLE hThread = CreateThread(
        NULL,    // Thread attributes
        0,       // Stack size (0 = use default)
        MusicThread, // Thread start address
        NULL,    // Parameter to pass to the thread
        0,       // Creation flags
        NULL);   // Thread id



}