#include <windows.h>
#include <stdio.h>

int main() {
    // Определение переменных для запуска внешнего процесса
    STARTUPINFO si;               // Структура для настройки параметров запускаемого процесса
    PROCESS_INFORMATION pi;       // Структура для получения информации о созданном процессе

    // Заполнение структуры STARTUPINFO
    ZeroMemory(&si, sizeof(si));   // Инициализация структуры нулями
    si.cb = sizeof(si);            // Установка размера структуры

    // Заполнение структуры PROCESS_INFORMATION нулями
    ZeroMemory(&pi, sizeof(pi));

    // Создание нового процесса
    // lpApplicationName: Путь к исполняемому файлу, который запускается (в данном случае, путь к Child.exe).
    // lpCommandLine: Командная строка для запуска процесса (если lpApplicationName не задан, то используется это поле).
    // lpProcessAttributes: Защита процесса (обычно NULL).
    // lpThreadAttributes: Защита потоков (обычно NULL).
    // bInheritHandles: Определяет, могут ли наследоваться дескрипторы от родительского процесса.
    // dwCreationFlags: Флаги для создания процесса (обычно 0).
    // lpEnvironment: Переменные окружения (обычно NULL, используются переменные окружения текущего процесса).
    // lpCurrentDirectory: Рабочий каталог процесса (обычно NULL, используется текущий каталог).
    // lpStartupInfo: Структура STARTUPINFO с настройками процесса (заполнена выше).
    // lpProcessInformation: Структура PROCESS_INFORMATION для получения информации о созданном процессе.

    if (CreateProcess(L"D:\\OperationalSystems\\Lab2\\Process\\x64\\Release\\Child.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        // Ожидание завершения процесса
        WaitForSingleObject(pi.hProcess, INFINITE);

        // Закрытие дескрипторов процесса и потока
        CloseHandle(pi.hProcess);  // Закрытие дескриптора процесса
        CloseHandle(pi.hThread);   // Закрытие дескриптора потока

        // Вывод сообщения
        printf("Bye\n");
    }
    else {
        printf("Ошибка при создании процесса\n");
    }

    return 0;
}
