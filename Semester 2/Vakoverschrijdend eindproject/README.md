# Annotatietool
## Context
Binnen de UGent loopt een onderwijsinnovatie project waarin video annotatie wordt ingezet om communicatievaardigheden, die centraal staan in diverse opleidingsonderdelen in verschillende opleidingen, te trainen en op een authentieke manier te toetsen. Hiervoor wordt ingezet op peer-assessment, waarbij studenten elkaar feedback geven op gefilmde situaties waarin de student communicatievaardigheden toepast. Lees het [verslag](https://github.ugent.be/bp-vop-2018/annotatietool-01/blob/master/verslag/document.pdf) voor een gedetailleerde beschrijving van het project.

## Structuur repository
Al de broncode bevindt zich in de [project](https://github.ugent.be/bp-vop-2018/annotatietool-01/tree/master/project) folder. Deze folder is als volgt opgedeeld:
* [src](https://github.ugent.be/bp-vop-2018/annotatietool-01/tree/master/project/src) : Deze folder bevat alle code in verband met de frontend
* [backend](https://github.ugent.be/bp-vop-2018/annotatietool-01/tree/master/project/backend) : Deze folder bevat alle code met betrekking tot de backend
* [spec](https://github.ugent.be/bp-vop-2018/annotatietool-01/tree/master/project/spec) : Deze folder bevat integratietesten voor de webapplicatie
* [java](https://github.ugent.be/bp-vop-2018/annotatietool-01/tree/master/project/java) : Deze folder bevat het Java-gedeelte van het project. De unit testen zitten ook in deze folder.

## Installatie repository
### Hardware en Software
De applicatie kan op volgende besturingssystemen draaien:
* Linux (32 en 64 bit)
* macOS (64 bit)
* Windows 7 of hoger (32 en 64 bit)

Verder moeten ook nog volgende softwarepakketten geïnstalleerd worden.
* [Node.js](https://nodejs.org/en) (minimum v8.9.4): Klik op de knop met onderschrift 'Recommended For Most Users' om de installatie van Node.js te beginnen. Controleer of dit juist geïnstalleerd is door het commando `node -v` uit te voeren.

* [MongoDB](https://www.mongodb.com/download-center) (minimum v2.6.10):
Klik op `Community Server` en vervolgens het pakket dat bij het besturingssysteem van het toestel past. Controleer of dit juist geïnstalleerd is door het commando `mongo  --version` uit te voeren in een terminal of console.

* [Java 8](https://www.java.com/en/download/win10.jsp) (minimum JDK 8u171):  : Klik op de download knop en volg de installatieprocedure. Controleer of dit juist geînstalleerd is door het commando `java --version` uit te voeren in een terminal of console.

* [ffmpeg](https://ffmpeg.zeranoe.com/builds/): Dit bevat enkel builds voor Windows en macOS. Een .bz2 bestand kan teruggevonden worden op https://ffmpeg.org/download.html. Om te controleren of dit programma correct is geïnstalleerd kan het commando `ffmpeg` uitgevoerd worden in de console of terminal.


### Downloaden repository
Nadat al de benodigde software geïnstalleerd is moet de broncode op het toestel geplaatst worden. Dit kan op twee manieren:

* Indien \textit{git} geïnstalleerd is op het toestel kan het commando 
    
    ```git clone https://github.ugent.be/bp-vop-2018/annotatietool-01.git```
    
    gebruikt worden. Dit zal een folder aanmaken met de naam `annotatietool-01` waarin de broncode terug te vinden is.
    
* Indien het toestel geen git  heeft, kan de repository nog altijd manueel gedownload worden via https://github.ugent.be/bp-vop-2018/annotatietool-01. Klik op `Clone or download` en dan `Download ZIP`. Dit zal een ZIP bestand downloaden waarin de broncode terug te vinden is. Plaats de inhoud van het ZIP bestand (folder genaamd `annotatietool-01`) op het toestel.

## Runnen applicatie
### Inloggen
Inloggen is mogelijk door gebruik te maken van verschillende accounts zoals beschreven in de seed.js in het userData veld. Deze informatie moet eenmalig ingevuld worden en blijft geldig tot de gebruiker uitlogt. Een overzicht van de mogelijke logins:
#### Docenten
* Name: docent Password: test
* Name: rubenjanssens Password: test

#### Studenten
* Name: student Password: test
* Name: nickvanhurck Password: test
* Name: emielvandenbussche Password: test
* Name: timothythiecke Password: test
* Name: arnoutlenaerts Password: test 

De groep die bestaat bevat de gebruikers bertdesaffel en nickvanhurck als studenten en de gebruiker docent als docent.

Er bestaan twee mogelijkheden om de applicatie te draaien op een lokaal toestel die hieronder staan beschreven.
### Docker
Hiervoor moet Docker geïnstalleerd worden op het toestel. Navigeer naar https://store.docker.com/search?type=edition&offering=community om naar een lijst te gaan van de Community Edition van Docker per besturingssysteem. Kies de versie dat past bij het besturingssysteem van het toestel en voer de installatieprocedure uit.

Wanneer Docker geïnstalleerd is op het toestel kan het volgende commando uitgevoerd worden in de root directory van het project (annotatietool-01).

```./buildandrun.sh```

De webapplicatie kan vanaf nu bediend worden op het lokaal adres `localhost:9010` via een webbrowser.

### Zonder Docker
Indien geen gebruik gemaakt wordt van Docker moet de technologiestack 
zelfstandig opgesteld worden. Voer volgende stappen uit:

* Navigeer naar de `project` folder (annotatie-tool-01/project).
* Open een terminal of de console (afhankelijk van het besturingssysteem) 
	      en voer het commando `npm install` uit. Dit zal alle nodige 
	      afhankelijkheden van het project laden.
* Wanneer alle afhankelijkheden geladen zijn, kan het commando `npm 
	start` uitgevoerd worden. Dit zal de backend opstarten met als onderliggende 
	commando `ng build \&\& nodemon www.js`. Het defaultadres van de backend 
	is `localhost:3000`. 

* Open een nieuwe terminal of console en voer het commando `ng 
	serve` uit. Dit zal de webapplicatie lokaal starten.

	
* Navigeer in een webbrowser naar `localhost:4200` om de 
	      applicatie te bedienen.


## Testen
Er zijn twee luiken van testen. Het eerste luik test de operaties die 
worden gebruikt door de webapplicatie. Het tweede luik zijn de JUnit testen voor 
de mp4 converter.
    
### Testen van de webapplicatie
De benodigde software is voor dit luik al geïnstalleerd indien de vorige secties correct uitgevoerd zijn. Enkel de backend moet draaien om deze testen uit te voeren. Open een console of terminal en start de applicatie met `npm start`. Open een nieuwe terminal of console,  navigeer naar `annotatietool-01/project` en voer het  commando `npm test` uit om de testen uit te voeren. Volgende uitvoer komt tevoorschijn:
![web_tests](https://i.imgur.com/0ORAYdU.png)
### Testen van de mp4 converter
Aangezien de mp4 converter geschreven is in Java is het logisch dat de testsuites geschreven zijn met behulp van JUnit. Indien de repository correct is geïnstalleerd, kunnen de JUnit testen uitgevoerd worden. Navigeer vanuit de root folder naar `java/MP4Converter/` en voer het volgende commando uit:
```java -jar RunTests.jar```.
Volgende uitvoer verschijnt indien de testen correct uitgevoerd zijn
![java_tests](https://github.ugent.be/bp-vop-2018/annotatietool-01/blob/verslag/verslag/img/java_tests.png)

