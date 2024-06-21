#include <Windows.h>
#include <iostream>
#include "Ripterms/Ripterms.h"

#define RIPTERMS_INJECTOR 66666

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpvReserved)  // reserved
{
    // Perform actions based on the reason for calling.
    switch (fdwReason)
    {
    case RIPTERMS_INJECTOR:
    case DLL_PROCESS_ATTACH:
    {
        // Initialize once for each new process.
        // Return FALSE to fail DLL load.

        if (!Ripterms::init(hinstDLL))
        {
            std::cin.ignore();
            FreeConsole();
            return FALSE;
        }
        std::cout << "Init success" << std::endl;
        return TRUE;
    }

    case DLL_THREAD_ATTACH:
        // Do thread-specific initialization.
        break;

    case DLL_THREAD_DETACH:
        // Do thread-specific cleanup.
        break;

    case DLL_PROCESS_DETACH:
        if (lpvReserved != nullptr)
        {
            //process termination
            Ripterms::partialClean();
            break;
        }
        // Perform any necessary cleanup.
        break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
    #include <iostream>
#include <vector>
#include <string>

// Structure représentant une base
struct Base {
    std::string player;
    int x;
    int y;
    int z;
};

// Fonction pour localiser les bases
std::vector<Base> locateBases() {
    // Exemple de bases - à remplacer par la logique de localisation réelle
    std::vector<Base> bases = {
        {"Player1", 100, 64, 200},
        {"Player2", -300, 70, 150},
        {"Player3", 500, 68, -400}
    };
    return bases;
}

void displayBases(const std::vector<Base>& bases) {
    for (const auto& base : bases) {
        std::cout << "Base de " << base.player << ": (" << base.x << ", " << base.y << ", " << base.z << ")\n";
    }
}

int main() {
    std::vector<Base> bases = locateBases();
    displayBases(bases);
    return 0;
}

}
