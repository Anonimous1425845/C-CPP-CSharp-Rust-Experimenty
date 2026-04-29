Technicky áno, je to možné pomocou procesu nazývaného cross-compilation (krížová kompilácia), ale má to jeden podstatný háčik.
Váš PC má procesor s architektúrou x86_64 (Intel/AMD), zatiaľ čo Raspberry Pi má ARM. Ak na Pi jednoducho spustíte gcc kód.c, výsledný súbor bude fungovať len na Pi a na Windowse ho nespustíte.
Aby ste na Raspberry Pi vytvorili .exe súbor pre Windows, musíte použiť špeciálny kompilátor MinGW-w64. [1] 
## Ako na to (stručný návod pre Pi):

   1. Nainštalujte krížový kompilátor:
   Na vašom Raspberry Pi otvorte terminál a zadajte:
   
   sudo apt update
   sudo apt install mingw-w64
   
   2. Skompilujte kód pre Windows:
   Namiesto klasického gcc použite verziu pre 64-bitový Windows:
   
   x86_64-w64-mingw32-gcc kód.c -o program.exe
   
   (Ak potrebujete 32-bitovú verziu, príkaz začína i686-w64-mingw32-gcc).
   3. Preneste súbor:
   Vzniknutý program.exe si pošlite do PC (napr. cez WinSCP, FileZilla alebo USB kľúč) a tam ho môžete normálne spustiť.

## Je to naozaj lepšie ako inštalácia na Windowse?
Úprimne, ak s C len začínate, krížová kompilácia prináša vlastné "peklo" (riešenie knižníc, ktoré nie sú súčasťou Windows API, môže byť zložité). [2, 3] 
Moje odporúčanie:
Ak vás Windows hnevá, skúste na ňom WSL (Windows Subsystem for Linux). Je to oficiálna funkcia Windowsu, ktorá vám do PC nainštaluje Linuxové prostredie za 5 minút. Potom tam budete mať gcc rovnako jednoducho ako na Raspberry Pi, ale kód pobeží priamo na vašom PC. [4] 
Chcete pomôcť s nastavením toho MinGW na Raspberry Pi, alebo vás zaujíma skôr to WSL?

[1] [https://stackoverflow.com](https://stackoverflow.com/questions/15986715/how-do-i-invoke-the-mingw-cross-compiler-on-linux)
[2] [https://forums.raspberrypi.com](https://forums.raspberrypi.com/viewtopic.php?t=201466)
[3] [https://blog.svgames.pl](https://blog.svgames.pl/article/cross-compiling-c-programs-for-ms-windows-using-mingw)
[4] [https://forums.raspberrypi.com](https://forums.raspberrypi.com/viewtopic.php?t=252277)
