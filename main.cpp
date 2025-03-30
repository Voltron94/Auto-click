#include <iostream>
#include <windows.h>
#include <ctype.h>

int main() 
{
    bool open = true;
    bool useMacro = true;
    int speed = 7; // multiplied by 2 to get the true speed, in ms

    INPUT input;    
    input.type = INPUT_MOUSE;
    
    std::cout << "Touch : "
    << "\n ! From the first click the auto click will start !"
    << "\n Press F : pause the program"
    << "\n F + click : restart the program"
    << "\n P : Close the program"
    << std::endl;

    Sleep(4000); 
    FreeConsole();  

    while(open)
    {
        if(useMacro) 
        {
            for (int key = 0; key <= 256; key++) 
            {  
                if (GetAsyncKeyState(key) & 0b1)  
                { 
                    if (key == 'F')
                    { 
                        std::cout << "F \n";
                        useMacro = !useMacro;
                    }
                    if (key == VK_LBUTTON)
                    {
                        input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN; 
                        SendInput(1, &input, sizeof(INPUT));                
                        Sleep(speed);

                        input.mi.dwFlags = MOUSEEVENTF_LEFTUP; 
                        SendInput(1, &input, sizeof(INPUT));    
                        Sleep(speed);
                    }
                }
            }
        }
        else
        {      
                for (int key = 0; key <= 256; key++)
                {
                    if (GetAsyncKeyState(key) & 0b1)  
                    { 
                        if (key == 'F'){ 
                            std::cout << "F \n";
                            useMacro = true;
                        }

                        if(key == 'P'){
                            std::cout << "P \n";
                            open = !open;
                        }
                    }
                }
            }
    }
}  
    

//  Virtual key List https://learn.microsoft.com/fr-fr/windows/win32/inputdev/virtual-key-codes
/*
    if (std::isupper(key))
        std::cout << char(key) << std::endl;  Utile a un key logger

    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0); //Obselète, problème possible

    Send input explication :
    SendInput(1, &input, sizeof(INPUT)); 
    UINT SendInput(
        UINT    cInputs,      // Nombre d'événements d'entrée
        LPINPUT pInputs,      // Tableau de structures INPUT
        int     cbSize        // Taille de la structure INPUT
    );
    &input par référence, par copie on ne modifirais pas input donc erreur

    Retrouvable sur documentation offciel de microsoft
*/
