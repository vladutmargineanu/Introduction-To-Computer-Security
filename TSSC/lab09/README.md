Student: Margineanu Nicolae-Vladut
Grupa: 341 C2

						Laborator 9

	Ex00
  ISC{sending_passwords_in_cleartext_is_not_smart}	
  - Am deschisWireshark, am dat open la fisierul 00-Capture1.pcap.
 Am apasat pe lupa (find) si am scris “ISC{”


	Ex01
  ISC{file_is_our_friend}	
  - Am adaugat .txt.gz si dezarhivati

	Ex02
  ISC{we_all_love_grep}	
  - sudo apt install hexedit
  - hexedit fisierul respectiv
  - grep -Ua "ISC{" 02-Hidden\ 1.png


	Ex03
  ISC{no_more_ideas_for_flags}	
  - Header corupt. FF D8 trebuie sa fie la inceput in loc de EE D9
  - Am folosi hexedit pentru schimbarea bitiilor

	Ex04
  ISC{spectrogram_for_the_win}	
  - am descarcat audacity si am folosit spectogram

	Ex05
  ISC{fileception_is_real}	
  - sudo apt install binwalk
  - binwalk -e pe poza
  - dd if=05-Idea.jpg of=flag.7z ibs=1 skip=33519
  - dezarhivare flag

DECIMAL       HEXADECIMAL     DESCRIPTION
--------------------------------------------------------------------------------
0             0x0             JPEG image data, JFIF standard 1.01
33519         0x82EF          7-zip archive data, version 0.4



	Ex06
  ISC{hidden_in_the_dark}	
  - Am transformat in html folosind:  https://pdf.online/convert-pdf-to-html
  - In imaginea HTML aparea flagul fara bara neagra de deasupra.
 
	Ex07
  ISC{what_were_you_waiting_for}	
  - Am despartit in frame-uri si am folosit 
  https://ezgif.com/split/ezgif-1-fd1ffb302d59.gif
  sa iau codul QR si l-am scanat cu telefonul


	Ex08
  ISC{keycap}	
  - Tool-ul folosit este Wireshark si la campul de leftover capture data se schimba niste octeti
 (odata la cateva pachete). Se iau octetii respectivi si se cauta corespondenta in tabelul de
 la pagina 53 din documentatie.




