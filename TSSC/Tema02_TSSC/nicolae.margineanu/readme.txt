Student: Margineanu Nicolae-Vladut
Grupa: 341 C2

				Tema 02 -TSSC
				
  Task 01
  
  In rezolvarea task-ului, am folosit utilitarul Wireshark si 
  am folosit Follow TCP Stream. Am marit variabila stream, pana
  am ajunj la pachetul cu cheia privata. Am salvatcheia privata intr-un fisier.
  Comenzi:
	vladutmargineanu@vladutmargineanu15:~/Desktop$ chmod 600 private 
	vladutmargineanu@vladutmargineanu15:~/Desktop$ ssh -i ./private secure@isc2021.root.sx
	You did it! Congratulations!

	Your flag is:

	SpeishFlag{7mFY0BwYnd84s4M8LDZZVHqQ5zC8r5QP}
  
  Task 02
  In rezolvarea acestui task, am rulat script-ul connect.sh,
  dupa care am investigat pagina web. Am gasit o linie comentata
  http://localhost:8080/auth/register_real_one

  Mi-am facut cont si am investigat pagina pe ruta:
  http://localhost:8080/inside


  Hey, you got in! Here's your flag: SpeishFlag{lrp2TCLFyxGtBFT21SdyTxdG6BHEmOFx}        
  