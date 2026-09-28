#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#endif

// Kode Warna ANSI (Ungu, Hijau, Putih)
#define COLOR_RESET     "\033[0m"
#define COLOR_BOLD      "\033[1m"
#define COLOR_PURPLE    "\033[1;35m" // Ungu / Magenta Bright
#define COLOR_GREEN     "\033[1;32m" // Hijau Neon
#define COLOR_WHITE     "\033[1;37m" // Putih Terang
#define COLOR_GRAY      "\033[1;30m" // Abu-abu gelap untuk pembatas

void activateAnsi(void) {
    #ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
    }
    #endif
}

int main(void) {
    activateAnsi();

    // Garis Pemisah Ungu
    printf(COLOR_PURPLE "======================================================================\n" COLOR_RESET);
    printf(COLOR_GREEN  "                        BIODATA MAHASISWA                             \n" COLOR_RESET);
    printf(COLOR_PURPLE "======================================================================\n" COLOR_RESET);
    
    // Informasi Diri (Label Ungu, Isi Hijau/Putih)
    printf(COLOR_PURPLE "%-25s" COLOR_RESET " : " COLOR_GREEN "%s\n" COLOR_RESET, "Nama Lengkap", "Muhammad Daffa Izza Pratama Putra");
    printf(COLOR_PURPLE "%-25s" COLOR_RESET " : " COLOR_GREEN "%s\n" COLOR_RESET, "NIM", "2612793");
    printf(COLOR_PURPLE "%-25s" COLOR_RESET " : " COLOR_GREEN "%s\n" COLOR_RESET, "Program Studi", "Teknik Elektro");
    printf(COLOR_PURPLE "%-25s" COLOR_RESET " : " COLOR_GREEN "%s\n" COLOR_RESET, "Fakultas", "Fakultas Pendidikan Teknik dan Industri");
    printf(COLOR_PURPLE "%-25s" COLOR_RESET " : " COLOR_GREEN "%s\n" COLOR_RESET, "Asal Sekolah", "SMAN 1 Cileunyi");
    
    printf(COLOR_GRAY "----------------------------------------------------------------------\n" COLOR_RESET);
    
    // Sub-judul & Teks
    printf(COLOR_GREEN "Alasan Memilih Teknik Elektro:\n" COLOR_RESET);
    printf(COLOR_WHITE "  Ingin mempelajari sistem kontrol dan pemrograman mikrokontroler\n" COLOR_RESET);
    printf(COLOR_WHITE "  untuk perangkat modern.\n" COLOR_RESET);
    
    printf(COLOR_GRAY "----------------------------------------------------------------------\n" COLOR_RESET);
    
    printf(COLOR_GREEN "Mata Kuliah Favorit Semester Ini:\n" COLOR_RESET);
    printf(COLOR_PURPLE "  - Algoritma dan Pemrograman C\n" COLOR_RESET);
    
    printf(COLOR_PURPLE "======================================================================\n" COLOR_RESET);

    return 0;
}