# Bežične senzorske mreže - Lab 9

### FESB, smjer 110/111/112/114/120, akademska godina 2016/2017

U sklopu današnje vježbe student će vizualizirati senzorske podatke sa Arduina. U vježbi ćemo koristiti server aplikaciju pisanu u *Node.js*-u.

## Uputstva za pokretanje Server aplikacije

Vaš Arduino, odnosno senzore temperature/blage i osvjetljenja povežite prema uputama koje su dane u Vježbi 3. Kod za Arduino je dan u direktoriju vježba. Pokrenite serversku aplikaciju ```server.js``` (kod također u dijrektoriju vježba) tako da u komandnom prozoru izvršite sljedeću naredbu:
```
node server.js COMX
```
gdje X označava COM port na koji se spojen Arduino.

Nakon toga testirajte svoju aplikaciju tako da u web preglednik upišete ```localhost:3000```
