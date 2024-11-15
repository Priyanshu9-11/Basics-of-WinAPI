#include<windows.h>

/*    Steps to create GUI
        1) WINMAIN
        2)WNDCLASSW and initialize its all members.
        3) Window procedure function(Event-driven function)
        4) Register ClassW function used to register window
        5) Create WindowW function to create window.
        6) Loop used to get message.
        */
LRESULT CALLBACK windowprocedure(HWND,UINT,WPARAM,LPARAM);
int WINAPI WinMain(HINSTANCE hint,HINSTANCE hprev,LPSTR agr,int ncmd)
{
        WNDCLASSW wc = {0};
        wc.hbrBackground = (HBRUSH)COLOR_3DFACE;
        wc.hCursor = LoadCursor(hint,IDC_ARROW);
        wc.hInstance = hint;
        wc.lpszClassName = L"Pal Cafe";
        wc.lpfnWndProc = windowprocedure;
        if (!RegisterClassW(&wc)){
                //pointer parameter
        return -1;
        }
        CreateWindowW(L"RajPal Caffe","GUI",WS_EX_OVERLAPPEDWINDOW|WS_VISIBLE,200,100,600,600,NULL,NULL,NULL,NULL);
        MSG msg = {0};
        while(GetMessageW(&msg,NULL,NULL,NULL)){
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        return 0;
}
LRESULT CALLBACK windowprocedure(HWND hnd,UINT msg,WPARAM wp,LPARAM lp)
{
    switch(msg)
    {
    case WM_CLOSE:
        if(MessageBoxW(hnd,L"Sure to Quit?","RajPal Khatre mein",MB_OKCANCEL)==IDOK){
            DestroyWindow(hnd);
        }
        break;
    default:
        return DefWindowProc(hnd,msg,wp,lp);
    }

}


