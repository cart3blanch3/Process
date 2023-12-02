#include <windows.h>
#include <stdio.h>

int main() {
    // ����������� ���������� ��� ������� �������� ��������
    STARTUPINFO si;               // ��������� ��� ��������� ���������� ������������ ��������
    PROCESS_INFORMATION pi;       // ��������� ��� ��������� ���������� � ��������� ��������

    // ���������� ��������� STARTUPINFO
    ZeroMemory(&si, sizeof(si));   // ������������� ��������� ������
    si.cb = sizeof(si);            // ��������� ������� ���������

    // ���������� ��������� PROCESS_INFORMATION ������
    ZeroMemory(&pi, sizeof(pi));

    // �������� ������ ��������
    // lpApplicationName: ���� � ������������ �����, ������� ����������� (� ������ ������, ���� � Child.exe).
    // lpCommandLine: ��������� ������ ��� ������� �������� (���� lpApplicationName �� �����, �� ������������ ��� ����).
    // lpProcessAttributes: ������ �������� (������ NULL).
    // lpThreadAttributes: ������ ������� (������ NULL).
    // bInheritHandles: ����������, ����� �� ������������� ����������� �� ������������� ��������.
    // dwCreationFlags: ����� ��� �������� �������� (������ 0).
    // lpEnvironment: ���������� ��������� (������ NULL, ������������ ���������� ��������� �������� ��������).
    // lpCurrentDirectory: ������� ������� �������� (������ NULL, ������������ ������� �������).
    // lpStartupInfo: ��������� STARTUPINFO � ����������� �������� (��������� ����).
    // lpProcessInformation: ��������� PROCESS_INFORMATION ��� ��������� ���������� � ��������� ��������.

    if (CreateProcess(L"D:\\OperationalSystems\\Lab2\\Process\\x64\\Release\\Child.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        // �������� ���������� ��������
        WaitForSingleObject(pi.hProcess, INFINITE);

        // �������� ������������ �������� � ������
        CloseHandle(pi.hProcess);  // �������� ����������� ��������
        CloseHandle(pi.hThread);   // �������� ����������� ������

        // ����� ���������
        printf("Bye\n");
    }
    else {
        printf("������ ��� �������� ��������\n");
    }

    return 0;
}
