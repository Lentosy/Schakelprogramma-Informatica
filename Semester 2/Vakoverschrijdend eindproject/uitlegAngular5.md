# ANGULAR 5
## Algemene uitleg

Angular5 maakt gebruik van componenten dit zijn typescript files die zo zijn opgebouwd dat met html code, typescript code (iets uitgebreidere javascript) en css files hierin verweven zit. De layout van een pagina zit zo. Je hebt een hoofd component (app.component.ts) hierin stop je jouw onderliggende componenten. Je kan loops maken van componenten met elk andere data zodat je een oplijsting van objecten tevoorschijn kan laten toveren. Angular werkt ook real time, dus je pagina moet niet per click geladen worden. 

De nieuwe versie van angular zorgt voor een zeer duidelijke scheiding tussen de frontend n de backend. Dit zorgt dat de backend is afgeschermd voor al de zwiebers die willen stelen. JWZ.

Dus de backend is eigenlijk gewoon een API service die men van de frontend gaat aanspreken om zo crud te kunnen toepassen op de databank.

Voor de algmene architectuur kan je dit raadplegen. https://angular.io/guide/architecture

## Runnen van applicatie's

Backend: `npm start` (dit gaat command `ng build && nodemon www.js` uitvoeren, dit gaat zien of de frontend goed build vooraleer de backend wordt opgestart)
Voor de backend `node www.js` kunnen we eventueel `nodemon www.js` van maken zodat deze ook watch doet op backend zoals `ng serve`.

Frontend:  `ng serve`

## Backend (nodeJs)

backend dient enkel voor data, communicatie met frontend gebeurt via de api.
En de api wordt opgezet in de backend, deze haalt dan de data uit de databank enz.

Hier ga ik niet meer te veel over zeggen blijft hetzelfde als voorzien bij vragen stel het aan je teammates die er weet van hebben of raadpleeg google.

De backend draait op localhost:3000

Voor het testen van de API's van de backend kan je gebruik maken van postman! (je kan hiet get,post,put enz loslaten op je server)

## Frontend (Angular5)

De frontend draait op localhost:4200

### Componenten

Voor meer uitleg over de verschillende componenten zie https://angular.io/guide/architecture-components.

### Modules

Angular is modulair en kan vele modules aanspreken. Modules kan je dus importeren en gebruiken, dit kan heel handig zijn voor vele dingen. Dit zijn eigenlijk libraries die men kan gebruiken. Dit kunnen ook navigatie bars zijn of componenten die andere mensen al gemaakt hebben. Voor meer uitleg zie https://angular.io/guide/architecture-modules.

### Routing & Navigation

In angular heb je een router deze kan je aanspreken om van de ene pagina naar de andere te gaan. Voor meer uitleg zie https://angular.io/guide/router.

### API

Dus in je componenten kan je een api gaan aanspreken die dan de data uit de databank
haalt deze gaat opslaan in een object en dan kan je hiermee aan de slag. De data uit de
databank halen gebeurt via services. 

Je gaat services aanmaken via `ng g service naamService`. In je services ga je de databank aanspreken, in je component ga je je service aanspreken, die dan de data voor je ophaalt. Voor meer info rond services https://angular.io/guide/architecture-services en voor een tutorial met voorbeelde zie https://angular.io/tutorial/toh-pt4. 

In de services spreek je de api vanuit angular aan met HttpClient, dit is een ingebouwde module van angular, voor hoe te gebruiken zie https://angular.io/guide/http.

### Data binding

Dit wil zeggen het koppelen van de data in je component aan/in je html pagina.
Je kan hele objecten gaan uitlezen en inlezen in je html pagina en je kan ook functies aanspreken door het drukken op een knop enz... Voor meer informatie zie https://angular.io/guide/architecture-components#data-binding.

Pipes zijn een manier om je data in andere vorm dan je deze ophaalt te laten zien in je front end. Voor meer informatie zie https://angular.io/guide/architecture-components#pipes.

### Bootstrap
Bootstrap dat hierbij hoort is ngx-bootstrap. Voor meer info zie https://valor-software.com/ngx-bootstrap/#/getting-started. Dit is een module die men kan gebruiken.

### To Know

#### aanmaken van componenten
Het aanmaken van services, pipes, components enz kan je via je terminal (cmd). Zie link voor hoe dit moet gebeuren, https://github.com/angular/angular-cli.
Als je dit niet aanmaakt met via cmd dan gaat de config hiervan hiervan niet automatisch gebeuren.
Ik heb de oude code die we moeten omzetten ergens in het project gestoken. Bij vragen just ask!

#### naming convention
De naam conventie van ANGULAR5 is lowercase met een streepje tussen de woorden:
- group-view  
- group-detail-view  
- class-view  
- cass-edit  
- enz...

### Extra over project omzetting
- Heb wat er gedaan moet worden met todo aangeduid. de TODO's kan je bekijken onderaan links in Webstorm.
- Shared map is voor bepaalde componenten die men meer moet gaan gebruiken in andere componenten zoals header en footer.
