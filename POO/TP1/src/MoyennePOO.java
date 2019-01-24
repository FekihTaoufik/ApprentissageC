class MoyennePOO{
// Ajouter un coefficient pour tenir compte des absences des étudiants. Il y a 12 séances, chaque présence compte 0.1. Avec 12 présences on obtient un coefficient de 1.2 qui sera multiplié à la moyenne calculée pour obtenir la note finale de cette matière.
// Que faire si on décide de mettre 3 notes écrites au lieu de 2 ?
// Que faire si on veut ajouter des coefficients ?
// Que faire si on veut garder la meilleure des trois notes ?
// Que faire si on veut considérer d'autres matières avec des règles différentes ?
int notes = 0 ;  

int nombreDeNotes = 0 ;

int nombreDeSeances = 12;

double coefPresence = 0.1;

int nombreDeSeancesPresent = 0;

public void definirPresence (int nombreDeSeances) {  
    nombreDeSeancesPresent=nombreDeSeances;
}  
void ajouteNote (int note,double coef) {  
  notes += note*coef;  
  nombreDeNotes += 1;  
}  
double calculNoteFinale() {  
    return coefPresence*nombreDeSeancesPresent*((double)notes) / nombreDeNotes ;  
  }  
}